#!/usr/bin/perl
#
# $Id$
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

#
# Where do you want the RCS ID and delta info?
# 0 = none,
# 1 = in mail only,
# 2 = rcsids in both mail and logs.
#
$rcsidinfo = 2;

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
$BRANCH_FILE   = "/tmp/#cvs.files.branch";
$SUMMARY_FILE  = "/tmp/#cvs.files.summary";
$FILE_PREFIX   = "#cvs.files";

$CVSROOT       = "$ENV{'CVSROOT'}";

$AVAIL_FILE    = "$CVSROOT/CVSROOT/avail";
$MAIL_FILE     = "/tmp/#cvs.mail";
$SUBJ_FILE     = "/tmp/#cvs.subj";
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

	push(@files, "$MAIL_FILE.$id.db")  if (-e "$MAIL_FILE.$id.db");
	push(@files, "$MAIL_FILE.$id.dir") if (-e "$MAIL_FILE.$id.dir");
	push(@files, "$MAIL_FILE.$id.pag") if (-e "$MAIL_FILE.$id.pag");

	push(@files, "$SUBJ_FILE.$id.db")  if (-e "$SUBJ_FILE.$id.db");
	push(@files, "$SUBJ_FILE.$id.dir") if (-e "$SUBJ_FILE.$id.dir");
	push(@files, "$SUBJ_FILE.$id.pag") if (-e "$SUBJ_FILE.$id.pag");
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

