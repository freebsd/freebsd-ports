# $FreeBSD$

####################################################################
####################################################################
# This file contains local configuration for the CVSROOT perl
# scripts.  It is loaded by cfg.pm and overrides the default
# configuration in that file.
#
# It is advised that you test it with
#     'env CVSROOT=/path/to/cvsroot perl -cw cfg.pm'
# before you commit any changes.  The check is to cfg.pm which
# loads this file.
####################################################################
####################################################################

$TZ = 'Etc/UTC';
$CHECK_HEADERS = 1;
$IDHEADER = 'FreeBSD';
$UNEXPAND_RCSID = 1;

%TEMPLATE_HEADERS = (
	"Reviewed by"		=> '.*',
	"Submitted by"		=> '.*',
	"Obtained from"		=> '.*',
	"Approved by"		=> '.*',
	"PR"			=> '.*',
	"MFC after"		=> '\d+(\s+(days?|weeks?|months?))?',
	"Security"		=> '.*'
);

$MAILCMD = "/usr/local/bin/mailsend -H";
$MAIL_BRANCH_HDR  = "X-FreeBSD-CVS-Branch";
$ADD_TO_LINE = 0;
$MAILBANNER = "FreeBSD ports repository";
if (defined $ENV{'CVS_COMMIT_ATTRIB'}) {
  my $attrib = $ENV{'CVS_COMMIT_ATTRIB'};
  $MAILBANNER .= " ($attrib committer)";
}

# Sanity check to make sure we've been run through the wrapper and are
# now primary group 'pcvs'.
#
$COMMITCHECK_EXTRA = sub {
	my $GRP=`/usr/bin/id -gn`;
	chomp $GRP;
	unless ( $GRP =~ /^pcvs$/ ) {
		print "You do not have group pcvs (commitcheck)!\n";
		exit 1;	# We could return false here.  But there's
			# nothing to stop us taking action here instead.
	}
	return 1;
};

# Wrap this in a hostname check to prevent mail to the FreeBSD
# list if someone borrows this file and forgets to change it.
my $hostname = `/bin/hostname`;
die "Can't determine hostname!\n" if $? >> 8;
chomp $hostname;
if ($hostname =~ /^repoman\.freebsd\.org$/i) {
	$MAILADDRS='ports-committers@FreeBSD.org cvs-ports@FreeBSD.org cvs-all@FreeBSD.org';
	$MAILADDRS = 'cvs@FreeBSD.org' if $DEBUG;

	@COMMIT_HOSTS = qw(repoman.freebsd.org);
}


@LOG_FILE_MAP = (
	'CVSROOT'	=> '^CVSROOT/',
	'ports'		=> '^ports/',
	'other'		=> '.*'
);

1; # Perl requires all modules to return true.  Don't delete!!!!
#end
