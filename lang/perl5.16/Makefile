# New ports collection makefile for:	perl5
# Version required:	5.004_04
# Date created:		16 April 1995
# Whom:			markm
#
# $Id: Makefile,v 1.23 1998/02/15 23:03:58 steve Exp $
#

DISTNAME=	perl5.005_01
PKGNAME=	perl-5.00501
CATEGORIES=	lang devel perl5
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=	markm@FreeBSD.ORG

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-sde -Dprefix=${PREFIX}

MAN1=	a2p.1 c2ph.1 h2ph.1 h2xs.1 perl.1 perl5004delta.1 \
	perlapio.1 perlbook.1 perlbot.1 perlbug.1 perlcall.1 \
	perldata.1 perldebug.1 perldelta.1 perldiag.1 perldoc.1 \
	perldsc.1 perlembed.1 perlfaq.1 perlfaq1.1 perlfaq2.1 \
	perlfaq3.1 perlfaq4.1 perlfaq5.1 perlfaq6.1 perlfaq7.1 \
	perlfaq8.1 perlfaq9.1 perlform.1 perlfunc.1 perlguts.1 \
	perlhist.1 perlipc.1 perllocale.1 perllol.1 perlmod.1 \
	perlmodinstall.1 perlmodlib.1 perlobj.1 perlop.1 \
	perlpod.1 perlport.1 perlre.1 perlref.1 perlrun.1 \
	perlsec.1 perlstyle.1 perlsub.1 perlsyn.1 perltie.1 \
	perltoc.1 perltoot.1 perltrap.1 perlvar.1 perlxs.1 \
	perlxstut.1 pl2pm.1 pod2html.1 pod2man.1 pstruct.1 \
	s2p.1 splain.1 xsubpp.1

MAN3=	AnyDBM_File.3 AutoLoader.3 AutoSplit.3 B.3 B::Asmdata.3 \
	B::Assembler.3 B::Bblock.3 B::Bytecode.3 B::C.3 B::CC.3 \
	B::Debug.3 B::Deparse.3 B::Disassembler.3 B::Lint.3 \
	B::Showlex.3 B::Stackobj.3 B::Terse.3 B::Xref.3 \
	Benchmark.3 CGI.3 CGI::Apache.3 CGI::Carp.3 CGI::Cookie.3 \
	CGI::Fast.3 CGI::Push.3 CGI::Switch.3 CPAN.3 \
	CPAN::FirstTime.3 CPAN::Nox.3 Carp.3 Class::Struct.3 \
	Config.3 Cwd.3 DB_File.3 Data::Dumper.3 Devel::SelfStubber.3 \
	DirHandle.3 DynaLoader.3 English.3 Env.3 Errno.3 \
	Exporter.3 ExtUtils::Command.3 ExtUtils::Embed.3 \
	ExtUtils::Install.3 ExtUtils::Installed.3 ExtUtils::Liblist.3 \
	ExtUtils::MM_OS2.3 ExtUtils::MM_Unix.3 ExtUtils::MM_VMS.3 \
	ExtUtils::MM_Win32.3 ExtUtils::MakeMaker.3 ExtUtils::Manifest.3 \
	ExtUtils::Miniperl.3 ExtUtils::Mkbootstrap.3 \
	ExtUtils::Mksymlists.3 ExtUtils::Packlist.3 ExtUtils::testlib.3 \
	Fatal.3 Fcntl.3 File::Basename.3 File::CheckTree.3 \
	File::Compare.3 File::Copy.3 File::DosGlob.3 File::Find.3 \
	File::Path.3 File::Spec.3 File::Spec::Mac.3 File::Spec::OS2.3 \
	File::Spec::Unix.3 File::Spec::VMS.3 File::Spec::Win32.3 \
	File::stat.3 FileCache.3 FileHandle.3 FindBin.3 \
	Getopt::Long.3 Getopt::Std.3 I18N::Collate.3 IO.3 \
	IO::File.3 IO::Handle.3 IO::Pipe.3 IO::Seekable.3 \
	IO::Select.3 IO::Socket.3 IPC::Msg.3 IPC::Open2.3 \
	IPC::Open3.3 IPC::Semaphore.3 IPC::SysV.3 Math::BigFloat.3 \
	Math::BigInt.3 Math::Complex.3 Math::Trig.3 NDBM_File.3 \
	Net::Ping.3 Net::hostent.3 Net::netent.3 Net::protoent.3 \
	Net::servent.3 O.3 Opcode.3 POSIX.3 Pod::Html.3 \
	Pod::Text.3 SDBM_File.3 Safe.3 Search::Dict.3 \
	SelectSaver.3 SelfLoader.3 Shell.3 Socket.3 Symbol.3 \
	Sys::Hostname.3 Sys::Syslog.3 Term::Cap.3 Term::Complete.3 \
	Term::ReadLine.3 Test.3 Test::Harness.3 Text::Abbrev.3 \
	Text::ParseWords.3 Text::Soundex.3 Text::Tabs.3 Text::Wrap.3 \
	Tie::Array.3 Tie::Handle.3 Tie::Hash.3 Tie::RefHash.3 \
	Tie::Scalar.3 Tie::SubstrHash.3 Time::Local.3 Time::gmtime.3 \
	Time::localtime.3 Time::tm.3 UNIVERSAL.3 User::grent.3 \
	User::pwent.3 attrs.3 autouse.3 base.3 blib.3 \
	constant.3 diagnostics.3 fields.3 integer.3 less.3 \
	lib.3 locale.3 ops.3 overload.3 re.3 sigtrap.3 \
	strict.3 subs.3 vars.3

MAN3PREFIX=	${PREFIX}/lib/perl5/5.00501/

test:
	@(cd ${WRKSRC}; make test)

post-install:
	@strip ${PREFIX}/bin/perl ${PREFIX}/bin/suidperl
	@ln -sf ${PREFIX}/bin/perl ${PREFIX}/bin/perl5
	@(cd /usr/include && ${PREFIX}/bin/h2ph *.h machine/*.h sys/*.h)

.include <bsd.port.mk>
