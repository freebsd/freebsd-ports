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
$ADD_TO_LINE = 0;

# Sanity check to make sure we've been run through the wrapper and are
# now primary group 'ncvs'.
#
$COMMITCHECK_EXTRA = sub {
	my $GRP=`/usr/bin/id -gn`;
	chomp $GRP;
	unless ( $GRP =~ /^ncvs$/ ) {
		print "You do not have group ncvs (commitcheck)!\n";
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
if ($hostname =~ /^freefall\.freebsd\.org$/i) {
	$MAILADDRS='cvs-committers@FreeBSD.org cvs-all@FreeBSD.org';
	$MAILADDRS = 'cvs@FreeBSD.org' if $DEBUG;

	@COMMIT_HOSTS = qw(freefall.freebsd.org);
}


@LOG_FILE_MAP = (
	'CVSROOT'	=> '^CVSROOT/',
	'distrib'	=> '^distrib/',
	'doc'		=> '^doc/',
	'ports'		=> '^ports/',
	'projects'	=> '^projects/',
	'www'		=> '^www/',

	'bin'		=> '^src/bin/',
	'contrib'	=> '^src/contrib/',
	'eBones'	=> '^src/eBones/',
	'etc'		=> '^src/etc/',
	'games'		=> '^src/games/',
	'gnu'		=> '^src/gnu/',
	'include'	=> '^src/include/',
	'kerberosIV'	=> '^src/kerberosIV/',
	'lib'		=> '^src/lib/',
	'libexec'	=> '^src/libexec/',
	'lkm'		=> '^src/lkm/',
	'release'	=> '^src/release/',
	'sbin'		=> '^src/sbin/',
	'share'		=> '^src/share/',
	'sys'		=> '^src/sys/',
	'tools'		=> '^src/tools/',
	'usrbin'	=> '^src/usr\.bin/',
	'usrsbin'	=> '^src/usr\.sbin/',
	'user'		=> '^src/',

	'other'		=> '.*'
);

1; # Perl requires all modules to return true.  Don't delete!!!!
#end
