# New ports collection makefile for:	jp-perl5
# Version required:	5.003
# Date created:		7 January 1997
# Whom:			Yoshiro MIHIRA
#
# $Id: Makefile,v 1.6 1997/05/28 19:52:34 fenner Exp $
#

DISTNAME=	perl5.003
PKGNAME=	jp-perl-5.003
CATEGORIES=	japanese perl5
MASTER_SITES=	ftp://ftp.funet.fi/pub/languages/perl/CPAN/src/5.0/ \
		ftp://ftp.is.co.za/pub/perl/CPAN/src/5.0/ \
		ftp://ftp.math.ncu.edu.tw/perl/CPAN/src/5.0/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/src/5.0/ \
		ftp://ftp.pasteur.fr/pub/computing/unix/perl/CPAN/src/5.0/ \
		ftp://ftp.sunet.se/pub/lang/perl/CPAN/src/5.0/ \
		ftp://ftp.switch.ch/mirror/CPAN/src/5.0/ \
		ftp://unix.hensa.ac.uk/mirrors/perl-CPAN/src/5.0/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/src/5.0/ \
		ftp://ftp.delphi.com/pub/mirrors/packages/perl/CPAN/src/5.0/ \
		ftp://uiarchive.cso.uiuc.edu/pub/lang/perl/CPAN/src/5.0/

PATCHFILES=	jperl5.003.patch7_1.gz
PATCH_SITES=	ftp://ftp.funet.fi/pub/languages/perl/CPAN/authors/id/WATANABE/ \
		ftp://ftp.is.co.za/pub/perl/CPAN/authors/id/WATANABE/ \
		ftp://ftp.math.ncu.edu.tw/perl/CPAN/authors/id/WATANABE/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/authors/id/WATANABE/ \
		ftp://ftp.pasteur.fr/pub/computing/unix/perl/CPAN/authors/id/WATANABE/ \
		ftp://ftp.sunet.se/pub/lang/perl/CPAN/authors/id/WATANABE/ \
		ftp://ftp.switch.ch/mirror/CPAN/authors/id/WATANABE/ \
		ftp://unix.hensa.ac.uk/mirrors/perl-CPAN/authors/id/WATANABE/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/authors/id/WATANABE/ \
		ftp://ftp.delphi.com/pub/mirrors/packages/perl/CPAN/authors/id/WATANABE/ \
		ftp://uiarchive.cso.uiuc.edu/pub/lang/perl/CPAN/authors/id/WATANABE/

MAINTAINER=	sanpei@yy.cs.keio.ac.jp

PATCH_DIST_STRIP=       -p1
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-sde -Dprefix=${PREFIX}

MAN1= 	perlbook.1 perlbot.1 perlcall.1 perldata.1 perldebug.1 perldiag.1  \
	perlembed.1 perlform.1 perlfunc.1 perlguts.1 perlipc.1 perllol.1   \
	perlmod.1 perlobj.1 perlop.1 perlovl.1 perlpod.1 perlre.1 perlref.1 \
	perlrun.1 perlsec.1 perlstyle.1 perlsub.1 perlsyn.1 perltie.1  \
	perltoc.1 perltrap.1 perlvar.1 perlxs.1 perlxstut.1 perl.1 \
	a2p.1 s2p.1 jperl.1
MAN3=	AnyDBM_File.3 AutoLoader.3 AutoSplit.3 Benchmark.3 \
	Carp.3 Cwd.3 DirHandle.3 ExtUtils::Manifest.3 Devel::SelfStubber.3 \
	English.3 Env.3 Exporter.3 Term::Cap.3 Shell.3 ExtUtils::Install.3 \
	ExtUtils::Liblist.3 ExtUtils::MM_OS2.3 ExtUtils::MM_Unix.3 \
	ExtUtils::MM_VMS.3 ExtUtils::MakeMaker.3 FileCache.3 \
	ExtUtils::Mkbootstrap.3 ExtUtils::Mksymlists.3 ExtUtils::testlib.3\
	ExtUtils::Miniperl.3 File::Basename.3 File::CheckTree.3 \
	File::Copy.3 File::Find.3 File::Path.3 Getopt::Long.3 \
	Getopt::Std.3 I18N::Collate.3 IPC::Open2.3 IPC::Open3.3 \
	Math::BigFloat.3 Math::BigInt.3 Math::Complex.3 Net::Ping.3 \
	Pod::Text.3 Search::Dict.3 SelectSaver.3 SelfLoader.3 Symbol.3 \
	Text::ParseWords.3 Sys::Hostname.3 Sys::Syslog.3 Term::Complete.3 \
	Term::ReadLine.3 Test::Harness.3 Text::Abbrev.3 subs.3 \
	Text::Soundex.3 Text::Tabs.3 Text::Wrap.3 Tie::Hash.3 \
	Tie::Scalar.3 Tie::SubstrHash.3 Time::Local.3 diagnostics.3 \
	integer.3 less.3 lib.3 overload.3 sigtrap.3 strict.3 vars.3 \
	Config.3 DynaLoader.3 DB_File.3 Fcntl.3 FileHandle.3 \
	NDBM_File.3 POSIX.3 SDBM_File.3 Safe.3 Socket.3 I18N::Japanese.3
MAN3PREFIX=	${PREFIX}/lib/perl5

test:
	@(cd ${WRKSRC}; make test)

post-install:
	@strip ${PREFIX}/bin/perl ${PREFIX}/bin/suidperl
	@ln -fs ${PREFIX}/bin/perl ${PREFIX}/bin/jperl

.include <bsd.port.mk>
