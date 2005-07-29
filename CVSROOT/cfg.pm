# $FreeBSD$

####################################################################
####################################################################
# This file contains the default configuration for the CVSROOT
# perl scripts.  You are advised to override the configuration
# in the cfg_local.pm file instead of here.
#
# WARNING: You are strongly advised to check for syntax errors
# in this file before committing it.  Use: perl -cw cfg.pm
####################################################################
####################################################################

package cfg;
use strict;
use vars qw(
	$ADD_TO_LINE $AVAIL_FILE $CHECK_HEADERS $COMMITCHECK_EXTRA
	@COMMIT_HOSTS $COMMITTER $DEBUG $DIFF_BLOCK_TOTAL_LINES $EXCLUDE_FILE
	$FILE_PREFIX $IDHEADER $LAST_FILE @LOG_FILE_MAP $MAILADDRS $MAILBANNER
	$MAILCMD $MAIL_BRANCH_HDR $MAIL_ON_DIR_CREATION $MAIL_TRANSFORM
	$MINCVSVERSION $MAX_DIFF_SIZE $NO_DOS_LINEBREAKS $PID $PROG_CVS
	$PROG_MV %TEMPLATE_HEADERS $TMPDIR $TZ $UNEXPAND_RCSID $WARN_HEADERS
);
use POSIX qw(tzset);

my $CVSROOT = $ENV{'CVSROOT'} || die "Can't determine \$CVSROOT!";



######################
### global options ###
######################
### WARNING: these aren't global across all the scripts yet.
### This is work in progress.

# Process group id; used as a unique number in temporary file names.
$PID = getpgrp();

# Debug level, 0 = off, 1 = on.
$DEBUG = 0;

# Location of temporary directory.
$TMPDIR = "/tmp/";

# The filename prefix used for temporary files.
$FILE_PREFIX = "#cvs.files.$PID";

# The file used to store the name of the last directory examined
# when processing a multi-directory commit.
$LAST_FILE = "$TMPDIR/$FILE_PREFIX.lastdir";
# System tools.
$PROG_CVS =	'/usr/bin/cvs';		# cvs(1)
$PROG_MV =	'/bin/mv';		# mv(1)

# The username of the committer.
$COMMITTER = $ENV{"LOGNAME"} || $ENV{'USER'} || getlogin
		|| (getpwuid($<))[0] || sprintf("uid#%d",$<);

# Time zone
$TZ = undef;

###################
### commitcheck ###
###################

# A list of hosts the it's ok to commit on.  Useful if your committers
# take local copies of the repository to work off-line.
# (Empty if you don't want checks.)
@COMMIT_HOSTS = ();

# The minimum version of cvs that we will work with.
$MINCVSVERSION = "1090900";  # 1.9.9p0

# Additional commit time checks.  This is an anonymous subroutine
# that gets called early on in the validation process to see whether
# the committer is allowed to commit.  It should return true if
# everything is ok, otherwise the commit will be terminated.
$COMMITCHECK_EXTRA = "";


###################
### cvs_acls.pl ###
###################

# The name of the avail file that defines who's allow to
# commit to what.
$AVAIL_FILE = "$CVSROOT/CVSROOT/avail";


################
### logcheck ###
################

# These are the optional headers that can be filled at the end of
# each commit message.  The associated value is a regular-expression
# that is used to type-check the entered value.  If a match fails
# then the commit is rejected.  (See rcstemplate).
#
# Make sure that these are also described in the rcstemplate to
# make their usage clear to committers.
#
# In addition any of these entries that are left blank are removed
# from the log at commit time.  [Please note that for them to be
# removed from the rcslog in the repository you need to be running
# the version of cvs in the FreeBSD source tree.  We've got a local
# patch that causes cvs to read back the commit message after the
# commit_prep.pl script has had a chance to modify it (via the
# 'commitinfo' hook). ]
%TEMPLATE_HEADERS = (
#	"Reviewed by"		=> '.*',
#	"Submitted by"		=> '.*',
#	"Obtained from"		=> '.*',
#	"Approved by"		=> '.*',
#	"PR"			=> '.*',
#	"MFC after"		=> '\d+(\s+(days?|weeks?|months?))?',
#	"Security"		=> '.*'
);


######################
### commit_prep.pl ###
######################

# Check for instances of $IDHEADER in committed files, and
# bomb out if they're not present, or corrupted.
# Exclusions can be specified in the exclude file.
# Currently $IDHEADER must be an instance of '$ CVSHeader $', or an alias
# defined in CVSROOT/options.
$CHECK_HEADERS = 0;
$EXCLUDE_FILE = "$CVSROOT/CVSROOT/exclude";

# Make a header check a non-fatal error - just warn, don't exit.
$WARN_HEADERS = 0;

# WARNING: You will also need to be running the version of cvs that
# the FreeBSD project is using; I believe that we have some local patches
# that aren't in the main 'cvs' source.
# Additionally you'll need to tweak CVSROOT/options if you wish to use your
# own ident header.
$IDHEADER = 'CVSHeader';

