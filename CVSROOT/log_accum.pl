#!/usr/bin/perl -w
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
# Originally by David Hampton <hampton@cisco.com>
#
# Extensively hacked for FreeBSD by Peter Wemm <peter@netplex.com.au>,
#  with parts stolen from Greg Woods <woods@most.wierd.com> version.
#
# Extensively cleaned up and re-worked to use an external configuration
# file by Josef Karthauser <joe@tao.org.uk>.

require 5.003;		# might work with older perl5

use strict;
use Text::Tabs;

use lib $ENV{CVSROOT};
use CVSROOT::cfg;
my $CVSROOT = $ENV{'CVSROOT'} || die "Can't determine \$CVSROOT!";


############################################################
#
# Constants
#
############################################################
my $STATE_NONE    = 0;
my $STATE_CHANGED = 1;
my $STATE_ADDED   = 2;
my $STATE_REMOVED = 3;
my $STATE_LOG     = 4;

my $BASE_FN       = "$cfg::TMPDIR/$cfg::FILE_PREFIX";
my $LAST_FILE     = $cfg::LAST_FILE;
my $CHANGED_FILE  = "$BASE_FN.changed";
my $ADDED_FILE    = "$BASE_FN.added";
my $REMOVED_FILE  = "$BASE_FN.removed";
my $LOG_FILE      = "$BASE_FN.log";
my $SUMMARY_FILE  = "$BASE_FN.summary";
my $LOGNAMES_FILE = "$BASE_FN.lognames";
my $SUBJ_FILE     = "$BASE_FN.subj";
my $TAGS_FILE     = "$BASE_FN.tags";
my $DIFF_FILE     = "$BASE_FN.diff";


############################################################
#
# Subroutines
#
############################################################

# Remove the temporary files.
sub cleanup_tmpfiles {
	my @files;		# The list of temporary files.

	# Don't clean up afterwards if in debug mode.
	return if $cfg::DEBUG;

	opendir DIR, $cfg::TMPDIR or die "Cannot open directory: $cfg::TMPDIR!";
	push @files, grep /^$cfg::FILE_PREFIX\..*$/, readdir(DIR);
	closedir DIR;

	foreach (@files) {
		unlink "$cfg::TMPDIR/$_";
	}
}


# Append a line to a named file.
sub append_line {
	my $filename = shift;	# File to append to.
	my $line = shift;	# Line to append.

	open FILE, ">>$filename" or
	    die "Cannot open for append file $filename.\n";
	print FILE "$line\n";
	close FILE;
}


# Read the first line from a named file.
sub read_line {
	my $filename = shift;	# The file to read the line from.

	my $line;		# The line read from the file.

	open FILE, "<$filename" or die "Cannot read file $filename!";
	$line = <FILE>;
	close FILE;
	chomp $line;

	return $line;
}


# Return the contents of a file as a list of strings,
# with trailing line feeds removed.
# Return an empty list of the file couldn't be opened for some reason.
sub read_logfile {
	my $filename = shift;	# The file to read from.

	my @text = ();		# The contents of the file.

	if (open FILE, "<$filename") {
		while (<FILE>) {
			chomp;
			push @text, $_;
		}
		close FILE;
	}

	return @text;
}


# Write a list to a file.
sub write_logfile {
	my $filename = shift;	# File to write to.
	my @lines = @_;		# Contents to write to file.

	open FILE, ">$filename" or
	    die "Cannot open for write log file $filename.";
	print FILE map { "$_\n" } @lines;
	close FILE;
}


