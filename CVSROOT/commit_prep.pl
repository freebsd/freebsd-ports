#!/usr/bin/perl -w
#
# $FreeBSD$
#
#
# Perl filter to handle pre-commit checking of files.  This program
# records the last directory where commits will be taking place for
# use by the log_accumulate script.  For new file, it forcing the
# existence of a RCS "Id" keyword in the first ten lines of the file.
# For existing files, it checks version number in the "Id" line to
# prevent losing changes because an old version of a file was copied
# into the direcory.
#
# Possible future enhancements:
#
#
#    Check for cruft left by unresolved conflicts.  Search for
#    "^<<<<<<<$", "^-------$", and "^>>>>>>>$".
#
#    Look for a copyright and automagically update it to the
#    current year.
#
# Contributed by David Hampton <hampton@cisco.com>
#

require 5.003;	# to be sure.  log_accum needs perl5

use strict;
use lib $ENV{CVSROOT};
use CVSROOT::cfg;
my $CVSROOT = $ENV{'CVSROOT'} || die "Can't determine \$CVSROOT!";


############################################################
#
# Constants
#
############################################################
my $ENTRIES       = "CVS/Entries";


# The "Id" header to check for.
my $HEADER	= $cfg::IDHEADER;

############################################################
#
# Error messages
#
############################################################
my $NoId = "
%s - Needs to contain a line with the keyword \"\$$HEADER\$\".\n";

# Protect string from substitution by RCS.
my $NoName = "
%s - The ID line should contain only \$$HEADER\$ for a newly created file.\n";

#$DelPath = "
#%s - The old path and version has been deleted from \$$HEADER\$.\n";

my $BadId = "
%s - The \$$HEADER\$ is mangled.\n";

my $BadName = "
%s - The pathname '%s'
    in the \$$HEADER\$ line does not match the actual filename.\n";

my $BadVersion = "
%s - GRRR!!  You spammed your copy of the file
    which was based upon version %s, with a different version based
    upon %s.  Please move your '%s' out of the way,
    perform an update to get the current version, and then
    CAREFULLY merge your changes into that file.\n";

############################################################
#
# Subroutines
#
############################################################

# Write a single line to a file.
sub write_line {
	my $filename = shift;	# File to write to.
	my $line = shift;	# Line to write to the file.

	open FILE, ">$filename" or die "Cannot open $filename, stopped\n";
	print FILE "$line\n";
	close FILE;
}

# Check to see whether a file is mentioned in the exclusion file.
sub exclude_file {
	my $filename = shift;
	my $directory = shift;

	my $path = "$directory/$filename";
	if (open(EX, "< $cfg::EXCLUDE_FILE")) {
		while (<EX>) {
			chomp;
			my $ex_entry = $_;

			# Skip comments and blank lines.
			next if $ex_entry =~ /^#/;
			next if $ex_entry =~ /^$/;

			if ($path =~ /$ex_entry/) {
				close(EX);
				return(1);
			}
		}
		close(EX);
	}

	# File shouldn't be excluded.
	return(0);
}

