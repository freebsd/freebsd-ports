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
	    $LAST_FILE $PID);


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


####################
### log_accum.pl ###
####################

# The command used to mail the log messages.
# Usually something like '/usr/sbin/sendmail'.  
$MAILCMD = "/usr/local/bin/mailsend -H";

# Email addresses of recipients of commit mail.
# (might be overridden below)
$MAILADDRS = "nobody";

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
use Sys::Hostname;		# get hostname() function
if (hostname() =~ /^(freefall|internat)\.freebsd\.org$/i) {
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
