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

############################################################
#
# Configurable options
#
############################################################
#
# Check each file (except dot files) for our RCS header keyword.
# (defined in the constants section.)
#
my $check_id = 0;

############################################################
#
# Constants
#
############################################################
my $ENTRIES       = "CVS/Entries";


# The "Id" header to check for.
my $HEADER	= $cfg::IDHEADER;

my $cvsroot= $ENV{'CVSROOT'} || "/home/ncvs";

############################################################
#
# Error messages
#
############################################################
my $NoId = "
%s - Does not contain a line with the keyword \"\$$HEADER:\".\n";

# Protect string from substitution by RCS.
my $NoName = "
%s - The ID line should contain only \$$HEADER\$ for a newly created file.\n";

#$DelPath = "
#%s - The old path and version has been deleted from \$$HEADER\$.\n";

my $BadId = "%s - The \$$HEADER\$ is mangled.\n";

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

sub check_version {
	my $filename = shift;
	my $directory = shift;
	my $hastag = shift;
	my $lastversion = shift;

	my $bareid;
	my $exclude;
	my $id;
	my $path;
	my $rname;
	my $version;

	# not present - either removed or let cvs deal with it.
	return 0 unless -f $filename;

	open FILE, $filename or die "Cannot open $filename, stopped\n";
	# requiring the header within the first 'n' lines isn't useful.
	my $pos;
	my $line;
	while (1) {
		$pos = -1;
		last if eof(FILE);
		$line = <FILE>;
		$pos = index($line, "\$$HEADER");
		last if ($pos >= 0);
	}

	if ($pos == -1) {
		$exclude = $cvsroot . "/CVSROOT/exclude";
		$path = $directory . "/" . $filename;
		open(EX, "<$exclude") || die("cannot open $exclude: $!");
		while (<EX>) {
			chomp;
			my $ex_entry = $_;

			next if $ex_entry =~ /^#/;

			if ($path =~ /$ex_entry/) {
				close(EX);
				return(0);
			}
		}
		close(EX);
	}
	if ($pos == -1) {
		printf($NoId, $filename);
		return(1);
	}
	$bareid = (index($line, "\$$HEADER: \$") >= 0 ||
	   index($line, "\$$HEADER\$") >= 0);
	if (!$bareid && $line !~ /\$$HEADER: .* \$/) {
		printf($BadId, $filename);
		return(1);
	}
	# Ignore version mismatches (MFC spamming etc) on branches.
	if ($hastag) {
		return (0);
	}
	($id, $rname, $version) = split(' ', substr($line, $pos));
	if ($lastversion eq '0') {
		if (!$bareid) {
			printf($NoName, $filename);
			return(1);
		}
		return(0);
	}
	if ($bareid) {
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
	if ($lastversion ne $version) {
		printf($BadVersion, $filename, $lastversion,
		    $version, $filename);
		return(1);
	}
	return(0);
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

$directory =~ s,^$cvsroot[/]+,,;

if ($directory =~ /^src/) {
	$check_id = 1;
}
if ($directory =~ /^ports/) {
	$check_id = 2;
}
if ($directory =~ /^src\/contrib/) {
	$check_id = 3;
}
if ($directory =~ /^src\/crypto/) {
	$check_id = 3;
}
if ($directory =~ /^src\/release/) {
	$check_id = 0;
}
if ($directory =~ /^src\/etc/) {
	$check_id = 0;
}
#
# Now check each file name passed in, except for dot files.  Dot files
# are considered to be administrative files by this script.
#
if ($check_id != 0) {
	my $failed = 0;
	foreach my $arg (@ARGV) {
		my $hastag = ($cvstag{$arg} ne '');
		next if (index($arg, ".") == 0);
		next if ($check_id == 2 && $arg ne "Makefile");
		next if ($check_id == 3 && $hastag);
		$failed += &check_version($arg, $directory, $hastag,
		    $cvsversion{$arg});
	}
	if ($failed) {
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