sub append_line {
    local($filename, $line) = @_;
    open(FILE, ">>$filename") || die("Cannot open file $filename.\n");
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

#
# do an 'cvs -Qn status' on each file in the arguments, and extract info.
#
sub change_summary {
    local($out, @filenames) = @_;
    local(@revline);
    local($file, $rev, $rcsfile, $line);

    while (@filenames) {
	$file = shift @filenames;

	if ("$file" eq "") {
	    next;
	}

	open(RCS, "-|") || exec 'cvs', '-Qn', 'status', $file;

	$rev = "";
	$delta = "";
	$rcsfile = "";


	while (<RCS>) {
	    if (/^[ \t]*Repository revision/) {
		chop;
		@revline = split(' ', $_);
		$rev = $revline[2];
		$rcsfile = $revline[3];
		$rcsfile =~ s,^$CVSROOT/,,;
		$rcsfile =~ s/,v$//;
	    }
	}
	close(RCS);

	if ($rev ne '' && $rcsfile ne '') {
	    open(RCS, "-|") || exec 'cvs', '-Qn', 'log', "-r$rev", $file;
	    while (<RCS>) {
		if (/^date:/) {
		    chop;
		    $delta = $_;
		    $delta =~ s/^.*;//;
		    $delta =~ s/^[\s]+lines://;
		}
	    }
	    close(RCS);
	}

	&append_line($out, sprintf("%-9s%-12s%s", $rev, $delta, $rcsfile));
    }
}


sub bump_version {
    local($trunkrev, $editnum, $version);

    $trunkrev = &read_line("$CVSROOT/$repository/$TRUNKREV_FILE");
    $editnum  = &read_line("$CVSROOT/$repository/$VERSION_FILE");
    &write_line("$CVSROOT/$repository/$VERSION_FILE", $editnum+1);
    $version = $trunkrev . "(" . $editnum . ")";
}

sub build_header {
    local($version) = @_;
    local($header);
    delete $ENV{'TZ'};
    local($sec,$min,$hour,$mday,$mon,$year) = localtime(time);
    $version = '';
    $header = sprintf("%-8s  %s  %02d/%02d/%02d %02d:%02d:%02d",
		       $login, $version, $year%100, $mon+1, $mday,
		       $hour, $min, $sec);
}

# !!! Mailing-list and history file mappings here !!!
sub mlist_map {
    local($dir) = @_;		# perl warns about this....
   
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

    dbmopen(%MAILFILE, "$MAIL_FILE.$id", 0666);

    foreach $category (keys %MAILFILE) {
	if ($category =~ /^cvs-/) {
	    $category =~ s,\n,,;
	    $category =~ s/^cvs-//;
	    $changes = "$CVSROOT/CVSROOT/commitlogs/$category";

	    open(CHANGES, ">>$changes") || die("Cannot open $changes.\n");
	    print(CHANGES join("\n", @text), "\n\n");
	    close(CHANGES);
	}
    }
    dbmclose(%MAILFILE);
}

sub do_avail_file {
    local($where) = @_;
    local($users,$repo,$who);

    dbmopen(%MAILFILE, "$MAIL_FILE.$id", 0666);
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
    dbmclose(%MAILFILE);
}

sub add_cc {
    local($who) = @_;

    # chop CC: and any leading space
    $who =~ s/^CC:[\s]+//i;	

    # re-quote it if possible..  I really don't want a rfc822 parser.. :-)
    $who =~ s/"//g;
    $who =~ s/^/"/;
    $who =~ s/$/"/;

    dbmopen(%MAILFILE, "$MAIL_FILE.$id", 0666);
    $MAILFILE{$who} = 1;
    dbmclose(%MAILFILE);
}


sub mail_notification {
    local(@text) = @_;
    local($names);
    local($subject);

    print "Mailing the commit message...\n";

    dbmopen(%MAILFILE, "$MAIL_FILE.$id", 0666);
    $names = "CVS-committers " . join(" ", keys %MAILFILE);
    $names =~ s,\n,,;
    dbmclose(%MAILFILE);

    dbmopen(%SUBJFILE, "$SUBJ_FILE.$id", 0666);
    $subject = join(" ", keys %SUBJFILE);
    $subject =~ s,\n,,;
    $subject =~ s,[ 	]*, ,;
    dbmclose(%SUBJFILE);

    #print "mail -s \"cvs commit: $subject\" $names\n";

    open(MAIL, "| mail -s \"cvs commit: $subject\" $names");
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
$login = $ENV{'USER'} || getlogin || (getpwuid($<))[0] || sprintf("uid#%d",$<);
@files = split(' ', $ARGV[0]);
@path = split('/', $files[0]);
$repository = $path[0];
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
dbmopen(%MAILFILE, "$MAIL_FILE.$id", 0666);
$MAILFILE{$mlist} = 1;
dbmclose(%MAILFILE);

dbmopen(%SUBJFILE, "$SUBJ_FILE.$id", 0666);
$SUBJFILE{$ARGV[0]} = 1;
dbmclose(%SUBJFILE);

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

# Check for an import command.  This will always appear as a
# single item in the argument list, and a log message.
#
if ($ARGV[0] =~ /Imported sources/) {
    $version = &bump_version if ($cisco_systems != 0);
    $header = &build_header($version);

    @text = ();
    push(@text, $header);
    push(@text, "");

    push(@text, "  ".$ARGV[0]);
    &do_changes_file(@text);

    while (<STDIN>) {
	chop;                   # Drop the newline
	push(@text, "  ".$_);
    }

    &mail_notification(@text);
    exit 0;
}    

#no longer useful. the CC: line would be _too_ big.
#&do_avail_file($dir);


#
# Iterate over the body of the message collecting information.
#
while (<STDIN>) {
    chop;			# Drop the newline
    if (/^Revision\/Branch:/) {
        s,^Revision/Branch:,,;
        push (@branch_lines, split);
        next;
    }
    if (/^Modified Files/) { $state = $STATE_CHANGED; next; }
    if (/^Added Files/)    { $state = $STATE_ADDED;   next; }
    if (/^Removed Files/)  { $state = $STATE_REMOVED; next; }
    if (/^Log Message/)    { $state = $STATE_LOG;     next; }
    s/[ \t\n]+$//;		# delete trailing space
    
    push (@changed_files, split) if ($state == $STATE_CHANGED);
    push (@added_files,   split) if ($state == $STATE_ADDED);
    push (@removed_files, split) if ($state == $STATE_REMOVED);
    if ($state == $STATE_LOG) {
	if (/^Reviewed by:$/i ||
	    /^Submitted by:$/i ||
	    /^Obtained from:$/i) {
	    next;
	}
	if (/^CC:/i) {
	    &add_cc($_);
	    # next;	# uncomment this to prevent logging CC: lines
	}
	push (@log_lines,     $_);
    }
}

#
# Strip leading and trailing blank lines from the log message.  Also
# compress multiple blank lines in the body of the message down to a
# single blank line.
# (Note, this only does the mail and changes log, not the rcs log).
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
&append_to_file("$BRANCH_FILE.$i.$id",  $dir, @branch_lines);
&append_to_file("$ADDED_FILE.$i.$id",   $dir, @added_files);
&append_to_file("$CHANGED_FILE.$i.$id", $dir, @changed_files);
&append_to_file("$REMOVED_FILE.$i.$id", $dir, @removed_files);
if ($rcsidinfo) {
    &change_summary("$SUMMARY_FILE.$i.$id", @changed_files);
}

#
# Check whether this is the last directory.  If not, quit.
#
if (-e "$LAST_FILE.$id") {
   $_ = &read_line("$LAST_FILE.$id");
   $tmpfiles=$files[0];
   $tmpfiles =~ s,([^a-zA-Z0-9_/]),\\$1,g;
   if (! grep(/$tmpfiles$/, $_)) {
	print "More commits to come...\n";
	exit 0
   }
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
    push(@text, &read_file("$BRANCH_FILE.$i.$id", "Branch:"));
    push(@text, &read_file("$CHANGED_FILE.$i.$id", "Modified:"));
    push(@text, &read_file("$ADDED_FILE.$i.$id", "Added:"));
    push(@text, &read_file("$REMOVED_FILE.$i.$id", "Removed:"));
    push(@text, "  Log:");
    push(@text, &read_logfile("$LOG_FILE.$i.$id", "  "));
    if ($rcsidinfo == 2) {
	if (-e "$SUMMARY_FILE.$i.$id") {
	    push(@text, "  ");
	    push(@text, "  Revision  Changes    Path");
	    push(@text, &read_logfile("$SUMMARY_FILE.$i.$id", "  "));
	}
    }
    push(@text, "");
}
if ($cisco_systems != 0) {
    @ddts = grep(/^CSCdi/, split(' ', join(" ", @text)));
    $text[0] .= "  " . join(" ", @ddts);
}
#
# Put the log message at the beginning of the Changes file
#
&do_changes_file(@text);
#
# Now generate the extra info for the mail message..
#
if ($rcsidinfo == 1) {
    $revhdr = 0;
    for ($i = 0; ; $i++) {
	last if (! -e "$LOG_FILE.$i.$id");
	if (-e "$SUMMARY_FILE.$i.$id") {
	    if (!$revhdr++) {
		push(@text, "Revision  Changes    Path");
	    }
	    push(@text, &read_logfile("$SUMMARY_FILE.$i.$id", ""));
	}
    }
    if ($revhdr) {
	push(@text, "");	# consistancy...
    }
}
#
# Mail out the notification.
#
&mail_notification(@text);
&cleanup_tmpfiles(1);
exit 0;