sub format_names {
	my $dir = shift;
	my @files = @_;

	my $indent = length($dir);
	$indent = 20 if $indent < 20;

	my $format = "    %-" . sprintf("%d", $indent) . "s ";

	my @lines = (sprintf($format, $dir));

	if ($cfg::DEBUG) {
		print STDERR "format_names(): dir = ", $dir;
		#print STDERR "; tag = ", $tag;
		print STDERR "; files = ", join(":", @files), ".\n";
	}

	foreach my $file (@files) {
		if (length($lines[$#lines]) + length($file) > 66) {
			$lines[++$#lines] = sprintf($format, "", "");
		}
		$lines[$#lines] .= $file . " ";
	}

	return @lines;
}


sub format_lists {
	my $header = shift;
	my @lines = @_;

	print STDERR "format_lists(): ", join(":", @lines), "\n" if $cfg::DEBUG;

	my $lastdir = '';
	my $lastsep = '';
	my $tag = '';
	my @files = ();
	my @text = ();
	foreach my $line (@lines) {
		if ($line =~ /.*\/$/) {
			push @text, &format_names($lastdir, @files) if $lastdir;
			@files = ();

			$lastdir = $line;
			$lastdir =~ s,/$,,;

			$tag = "";	# next thing is a tag
		} elsif (!$tag) {
			$tag = $line;
			next if "$header$tag" eq $lastsep;

			$lastsep = $header . $tag;
			if ($tag eq 'HEAD') {
				push @text, "  $header files:";
			} else {
				push @text, sprintf("  %-22s (Branch: %s)",
				    "$header files:", $tag);
			}
		} else {
			push @files, $line;
		}
	}
	push @text, &format_names($lastdir, sort @files);

	return @text;
}


sub append_names_to_file {
	my $filename = shift;
	my $dir = shift;
	my $tag = shift;
	my @files = @_;

	return unless @files;

	open FILE, ">>$filename" or die "Cannot append to file $filename.";

	print FILE $dir, "\n";
	print FILE $tag, "\n";
	print FILE map { "$_\n" } @files;
	close FILE;
}


#
# Use cvs status to obtain the current revision number of a given file.
#
sub get_revision_number {
	my $file = shift;

	my $rcsfile = "";
	my $revision = "";

	open(RCS, "-|") || exec $cfg::PROG_CVS, '-Qn', 'status', $file;
	while (<RCS>) {
		if (/^[ \t]*Repository revision/) {
			chomp;
			my @revline = split;
			$revision = $revline[2];
			$revline[3] =~ m|^$CVSROOT/+(.*),v$|;
			$rcsfile = $1;
			last;
		}
	}
	close RCS;

	$rcsfile =~ s|/Attic/|/|;	# Remove 'Attic/' if present.
	return($revision, $rcsfile);
}


#
# Return the previous revision number.
#
sub previous_revision {
	my $rev = shift;

	$rev =~ /(?:(.*)\.)?([^\.]+)\.([^\.]+)$/;
	my ($base, $r1, $r2) = ($1, $2, $3);

	my $prevrev = "";
	if ($r2 == 1) {
		$prevrev = $base;
	} else {
		$prevrev = "$base." if $base;
		$prevrev .= "$r1." . ($r2 - 1);
	}
	return $prevrev;
}


#
# Count the number of lines in a given revision of a file.
#
sub count_lines_in_revision {
	my $file = shift;	# File in repository.
	my $rev = shift;	# Revision number.

	my $lines = 0;
	open(RCS, "-|") ||
	    exec $cfg::PROG_CVS, '-Qn', 'update', '-p', "-r$rev", $file;
	while (<RCS>) {
		++$lines;
	}
	close RCS;

	return $lines;
}


#
# Summarise details of the file modifications.
#
sub change_summary_changed {
	my $outfile = shift;		# File name of output file.
	my @filenames = @_;		# List of files to check.

	foreach my $file (@filenames) {
		next unless $file;

		my $delta = "";
		my ($rev, $rcsfile) = get_revision_number($file);

		if ($rev and $rcsfile) {
			open(RCS, "-|") ||
			    exec $cfg::PROG_CVS, '-Qn', 'log', "-r$rev", $file;
			while (<RCS>) {
				if (/^date:.*lines:\s(.*)$/) {
					$delta = $1;
					last;
				}
			}
			close RCS;
		}

		&append_line($outfile, "$rev,$delta,,$rcsfile");
	}
}


#
# Summarise details of added files.
#
sub change_summary_added {
	my $outfile = shift;		# File name of output file.
	my @filenames = @_;		# List of files to check.

	foreach my $file (@filenames) {
		next unless $file;

		my $delta = "";
		my ($rev, $rcsfile) = get_revision_number($file);

		if ($rev and $rcsfile) {
			my $lines = count_lines_in_revision($file, $rev);
			$delta = "+$lines -0";
		}

		&append_line($outfile, "$rev,$delta,new,$rcsfile");
	}
}


#
# Summarise details of removed files.
#
sub change_summary_removed {
	my $outfile = shift;		# File name of output file.
	my @filenames = @_;		# List of files to check.

	foreach my $file (@filenames) {
		next unless $file;

		my $delta = "";
		my ($rev, $rcsfile) = get_revision_number($file);

		if ($rev and $rcsfile) {
			my $prevrev = previous_revision($rev);
			my $lines = count_lines_in_revision($file, $prevrev);
			$delta = "+0 -$lines";
		}

		&append_line($outfile, "$rev,$delta,dead,$rcsfile");
	}
}


sub build_header {
	delete $ENV{'TZ'};

	my $datestr = `/bin/date +"%Y/%m/%d %H:%M:%S %Z"`;
	chomp $datestr;

	my $header = sprintf("%-8s    %s", $cfg::COMMITTER, $datestr);

	my @text;
	push @text, $header;
	push @text, "";
	push @text, "  $cfg::MAILBANNER", "" if $cfg::MAILBANNER;

	return @text;
}


# !!! Mailing-list and commitlog history file mappings here !!!
# This needs pulling out as a configuration block somewhere so
# that others can easily change it.
sub get_log_name {
	my $dir = shift;	# Directory name


	for my $i (0 .. ($#cfg::LOG_FILE_MAP - 1) / 2) {
		my $log = $cfg::LOG_FILE_MAP[$i * 2];
		my $pattern = $cfg::LOG_FILE_MAP[$i * 2 + 1];

		return $log if $dir =~ /$pattern/;
	}

	return 'other';
}


sub do_changes_file {
	my @text = @_;

	my %unique = ();
	my @mailaddrs = &read_logfile($LOGNAMES_FILE);
	foreach my $category (@mailaddrs) {
		next if ($unique{$category});
		$unique{$category} = 1;

		my $changes = "$CVSROOT/CVSROOT/commitlogs/$category";
		open CHANGES, ">>$changes"
			or die "Cannot open $changes.\n";
		print CHANGES map { "$_\n" } @text;
		print CHANGES "\n\n\n";
		close CHANGES;
	}
}


sub mail_notification {
	my @text = @_;

# This is turned off since the To: lines go overboard.
# Also it has bit-rotted since, and can't just be switched on again.
# - but keep it for the time being in case we do something like cvs-stable
#	my @mailaddrs = &read_logfile($LOGNAMES_FILE);
#	print(MAIL 'To: cvs-committers' . $dom . ", cvs-all" . $dom);
#	foreach $line (@mailaddrs) {
#		next if ($unique{$line});
#		$unique{$line} = 1;
#		next if /^cvs-/;
#		print(MAIL ", " . $line . $dom);
#	}
#	print(MAIL "\n");

	my @email = ();

	my $to = $cfg::MAILADDRS;
	print "Mailing the commit message to '$to'.\n";

	push @email, "To: $to" if $cfg::ADD_TO_LINE;

	my $subject = 'Subject: cvs commit:';
	my @subj = &read_logfile($SUBJ_FILE);
	my $subjlines = 0;
	my $subjwords = 0;	# minimum of two "words" per line
	LINE: foreach my $line (@subj) {
		foreach my $word (split(/ /, $line)) {
			if ($subjwords > 2 &&
			    length("$subject $word") > 75) {
				if ($subjlines > 2) {
					$subject .= " ...";
				}
				push @email, $subject;
				if ($subjlines > 2) {
					$subject = "";
					last LINE;
				}

				# rfc822 continuation line
				$subject = "        ";
				$subjwords = 0;
				$subjlines++;
			}
			$subject .= " " . $word;
			$subjwords++;
		}
	}
	push @email, $subject if $subject;

	# If required add a header to the mail msg showing
	# which branches were modified during the commit.
	if ($cfg::MAIL_BRANCH_HDR) {
		my %tags = map { $_ => 1 } &read_logfile($TAGS_FILE);
		if (keys %tags) {
			push @email, $cfg::MAIL_BRANCH_HDR . ": " .
			    join(",", sort keys %tags);
		}
	}

	push @email, "";
	push @email, @text;

	# Transform the email message?
	if (defined($cfg::MAIL_TRANSFORM) && $cfg::MAIL_TRANSFORM) {
		die 'log_accum.pl: $cfg::MAIL_TRANSFORM isn\'t a sub!'
		    unless ref($cfg::MAIL_TRANSFORM) eq "CODE";

		if ($cfg::DEBUG) {
			print "Email transform.\n";
			print map { "Before: $_\n" } @email;
		}

		@email = &$cfg::MAIL_TRANSFORM(@email);

		print map { "After: $_\n" } @email if $cfg::DEBUG;
	}

	# Send the email.
	open MAIL, "| $cfg::MAILCMD $to"
	    or die "Please check $cfg::MAILCMD.";
	print MAIL map { "$_\n" } @email;
	close MAIL;
}


# Return the length of the longest value in the list.
sub longest_value {
	my @values = @_;

	my @sorted = sort { $b <=> $a } map { length $_ } @values;
	return $sorted[0];
}


sub format_summaries {
	my @filenames = @_;

	my @revs;
	my @deltas;
	my @files;
	my @statuses;

	# Parse the summary file.
	foreach my $filename (@filenames) {
		open FILE, $filename or next;
		while (<FILE>) {
			chomp;
			my ($r, $d, $s, $f) = split(/,/, $_, 4);
			push @revs, $r;
			push @deltas, $d;
			push @statuses, $s;
			push @files, $f;
		}
		close FILE;
	}

	# Format the output, extra spaces after "Changes"
	# to match historic formatting.
	my $r_max = longest_value("Revision", @revs) + 2;
	my $d_max = longest_value("Changes  ", @deltas) + 2;

	my @text;
	my $fmt = "%-" . $r_max . "s%-" . $d_max . "s%s";
	push @text, sprintf $fmt, "Revision", "Changes", "Path";

	my @order = sort { $files[$a] cmp $files[$b] } (0 .. $#revs);
	foreach (@order) {
		my $file = $files[$_];
		my $status = $statuses[$_];
		$file .= " ($status)" if $status;
		push @text, sprintf $fmt, $revs[$_], $deltas[$_], $file;
	}

	return @text;
}


#
# Make a diff of the changes.
#
sub do_diff {
	my $outfile = shift;
	my @filenames = @_;		# List of files to check.

	foreach my $file (@filenames) {
		next unless $file;

		my $diff;

		my ($rev, $rcsfile) = get_revision_number($file);

		#
		# If this is a binary file, don't try to report a diff;
		# not only is it meaningless, but it also screws up some
		# mailers.  We rely on Perl's 'is this binary' algorithm;
		# it's pretty good.  But not perfect.
		#
		if (($file =~ /\.(?:pdf|gif|jpg|tar|tgz|gz)$/i) or (-B $file)) {
			$diff .= "Index: $file\n";
			$diff .= "=" x 67 . "\n";
			$diff .= "\t<<Binary file>>\n";
		} else {
			#
			# Get the differences between this and the previous
			# revision, being aware that new files always have
			# revision '1.1' and new branches always end in '.n.1'.
			#
			if ($rev =~ /^(.*)\.([0-9]+)$/) {
				my $prev_rev = previous_revision($rev);

				my @args = ();
				if ($rev eq '1.1') {
					$diff .= "Index: $file\n"
					    . "=" x 68 . "\n";
					@args = ('-Qn', 'update', '-p',
					    '-r1.1', $file);
				} else {
					@args = ('-Qn', 'diff', '-u',
					    "-r$prev_rev", "-r$rev", $file);
				}

				print "Generating diff: $cfg::PROG_CVS " .
				    "@args" if  $cfg::DEBUG;
				open(DIFF, "-|") || exec $cfg::PROG_CVS, @args;
				while(<DIFF>) {
					$diff .= $_;
				}
				close DIFF;
			}
		}

		my $diff_length = length($diff);
		if ($diff_length > $cfg::MAX_DIFF_SIZE * 1024) {
			$diff = "File/diff for $file is too large (" .
			    $diff_length . " bytes > " .
			    $cfg::MAX_DIFF_SIZE * 1024 . " bytes)!\n";
		}
		&append_line($outfile, "\n\n$diff");
	}
}

#############################################################
#
# Main Body
#
############################################################

#
# Setup environment
#
umask (002);

#
# Initialize basic variables
#
my $input_params = $ARGV[0];
my ($directory, @filenames) = split " ", $input_params;
#@files = split(' ', $input_params);

my @path = split('/', $directory);
my $dir;
if ($#path == 0) {
	$dir = ".";
} else {
	$dir = join('/', @path[1..$#path]);
}
$dir = $dir . "/";

#
# Throw some values at the developer if in debug mode
#
if ($cfg::DEBUG) {
	print "ARGV      - ", join(":", @ARGV), "\n";
	print "directory - ", $directory, "\n";
	print "filenames - ", join(":", @filenames), "\n";
	print "path      - ", join(":", @path), "\n";
	print "dir       - ", $dir, "\n";
	print "pid       - ", $cfg::PID, "\n";
}

# Was used for To: lines, still used for commitlogs naming.
&append_line($LOGNAMES_FILE, &get_log_name("$directory/"));
&append_line($SUBJ_FILE, "$directory " . join(" ", sort @filenames));

#
# Check for a new directory first.  This will always appear as a
# single item in the argument list, and an empty log message.
#
if ($input_params =~ /New directory/) {
	my @text = &build_header();

	push @text, "  $input_params";
	&do_changes_file(@text);
	&mail_notification(@text) if $cfg::MAIL_ON_DIR_CREATION;
	&cleanup_tmpfiles();
	exit 0;
}

#
# Check for an import command.  This will always appear as a
# single item in the argument list, and a log message.
#
if ($input_params =~ /Imported sources/) {
	my @text = &build_header();
	my $vendor_tag;

	push @text, "  $input_params";

	while (<STDIN>) {
		chomp;
		push @text, "  $_";

		$vendor_tag = $1 if /Vendor Tag:\s*(\S*)/;
	}
	&append_line($TAGS_FILE, $vendor_tag) if $vendor_tag;

	&do_changes_file(@text);
	&mail_notification(@text);
	&cleanup_tmpfiles();
	exit 0;
}

#
# Iterate over the body of the message collecting information.
#
my %added_files;		# Hashes containing lists of files
my %changed_files;		# that have been changed, keyed
my %removed_files;		# by branch tag.

my @log_lines;			# The lines of the log message.

my $tag = "HEAD";		# Default branch is HEAD.
my $state = $STATE_NONE;	# Initially in no state.

while (<STDIN>) {
	s/[ \t\n]+$//;		# delete trailing space

	# parse the revision tag if it exists.
	if (/^Revision\/Branch:(.*)/)	{ $tag = $1;	 next; }
	if (/^[ \t]+Tag: (.*)/)		{ $tag = $1;	 next; }
	if (/^[ \t]+No tag$/)		{ $tag = "HEAD"; next; }

	# check for a state change, guarding against similar markers
	# in the log message itself.
	unless ($state == $STATE_LOG) {
		if (/^Modified Files/)	{ $state = $STATE_CHANGED; next; }
		if (/^Added Files/)	{ $state = $STATE_ADDED;   next; }
		if (/^Removed Files/)	{ $state = $STATE_REMOVED; next; }
		if (/^Log Message/)	{ $state = $STATE_LOG;	   next; }
	}

	# don't so anything if we're not in a state.
	next if $state == $STATE_NONE;

	# collect the log line (ignoring empty template entries)?
	if ($state == $STATE_LOG) {
		next if /^(.*):$/ and $cfg::TEMPLATE_HEADERS{$1};

		push @log_lines, $_;
	}

	# otherwise collect information about which files changed.
	my @files = split;
	push @{ $changed_files{$tag} },	@files if $state == $STATE_CHANGED;
	push @{ $added_files{$tag} },	@files if $state == $STATE_ADDED;
	push @{ $removed_files{$tag} },	@files if $state == $STATE_REMOVED;
}
&append_line($TAGS_FILE, $tag);

#
# Strip leading and trailing blank lines from the log message.
# Compress multiple blank lines in the body of the message down to a
# single blank line.
# Convert tabs to spaces, so that when we indent the email message and
# log file everything still lines up.
# (Note, this only does the mail and changes log, not the rcs log).
#
my $log_message = join "\n", @log_lines;
$log_message =~ s/\n{3,}/\n\n/g;
$log_message =~ s/^\n+//;
$log_message =~ s/\n+$//;
@log_lines = expand(split /\n/, $log_message);


#
# Find the log file that matches this log message
#
my $message_index;		# The index of this log message
for ($message_index = 0; ; $message_index++) {
	last unless -e "$LOG_FILE.$message_index";

	my @text = &read_logfile("$LOG_FILE.$message_index");
	last unless @text;
	last if "@log_lines" eq "@text";
}

#
# Spit out the information gathered in this pass.
#
foreach my $tag ( keys %added_files ) {
	&append_names_to_file("$ADDED_FILE.$message_index",   $dir, $tag,
	    @{ $added_files{$tag} });
}
foreach my $tag ( keys %changed_files ) {
	&append_names_to_file("$CHANGED_FILE.$message_index", $dir, $tag,
	    @{ $changed_files{$tag} });
}
foreach my $tag ( keys %removed_files ) {
	&append_names_to_file("$REMOVED_FILE.$message_index", $dir, $tag,
	    @{ $removed_files{$tag} });
}
&write_logfile("$LOG_FILE.$message_index", @log_lines);

#
# Save the info for the commit summary.
#
foreach my $tag ( keys %added_files ) {
	&change_summary_added("$SUMMARY_FILE.$message_index",
	    @{ $added_files{$tag} });
	&do_diff("$DIFF_FILE.$message_index", @{ $added_files{$tag} })
		if ( $cfg::MAX_DIFF_SIZE > 0 );
}
foreach my $tag ( keys %changed_files ) {
	&change_summary_changed("$SUMMARY_FILE.$message_index",
	    @{ $changed_files{$tag} });
	&do_diff("$DIFF_FILE.$message_index", @{ $changed_files{$tag} })
		if ( $cfg::MAX_DIFF_SIZE > 0 );
}
foreach my $tag ( keys %removed_files ) {
	&change_summary_removed("$SUMMARY_FILE.$message_index",
	    @{ $removed_files{$tag} });
}

#
# Check whether this is the last directory.  If not, quit.
# The last directory name was written by commit_prep.pl on
# the way in.
#
if (-e $LAST_FILE) {
	$_ = &read_line($LAST_FILE);
	my $tmpfiles = $directory;
	$tmpfiles =~ s,([^a-zA-Z0-9_/]),\\$1,g;
	unless (grep(/$tmpfiles$/, $_)) {
		print "More commits to come...\n";
		exit 0
	}
}

#
# This is it.  The commits are all finished.  Lump everything together
# into a single message, fire a copy off to the mailing list, and drop
# it on the end of the Changes file.
#

#
# Produce the final compilation of the log messages
#
my $diff_num_lines = $cfg::DIFF_BLOCK_TOTAL_LINES;
for (my $i = 0; ; $i++) {
	last unless -e "$LOG_FILE.$i";

	my @log_msg = &build_header();

	my @mod_lines = &read_logfile("$CHANGED_FILE.$i");
	push @log_msg, &format_lists("Modified", @mod_lines) if @mod_lines;

	my @add_lines = &read_logfile("$ADDED_FILE.$i");
	push @log_msg, &format_lists("Added", @add_lines) if @add_lines;

	my @rem_lines = &read_logfile("$REMOVED_FILE.$i");
	push @log_msg, &format_lists("Removed", @rem_lines) if @rem_lines;

	my @msg_lines = &read_logfile("$LOG_FILE.$i");
	push @log_msg, "  Log:", (map { "  $_" } @msg_lines) if @msg_lines;


	if (-e "$SUMMARY_FILE.$i") {
		push @log_msg, "  ", map {"  $_"}
		    format_summaries("$SUMMARY_FILE.$i");
	}

	#
	# Add a copy of the message in the relevant log files.
	#
	&do_changes_file(@log_msg);

	#
	# Add the diff after writing the log files.
	#
	if (-e "$DIFF_FILE.$i" and $diff_num_lines > 0) {
		my @diff_block = read_logfile("$DIFF_FILE.$i");

		my $lines_to_use = scalar @diff_block;
		$lines_to_use = $diff_num_lines
		    if $lines_to_use > $diff_num_lines;

		push @log_msg, "  ",
		    map {"  $_"} @diff_block[0 .. $lines_to_use - 1];

		$diff_num_lines -= $lines_to_use;
		if ($diff_num_lines <= 0) {
			push @log_msg, "",
			    "----------------------------------------------",
			    "Diff block truncated.  (Max lines = " .
			        $cfg::DIFF_BLOCK_TOTAL_LINES . ")",
			    "----------------------------------------------",
			    "";
		}
	}

	#
	# Mail out the notification.
	#
	&mail_notification(@log_msg);
}

&cleanup_tmpfiles();
exit 0;
# EOF
