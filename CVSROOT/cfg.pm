# $FreeBSD$

####################################################################
####################################################################
# This file contains configuration for the CVSROOT perl scripts.
# WARNING: You are strongly advised to check for syntax errors
# in this file before committing it.  Use: perl -c cfg.pm
####################################################################
####################################################################

package cfg;
use strict;
use vars qw($DEBUG $TMPDIR %TEMPLATE_HEADERS);


######################
### global options ###
######################

# Debug level, 0 = off, 1 = on.
$DEBUG = 0;

# Location of temporary directory.
$TMPDIR = "/tmp/";


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


#end
1; # Perl required all modules to return true.  Don't delete!!!!
