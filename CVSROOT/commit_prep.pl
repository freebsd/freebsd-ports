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

############################################################
#
# Configurable options
#
############################################################
#
# Check each file (except dot files) for our RCS header keyword.
# (defined in the constants section.)
#
$check_id = 0;

#
# Record the directory for later use by the log_accumulate stript.
#
$record_directory = 1;

############################################################
#
# Constants
#
############################################################
$LAST_FILE     = "/tmp/#cvs.files.lastdir";
$ENTRIES       = "CVS/Entries";
$HEADER        = 'FreeBSD';	# Our RCS header is '$ FreeBSD $', 
				# (without the spaces.)

$NoId = "
%s - Does not contain a line with the keyword \"\$$HEADER:\".\n";

# Protect string from substitution by RCS.
$NoName = "
%s - The ID line should contain only \$$HEADER\$ for a newly created file.\n";

#$DelPath = "
#%s - The old path and version has been deleted from \$$HEADER\$.\n";

$BadId = "%s - The \$$HEADER\$ is mangled.\n";

$BadName = "
%s - The pathname '%s'
    in the \$$HEADER\$ line does not match the actual filename.\n";

$BadVersion = "
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

sub write_line {
    local($filename, $line) = @_;
    open(FILE, ">$filename") || die("Cannot open $filename, stopped");
    print(FILE $line, "\n");
    close(FILE);
}

sub check_version {
    local($id, $rname, $version, $bareid);
    local($filename, $directory, $hastag, $cvsversion) = @_;

    if (! -f $filename) {
	return(0);	# not present - either removed or let cvs deal with it.
    }
    open(FILE, $filename) || die("Cannot open $filename, stopped");
    # requiring the header within the first 'n' lines isn't useful.
    while (1) {
	$pos = -1;
	last if eof(FILE);
	$line = <FILE>;
	$pos = index($line, "\$$HEADER");
	last if ($pos >= 0);
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
    if ($cvsversion{$filename} == 0) {
	if (!$bareid) {
	    printf($NoName, $filename);
	    return(1);
	}
	return(0);
    }
    if ($bareid) {
	return (0);
#	if ($directory =~ /^ports\//) {
#	    return (0);	# ok for ports
#	}
#	# Don't know whether to allow or trap this.  It means one could
#	# bypass the version spam checks by simply using a bare tag.
#	printf($DelPath, $filename);
#	return(1);
    }
    if ($rname ne "$directory/$filename,v") {
	# If ports and the pathname is just the basename (eg: somebody sent
	# in a port with $Id$ and the committer changed Id -> $HEADER and
	# the version numbers otherwise match.
	if (!($directory =~ /^ports\// && $rname eq "$filename,v")) {
	    printf($BadName, "$directory/$filename,v", $rname);
	    return(1);
	}
    }
    if ($cvsversion{$filename} ne $version) {
	printf($BadVersion, $filename, $cvsversion{$filename},
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

$id = getpgrp();
#print("ARGV - ", join(":", @ARGV), "\n");
#print("id   - ", id, "\n");

#
# Suck in the Entries file
#
open(ENTRIES, $ENTRIES) || die("Cannot open $ENTRIES.\n");
while (<ENTRIES>) {
    chop;
    next if (/^D/);
    local($filename, $version, $stamp, $opt, $tag) = split('/', substr($_, 1));
    $cvsversion{$filename} = $version;
    $cvstag{$filename} = $tag;
    $stamp = $opt;	#silence -w
}
close(ENTRIES);

$directory = $ARGV[0];
shift @ARGV;

$cvsroot=$ENV{'CVSROOT'} || "/home/ncvs";
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
#$login = $ENV{'USER'} || getlogin || (getpwuid($<))[0] || sprintf("uid#%d",$<);
#if ($login eq "peter") {
#	print "directory:$directory, check_id:$check_id\n";
#} else {
#	$check_id = 0;
#}
if ($check_id != 0 && $ENV{'CVSFUBAR'}) {
	$check_id = 0;
	print "CVS VERSION CHECK BYPASSED!\n";
	system("ps -xww | mail -s 'version check override used' cvs");
}
#
# Now check each file name passed in, except for dot files.  Dot files
# are considered to be administrative files by this script.
#
if ($check_id != 0) {
    $failed = 0;
    foreach $arg (@ARGV) {
	local($hastag) = ($cvstag{$arg} ne '');
	next if (index($arg, ".") == 0);
	next if ($check_id == 2 && $arg ne "Makefile");
	next if ($check_id == 3 && $hastag);
	$failed += &check_version($arg, $directory, $hastag, $cvsversion);
    }
    if ($failed) {
	print "\n";
	unlink("$LAST_FILE.$id");
	exit(1);
    }
}

#
# Record this directory as the last one checked.  This will be used
# by the log_accumulate script to determine when it is processing
# the final directory of a multi-directory commit.
#
if ($record_directory != 0) {
    &write_line("$LAST_FILE.$id", $directory);
}
exit(0);