sub check_version {
	my $filename = shift;
	my $directory = shift;
	my $hastag = shift;
	my $lastversion = shift;

	my $found_rcsid;	# True if our rcsid was found in the file.
	my $rcsid;		# The rcsid that was in the file.
	my $rcsid_info;		# The expanded values of the rcsid.
	my $rname;		# The file pathname, parsed from the rcsid.
	my $version;		# The file version, parsed from the rcsid.

	# not present - either removed or let cvs deal with it.
	return 0 unless -f $filename;

	# Search the file for our rcsid.
	# NOTE: We stop after finding the first potential match.
	open FILE, $filename or die "Cannot open $filename, stopped\n";
	$found_rcsid = 0;
	while (<FILE>) {
		next unless /^.*(\$$HEADER.*)/;
		$rcsid = $1;
		$found_rcsid = 1;
		last;
	}
	close FILE;

	# The file should have had an rcsid in it!
	unless ($found_rcsid) {
		printf($NoId, $filename);
		return(1);
	}

	# Is the rcsid corrupt?
	unless ($rcsid =~ /\$$HEADER(: ([^\$]* )?)?\$/) {
		printf($BadId, $filename);
		return(1);
	}
	$rcsid_info = $2 || "";
	($rname, $version) = split /\s/, $rcsid_info;

	# Ignore version mismatches (MFC spamming etc) on branches.
	if ($hastag) {
		return (0);
	}

	# A new file should have an unexpanded rcsid.
	if ($lastversion eq '0') {
		unless ($rcsid_info eq "") {
			printf($NoName, $filename);
			return(1);
		}
		return(0);
	}

	# It's ok for the rcsid to be not expanded.
	if ($rcsid_info eq "") {
		return (0);
#		if ($directory =~ /^ports\//) {
#			return (0);	# ok for ports
#		}
#		# Don't know whether to allow or trap this.  It means
#		# one could bypass the version spam checks by simply
#		# using a bare tag.
#		printf($DelPath, $filename);
#		return(1);
	}

	# Check that the file name in the rcsid matches reality.
	if ($rname ne "$directory/$filename,v") {
		# If ports and the pathname is just the basename
		# (eg: somebody sent in a port with $Id$ and the
		# committer changed Id -> $HEADER and the version
		# numbers otherwise match.
		if (!($directory =~ /^ports\// && $rname eq "$filename,v")) {
			printf($BadName, "$directory/$filename,v", $rname);
			return(1);
		}
	}

	# Check that the version in the rcsid matches reality.
	if ($lastversion ne $version) {
		printf($BadVersion, $filename, $lastversion,
		    $version, $filename);
		return(1);
	}
	return(0);
}


# Do file fixups, i.e. replacing $ Id: .* $ with $ Id $.
sub fix_up_file {
	my $filename = shift;

	# not present - either removed or let cvs deal with it.
	return 0 unless -f $filename;

	open F, "< $filename" or die "Can't open $filename!\n";
	my @file = <F>;
	close F;

	open F, "> $filename.tmp" or die "Can't create $filename tmpfile!\n";
	while (@file) {
		my $line = shift @file;

		$line =~ s/\$$HEADER:.*?\$/\$$HEADER\$/g;
		print F $line or die "Out of disk space?\n";
	}
	close F;

	# overwrite the original file......
	system($cfg::PROG_MV, "$filename.tmp", $filename);
	die "Can't recreate $filename!\n" if $? >> 8;
}

#############################################################
#
# Main Body
#
############################################################

#print("ARGV - ", join(":", @ARGV), "\n");
#print("id   - ", $cfg::PID, "\n");

#
# Suck in the Entries file
#
my %cvsversion;
my %cvstag;
open ENTRIES, $ENTRIES or die "Cannot open $ENTRIES.\n";
while (<ENTRIES>) {
	chomp;
	next if /^D/;

	my ($filename, $ver, $stamp, $opt, $tag) = split '/', substr($_, 1);
	$cvsversion{$filename} = $ver;
	$cvstag{$filename} = $tag;
	$stamp = $opt;	#silence -w
}
close ENTRIES;

my $directory = $ARGV[0];
shift @ARGV;

$directory =~ s,^$CVSROOT[/]+,,;

my $check_id = 0;
if ($directory =~ /^src\/contrib/) {
	$check_id = 3;
}
if ($directory =~ /^src\/crypto/) {
	$check_id = 3;
}
#
# Now check each file name passed in, except those excluded.
#
if ($cfg::CHECK_HEADERS) {
	my $failed = 0;
	foreach my $arg (@ARGV) {
		my $hastag = ($cvstag{$arg} ne '');
		next if ($check_id == 3 && $hastag);

		# Ignore the file if it's in the exclude list.
		next if exclude_file($arg, $directory);

		# Check to make sure that the file hasn't had
		# it's revision string changed.
		$failed += &check_version($arg, $directory, $hastag,
		    $cvsversion{$arg});

		# Unexpand the rcsid if required.
		fix_up_file($arg) if $cfg::UNEXPAND_RCSID and !$failed;
	}
	if ($failed and not $cfg::WARN_HEADERS) {
		print "\n";
		unlink($cfg::LAST_FILE);
		exit(1);
	}
}

#
# Record this directory as the last one checked.  This will be used
# by the log_accumulate script to determine when it is processing
# the final directory of a multi-directory commit.
#
&write_line($cfg::LAST_FILE, $directory);

exit(0);
