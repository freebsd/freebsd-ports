# $FreeBSD$

####################################################################
####################################################################
# This file contains configuration for the CVSROOT perl scripts.
# WARNING: You are strongly advised to check for syntax errors
# in this file before committing it.  Use: perl -cw cfg.pm
####################################################################
####################################################################

package cfg;
use strict;
use vars qw($DEBUG $FILE_PREFIX $MAILADDRS $MAILBANNER $MAILCMD
	    $MAIL_BRANCH_HDR $MAIL_ON_DIR_CREATION $MAIL_TRANSFORM
	    $TMPDIR %TEMPLATE_HEADERS
	    $CHECK_HEADERS $LAST_FILE $PID $IDHEADER $UNEXPAND_RCSID);


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
%TEMPLATE_HEADERS = (
	"Reviewed by"		=> '.*',
	"Submitted by"		=> '.*',
	"Obtained from"		=> '.*',
	"Approved by"		=> '.*',
	"PR"			=> '.*',
	"MFC after"		=> '\d+(\s+(days?|weeks?|months?))?'
);


######################
### commit_prep.pl ###
######################

# Check for instances of $IDHEADER in committed files, and
# bomb out if they're not present, or corrupted.
# Exclusions can be specified in the CVSROOT/exclude file.
# Currently $IDHEADER must be an instance of '$ CVSHeader $', or an alias
# defined in CVSROOT/options.
$CHECK_HEADERS = 1;

# WARNING: You will also need to be running the version of cvs that
# the FreeBSD project is using; I believe that we have some local patches
# that aren't in the main 'cvs' source.
# Additionally you'll need to tweak CVSROOT/options if you wish to use your
# own ident header.
$IDHEADER = 'FreeBSD';	# Our RCS header is '$ FreeBSD $', 

# Contract any instances of $IDHEADER in the source file before committing.
# This is useful because it means that expanded headers aren't stored in
# the repository as part of the delta.
$UNEXPAND_RCSID = 1;


####################
### log_accum.pl ###
####################

# The command used to mail the log messages.
# Usually something like '/usr/sbin/sendmail'.  
$MAILCMD = "/usr/local/bin/mailsend -H";

# Email addresses of recipients of commit mail.
# (might be overridden below)
$MAILADDRS = 'nobody';

# Extra banner added to the top of commit email.
# i.e. $MAILBANNER = "Project X CVS Repository";
# Use "" if you don't want one.
$MAILBANNER = "";

# Send mail when directories are created in the repository.
# 0 = off, 1 = on.
$MAIL_ON_DIR_CREATION = 0;

# Include the names of the branches committed to in the commit email,
# using this header (leave off the trailing ':').  Use "" if you don't
# want one.
$MAIL_BRANCH_HDR  = "X-CVS-Branch";

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
		last if $line =~ /^\s*Revision\s*Changes\s*Path\s*$/;

		push @output, $line;
	}

	# Add the url links
	foreach (@input) {
		# Skip any trailing blank lines.
		unless ($_) {
			push @output, $_;
			next;
		}

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
			$extra = ".diff?r1=$prevrev&r2=$rev";
		}
		push @output, $_;
		push @output, "$baseurl$extra";
	}
	    
	return @output;
};






##############################################################
##############################################################
# FreeBSD site localisation [overrides configuration above].
# Remember to comment out if using for other purposes.
##############################################################
##############################################################
my $hostname = `/bin/hostname`;
die "Can't determine hostname!\n" if $? >> 8;
chomp $hostname;
if ($hostname =~ /^(freefall|internat)\.freebsd\.org$/i) {
	my $meister;

	$MAILADDRS='cvs-committers@FreeBSD.org cvs-all@FreeBSD.org';
	if ($1 =~ /freefall/i) {
		$meister = 'peter@FreeBSD.org';
	} else {
		$meister = 'markm@FreeBSD.org';
		$MAILBANNER = "FreeBSD International Crypto Repository";
	}
	$MAILADDRS = $meister if $DEBUG;


	$MAIL_BRANCH_HDR  = "X-FreeBSD-CVS-Branch";
}


#end
1; # Perl requires all modules to return true.  Don't delete!!!!
