#!/usr/local/bin/perl -w
#
# $FreeBSD$
#
# Perl filter to handle the log messages from the checkin of files in
# a directory.  This script will group the lists of files by log
# message, and mail a single consolidated log message at the end of
# the commit.
#
# This file assumes a pre-commit checking program that leaves the
# names of the first and last commit directories in a temporary file.
#
# Contributed by David Hampton <hampton@cisco.com>
#

############################################################
#
# Configurable options
#
############################################################
#
# Do cisco Systems, Inc. specific nonsense.
#
$cisco_systems = 0;

############################################################
#
# Constants
#
############################################################
$STATE_NONE    = 0;
$STATE_CHANGED = 1;
$STATE_ADDED   = 2;
$STATE_REMOVED = 3;
$STATE_LOG     = 4;

$LAST_FILE     = "/tmp/#cvs.lastdir";
$CHANGED_FILE  = "/tmp/#cvs.files.changed";
$ADDED_FILE    = "/tmp/#cvs.files.added";
$REMOVED_FILE  = "/tmp/#cvs.files.removed";
$LOG_FILE      = "/tmp/#cvs.files.log";
$FILE_PREFIX   = "#cvs.files";

$AVAIL_FILE    = "$ENV{'CVSROOT'}/CVSROOT/avail";
$MAIL_FILE     = "/tmp/#cvs.mail";
$VERSION_FILE  = "version";
$TRUNKREV_FILE = "TrunkRev";
#$CHANGES_FILE  = "Changes";
#$CHANGES_TEMP  = "Changes.tmp";

############################################################
#
# Subroutines
#
############################################################

