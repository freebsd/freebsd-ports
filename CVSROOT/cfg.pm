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
	    $MAIL_ON_DIR_CREATION $TMPDIR %TEMPLATE_HEADERS
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
# Currently $IDHEADER must be an instance of $CVSHeader$, or an alias
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
}


#end
1; # Perl requires all modules to return true.  Don't delete!!!!