# Contract any instances of $IDHEADER in the source file before committing.
# This is useful because it means that expanded headers aren't stored in
# the repository as part of the delta.
$UNEXPAND_RCSID = 0;

# Check for DOS/WINDOWS/MAC linebreaks in the file, bomb out if present.
# Exclusions can be specified in the exclude file.
$NO_DOS_LINEBREAKS = 0;


####################
### log_accum.pl ###
####################

# The command used to mail the log messages.
# Usually something like '/usr/sbin/sendmail'.
$MAILCMD = "/usr/sbin/sendmail";

# Email addresses of recipients of commit mail.
$MAILADDRS = 'nobody';

# Extra banner added to the top of commit email.
# Use "" if you don't want one.
# i.e. $MAILBANNER = "Project X CVS Repository";
$MAILBANNER = "";

# Send mail when directories are created in the repository.
# 0 = off, 1 = on.
$MAIL_ON_DIR_CREATION = 0;

# Include the names of the branches committed to in the commit email,
# using this header (leave off the trailing ':').
# Use "" if you don't want one.
$MAIL_BRANCH_HDR  = "X-CVS-Branch";

# Include a 'To:' header in the generated commit mail?
$ADD_TO_LINE = 1;

# This is a way to post-process the log email before it is mailed.
# Some people find it useful to use this to create URLs in their
# commit mails to show the patch in a web page (using cvsweb) for
# instance.
#
# The $MAIL_TRANSFORM variable should be "" if you don't want to
# use this feature.  Otherwise it should be a reference to a
# subroutine that is passed the email message as a list, and returns
# the modified list to the log_accum.pl script.  The list has one
# element per email line, with no trailing line feeds.  This function
# shouldn't add them.  If $DEBUG is switched on the log_accum.pl
# script will show the before and after on stdout at commit time.
#
# The example below shows a way of inserting links to cvsweb.
$MAIL_TRANSFORM = "";
#$MAIL_TRANSFORM = sub {
#	add_cvsweb_entry("http://www.example.org/cgi-bin/cvsweb.cgi", @_);
#};

# A copy of the commit summary is saved locally as well as being
# emailed to the committers.  The name of the local log is obtained
# by performing a pattern match on the directory that the files are
# in.  The following map defines the file names and their associated
# pattern match.  They are checked in order. The name 'other' is
# used if none of the patterns match.
#
# XXX The directory that the logs are placed in should be a
# configuration option too.
@LOG_FILE_MAP = (
	'CVSROOT'	=> '^CVSROOT/',
	'doc'		=> '^doc/',
	'user'		=> '^src/',
	'other'		=> '.*'
);

# Include diffs of not greater than this size in kbytes in the
# commit mail for each file modified. (0 = off).
$MAX_DIFF_SIZE = 0;

# Maximum size of in lines of the diff block.
$DIFF_BLOCK_TOTAL_LINES = 200;


######################
# EXAMPLES
######################
# A function for post-processing a log message
# and outputing it with URLs to a cvsweb.cgi in.
sub add_cvsweb_entry {
	my $url_to_cvsweb = shift;
	my @input = @_;
	my @output = ();

	# Skip down to the revision summary.
	while (1) {
		my $line = shift @input;
		last unless defined($line);

		push @output, $line;
		last if $line =~ /^\s*Revision\s*Changes\s*Path\s*$/;
	}

	# Add the url links
	my $skip = 0;
	foreach (@input) {
		# The revision block is terminated with an empty line.
		$skip = 1 if $_ =~ /^\s*$/;

		push @output, $_;
		next if $skip;

		my ($rev, $add, $sub, $file, $status) = split;

		$rev =~ /(?:(.*)\.)?([^\.]+)\.([^\.]+)$/;
		my ($base, $r1, $r2) = ($1, $2, $3);
		my $prevrev = "";
		if ($r2 == 1) {
			$prevrev = $base;
		} else {
			$prevrev = "$base." if $base;
			$prevrev .= "$r1." . ($r2 - 1);
		}

		my $baseurl = "$url_to_cvsweb/$file";
		my $extra;
		if (defined($status)) {
			$rev = $prevrev if $status =~ /dead/;
			$extra = "?rev=$rev&content-type=text/plain";
		} else {
			$extra = ".diff?r1=$prevrev&r2=$rev&f=h";
		}
		push @output, "$baseurl$extra";
	}

	return @output;
};


######################################################################
# Load the local configuration file, that allows the entries in this
# file to be overridden.
######################################################################
eval { require "$CVSROOT/CVSROOT/cfg_local.pm" }
    if -e "$CVSROOT/CVSROOT/cfg_local.pm";
warn $@ if $@;

if (defined $TZ) {
	$ENV{'TZ'} = $TZ;
} else {
	delete $ENV{'TZ'};
}
tzset;

1; # Perl requires all modules to return true.  Don't delete!!!!
#end