sub format_names {
    local($dir, @files) = @_;
    local(@lines);
    $lines[0] = sprintf(" %-08s", $dir);
    foreach $file (@files) {
	if (length($lines[$#lines]) + length($file) > 60) {
	    $lines[++$#lines] = sprintf(" %8s", " ");
	}
	$lines[$#lines] .= " ".$file;
    }
    @lines;
}

sub cleanup_tmpfiles {
    local($all) = @_;
    local($wd, @files);

    $wd = `pwd`;
    chdir("/tmp");
    opendir(DIR, ".");
    if ($all == 1) {
	push(@files, grep(/$id$/, readdir(DIR)));
	push(@files, "$MAIL_FILE.$id.db") if (-e "$MAIL_FILE.$id.db");
    } else {
	push(@files, grep(/^$FILE_PREFIX.*$id$/, readdir(DIR)));
    }
    closedir(DIR);
    foreach (@files) {
	unlink $_;
    }
    chdir($wd);
}

sub write_logfile {
    local($filename, @lines) = @_;
    open(FILE, ">$filename") || die ("Cannot open log file $filename.\n");
    print(FILE join("\n", @lines), "\n");
    close(FILE);
}

sub append_to_file {
    local($filename, $dir, @files) = @_;
    if (@files) {
	local(@lines) = &format_names($dir, @files);
	open(FILE, ">>$filename") || die ("Cannot open file $filename.\n");
	print(FILE join("\n", @lines), "\n");
	close(FILE);
    }
}

sub write_line {
    local($filename, $line) = @_;
    open(FILE, ">$filename") || die("Cannot open file $filename.\n");
    print(FILE $line, "\n");
    close(FILE);
}

sub read_line {
    local($line);
    local($filename) = @_;
    open(FILE, "<$filename") || die("Cannot open file $filename.\n");
    $line = <FILE>;
    close(FILE);
    chop($line);
    $line;
}

sub read_file {
    local(@text);
    local($filename, $leader) = @_;
    open(FILE, "<$filename") || return ();
    while (<FILE>) {
	chop;
	push(@text, sprintf("  %-10s  %s", $leader, $_));
	$leader = "";
    }
    close(FILE);
    @text;
}

sub read_logfile {
    local(@text);
    local($filename, $leader) = @_;
    open(FILE, "<$filename") || die ("Cannot open log file $filename.\n");
    while (<FILE>) {
	chop;
	push(@text, $leader.$_);
    }
    close(FILE);
    @text;
}

sub bump_version {
    local($trunkrev, $editnum, $version);

    $trunkrev = &read_line("$ENV{'CVSROOT'}/$repository/$TRUNKREV_FILE");
    $editnum  = &read_line("$ENV{'CVSROOT'}/$repository/$VERSION_FILE");
    &write_line("$ENV{'CVSROOT'}/$repository/$VERSION_FILE", $editnum+1);
    $version = $trunkrev . "(" . $editnum . ")";
}

sub build_header {
    local($version) = @_;
    local($header);
    local($sec,$min,$hour,$mday,$mon,$year) = localtime(time);
    $version = '';
    $header = sprintf("%-8s  %s  %02d/%02d/%02d %02d:%02d:%02d",
		       $login, $version, $year%100, $mon+1, $mday,
		       $hour, $min, $sec);
}

# !!! Mailing-list and history file mappings here !!!
sub mlist_map {
    local($dir) = @_;
   
    return 'cvs-CVSROOT'      if($dir =~ /^CVSROOT/);
    return 'cvs-ports'        if($dir =~ /^ports/);

    return 'cvs-other'        unless($dir =~ /^src/);
    $dir =~ s,^src/,,;

    return 'cvs-bin'          if($dir =~ /^bin/);
    return 'cvs-etc'          if($dir =~ /^etc/);
    return 'cvs-games'        if($dir =~ /^games/);
    return 'cvs-gnu'          if($dir =~ /^gnu/);
    return 'cvs-include'      if($dir =~ /^include/);
    return 'cvs-kerberosIV'   if($dir =~ /^kerberosIV/);
    return 'cvs-lib'          if($dir =~ /^lib\//);
    return 'cvs-libexec'      if($dir =~ /^libexec/);
    return 'cvs-sbin'         if($dir =~ /^sbin/);
    return 'cvs-share'        if($dir =~ /^share/);
    return 'cvs-usrbin'       if($dir =~ /^usr\.bin/);
    return 'cvs-usrsbin'      if($dir =~ /^usr\.sbin/);

    return 'cvs-user'         unless($dir =~ /^sys/);
    $dir =~ s,^sys/,,;

# Note, this does not really work, it ends up dumping it in the LAST tree
# the commit was done in, so for now, just dump it all in cvs-sys.
# XXX
    return 'cvs-sys';

    return 'cvs-sys_ddb'      if($dir =~ /^ddb/);
    return 'cvs-sys_fs'       if($dir =~ /^(fs)|(isofs)|(miscfs)|(nfs)|(ufs)/);
    return 'cvs-sys_i386'     if($dir =~ /^i386/);
    return 'cvs-sys_net'      if($dir =~ /^net/);
    return 'cvs-sys_kern'     if($dir =~ /^kern/);
    return 'cvs-sys_libkern'  if($dir =~ /^libkern/);
    return 'cvs-sys_scsi'     if($dir =~ /^scsi/);
    return 'cvs-sys_sys'      if($dir =~ /^sys/);
    return 'cvs-sys_vm'       if($dir =~ /^vm/);

    return 'cvs-sys';
}    

sub do_changes_file {
    local($changes,$category);
    local(@text) = @_;

    $category = $mlist;
    $category =~ s/^cvs-//;
    
    $changes = "$ENV{'CVSROOT'}/CVSROOT/commitlogs/$category";

    open(CHANGES, ">>$changes") || die("Cannot open $changes.\n");
    print(CHANGES join("\n", @text), "\n\n");
    close(CHANGES);
}

sub do_avail_file {
    local($where) = @_;
    local($users,$repo,$who);

    dbmopen(MAILFILE, "$MAIL_FILE.$id", 0666);
    open(AVAIL, "<$AVAIL_FILE") || die("Cannot open $AVAIL_FILE.\n");
    while(<AVAIL>) {
	if(/^avail\|([^|]*)\|(.*)$/) {
	    $users = $1;
	    $repo = $2;
	    if(($where eq $repo) || ($where =~ /^$repo\//)) {
		foreach $who (split(/,/, $users)) {
		    $MAILFILE{$who} = 1;
		}
	    }
	} elsif(/^avail\|([^|]*)$/) {
	    foreach $who (split(/,/, $1)) {
		$MAILFILE{$who} = 1;
	    }
	}
    }
    close(AVAIL);
    dbmclose(MAILFILE);
}


sub mail_notification {
    local(@text) = @_;
    local($names);

    print "Mailing commit message...\n";
    dbmopen(MAILFILE, "$MAIL_FILE.$id", 0666);
    $names = join(" ", keys %MAILFILE) . " $mlist";
    $names =~ s,\n,,;
    dbmclose(MAILFILE);

    open(MAIL, "| mail -s \"cvs commit: $ARGV[0]\" $names");
    print(MAIL join("\n", @text));
    close(MAIL);
}

#############################################################
#
# Main Body
#
############################################################

#
# Initialize basic variables
#
$id = getpgrp();
$state = $STATE_NONE;
$login = getlogin || (getpwuid($<))[0] || die("Unknown user $<.\n");
@files = split(' ', $ARGV[0]);
@path = split('/', $files[0]);
$repository = @path[0];
if ($#path == 0) {
    $dir = ".";
} else {
    $dir = join('/', @path[1..$#path]);
}
#print("ARGV  - ", join(":", @ARGV), "\n");
#print("files - ", join(":", @files), "\n");
#print("path  - ", join(":", @path), "\n");
#print("dir   - ", $dir, "\n");
#print("id    - ", $id, "\n");

$mlist = &mlist_map($files[0]);

#
# Check for a new directory first.  This will always appear as a
# single item in the argument list, and an empty log message.
#
if ($ARGV[0] =~ /New directory/) {
    $version = &bump_version if ($cisco_systems != 0);
    $header = &build_header($version);
    @text = ();
    push(@text, $header);
    push(@text, "");
    push(@text, "  ".$ARGV[0]);
    &do_changes_file(@text);
    &mail_notification(@text);
    exit 0;
}

&do_avail_file($dir);

#
# Iterate over the body of the message collecting information.
#
while (<STDIN>) {
    chop;			# Drop the newline
    if (/^Modified Files/) { $state = $STATE_CHANGED; next; }
    if (/^Added Files/)    { $state = $STATE_ADDED;   next; }
    if (/^Removed Files/)  { $state = $STATE_REMOVED; next; }
    if (/^Log Message/)    { $state = $STATE_LOG;     next; }
    s/^[ \t\n]+//;		# delete leading space
    s/[ \t\n]+$//;		# delete trailing space
    
    push (@changed_files, split) if ($state == $STATE_CHANGED);
    push (@added_files,   split) if ($state == $STATE_ADDED);
    push (@removed_files, split) if ($state == $STATE_REMOVED);
    push (@log_lines,     $_)    if ($state == $STATE_LOG);
}

#
# Strip leading and trailing blank lines from the log message.  Also
# compress multiple blank lines in the body of the message down to a
# single blank line.
#
while ($#log_lines > -1) {
    last if ($log_lines[0] ne "");
    shift(@log_lines);
}
while ($#log_lines > -1) {
    last if ($log_lines[$#log_lines] ne "");
    pop(@log_lines);
}
for ($i = $#log_lines; $i > 0; $i--) {
    if (($log_lines[$i - 1] eq "") && ($log_lines[$i] eq "")) {
	splice(@log_lines, $i, 1);
    }
}

#
# Find the log file that matches this log message
#
for ($i = 0; ; $i++) {
    last if (! -e "$LOG_FILE.$i.$id");
    @text = &read_logfile("$LOG_FILE.$i.$id", "");
    last if ($#text == -1);
    last if (join(" ", @log_lines) eq join(" ", @text));
}

#
# Spit out the information gathered in this pass.
#
&write_logfile("$LOG_FILE.$i.$id", @log_lines);
&append_to_file("$ADDED_FILE.$i.$id",   $dir, @added_files);
&append_to_file("$CHANGED_FILE.$i.$id", $dir, @changed_files);
&append_to_file("$REMOVED_FILE.$i.$id", $dir, @removed_files);

#
# Check whether this is the last directory.  If not, quit.
#
if (-e "$LAST_FILE.$id") {
   $_ = &read_line("$LAST_FILE.$id");
   $tmpfiles=$files[0];
   $tmpfiles =~ s,([^a-zA-Z0-9_/]),\\$1,g;
   exit 0 if (! grep(/$tmpfiles$/, $_));
}

#
# This is it.  The commits are all finished.  Lump everything together
# into a single message, fire a copy off to the mailing list, and drop
# it on the end of the Changes file.
#
# Get the full version number
#
$version = &bump_version if ($cisco_systems != 0);
$header = &build_header($version);

#
# Produce the final compilation of the log messages
#
@text = ();
push(@text, $header);
push(@text, "");
for ($i = 0; ; $i++) {
    last if (! -e "$LOG_FILE.$i.$id");
    push(@text, &read_file("$CHANGED_FILE.$i.$id", "Modified:"));
    push(@text, &read_file("$ADDED_FILE.$i.$id", "Added:"));
    push(@text, &read_file("$REMOVED_FILE.$i.$id", "Removed:"));
    push(@text, "  Log:");
    push(@text, &read_logfile("$LOG_FILE.$i.$id", "  "));
    push(@text, "");
}
if ($cisco_systems != 0) {
    @ddts = grep(/^CSCdi/, split(' ', join(" ", @text)));
    $text[0] .= "  " . join(" ", @ddts);
}
#
# Put the log message at the beginning of the Changes file and mail
# out the notification.
#
&do_changes_file(@text);
&mail_notification(@text);
&cleanup_tmpfiles(1);
exit 0;
