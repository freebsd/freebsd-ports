# $FreeBSD$

####################################################################
####################################################################
# This file contains local configuration for the CVSROOT perl
# scripts.  It is loaded by cfg.pm and overrides the default
# configuration in that file.
#
# It is advised that you test it with 'perl -cw cfg_local.pm'
# before you commit any changes.
####################################################################
####################################################################

$CHECK_HEADERS = 1;
$IDHEADER = 'FreeBSD';
$UNEXPAND_RCSID = 1;

%TEMPLATE_HEADERS = (
	"Reviewed by"		=> '.*',
	"Submitted by"		=> '.*',
	"Obtained from"		=> '.*',
	"Approved by"		=> '.*',
	"PR"			=> '.*',
	"MFC after"		=> '\d+(\s+(days?|weeks?|months?))?'
);

$MAILCMD = "/usr/local/bin/mailsend -H";
$MAIL_BRANCH_HDR  = "X-FreeBSD-CVS-Branch";


# Wrap this in a hostname check to prevent mail to the FreeBSD
# list if someone borrows this file and forgets to change it.
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



1; # Perl requires all modules to return true.  Don't delete!!!!
#end
