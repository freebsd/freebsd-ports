# New ports collection makefile for:	perl5
# Date created:		16 April 1995
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	${PERL_VER}
PORTREVISION=	15
CATEGORIES=	lang devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	../../src \
			tobez/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		BSDPAN-${PORTVERSION}_${BSDPAN_REVISION}${EXTRACT_SUFX}:local

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

PERL_VER=	5.6.1
PERL_ARCH=	mach
PERL_VERSION=	${PERL_VER}

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-sde -Dprefix=${PREFIX} \
	-Darchlib=${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH} \
	-Dprivlib=${PREFIX}/lib/perl5/${PERL_VER} \
	-Dman3dir=${PREFIX}/lib/perl5/${PERL_VER}/man/man3 \
	-Dsitearch=${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH} \
	-Dsitelib=${PREFIX}/lib/perl5/site_perl/${PERL_VER} \
	-Dscriptdir=${PREFIX}/bin \
	-Dcc="${CC}" \
	-Ui_malloc -Ui_iconv -Dccflags=-DAPPLLIB_EXP=\"${BSDPAN_DEST}\"
INSTALLS_SHLIB=	yes

.if defined(WITH_GDBM)
CONFIGURE_ARGS+=	-Di_gdbm
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
PLIST_SUB+=		GDBM=""
.else
CONFIGURE_ARGS+=	-Ui_gdbm
PLIST_SUB+=		GDBM="@comment "
.endif

.if defined(WITH_PERL_MALLOC)
CONFIGURE_ARGS+=	-Dusemymalloc=y
.else
CONFIGURE_ARGS+=	-Dusemymalloc=n
.endif

INCLUDEDIR=	/usr/include

.ifdef USE_PERL5
.error You have `USE_PERL5' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500043
PKGMESSAGE=	${PKGDIR}/.not-here
.endif

MAN1=	a2p.1 c2ph.1 dprofpp.1 find2perl.1 h2ph.1 h2xs.1 perl.1 \
	perl5004delta.1 perl5005delta.1 perlaix.1 perlamiga.1 \
	perlapi.1 perlapio.1 perlbook.1 perlboot.1 perlbot.1 \
	perlbs2000.1 perlbug.1 perlcall.1 perlcc.1 perlclib.1 \
	perlcompile.1 perlcygwin.1 perldata.1 perldbmfilter.1 \
	perldebguts.1 perldebtut.1 perldebug.1 perldelta.1 perldiag.1 \
	perldoc.1 perldos.1 perldsc.1 perlebcdic.1 perlembed.1 \
	perlepoc.1 perlfaq.1 perlfaq1.1 perlfaq2.1 perlfaq3.1 \
	perlfaq4.1 perlfaq5.1 perlfaq6.1 perlfaq7.1 perlfaq8.1 \
	perlfaq9.1 perlfilter.1 perlfork.1 perlform.1 perlfunc.1 \
	perlguts.1 perlhack.1 perlhist.1 perlhpux.1 perlintern.1 \
	perlipc.1 perllexwarn.1 perllocale.1 perllol.1 perlmachten.1 \
	perlmacos.1 perlmod.1 perlmodinstall.1 perlmodlib.1 \
	perlmpeix.1 perlnewmod.1 perlnumber.1 perlobj.1 perlop.1 \
	perlopentut.1 perlos2.1 perlos390.1 perlpod.1 perlport.1 \
	perlre.1 perlref.1 perlreftut.1 perlrequick.1 perlretut.1 \
	perlrun.1 perlsec.1 perlsolaris.1 perlstyle.1 perlsub.1 \
	perlsyn.1 perlthrtut.1 perltie.1 perltoc.1 perltodo.1 \
	perltoot.1 perltootc.1 perltrap.1 perlunicode.1 perlutil.1 \
	perlvar.1 perlvmesa.1 perlvms.1 perlvos.1 perlwin32.1 \
	perlxs.1 perlxstut.1 pl2pm.1 pod2html.1 pod2man.1 pod2text.1 \
	pod2usage.1 podchecker.1 podselect.1 pstruct.1 s2p.1 \
	splain.1 xsubpp.1

MAN3=	AnyDBM_File.3 AutoLoader.3 AutoSplit.3 B.3 B::Asmdata.3 \
	B::Assembler.3 B::Bblock.3 B::Bytecode.3 B::C.3 B::CC.3 \
	B::Concise.3 B::Debug.3 B::Deparse.3 B::Disassembler.3 \
	B::Lint.3 B::Showlex.3 B::Stackobj.3 B::Stash.3 B::Terse.3 \
	B::Xref.3 Benchmark.3 ByteLoader.3 CGI.3 CGI::Apache.3 \
	CGI::Carp.3 CGI::Cookie.3 CGI::Fast.3 CGI::Pretty.3 \
	CGI::Push.3 CGI::Switch.3 CGI::Util.3 CPAN.3 CPAN::FirstTime.3 \
	CPAN::Nox.3 Carp.3 Carp::Heavy.3 Class::Struct.3 Config.3 \
	Cwd.3 DB.3 DB_File.3 Data::Dumper.3 Devel::DProf.3 \
	Devel::Peek.3 Devel::SelfStubber.3 DirHandle.3 Dumpvalue.3 \
	DynaLoader.3 English.3 Env.3 Errno.3 Exporter.3 \
	Exporter::Heavy.3 ExtUtils::Command.3 ExtUtils::Embed.3 \
	ExtUtils::Install.3 ExtUtils::Installed.3 ExtUtils::Liblist.3 \
	ExtUtils::MM_Cygwin.3 ExtUtils::MM_OS2.3 ExtUtils::MM_Unix.3 \
	ExtUtils::MM_VMS.3 ExtUtils::MM_Win32.3 ExtUtils::MakeMaker.3 \
	ExtUtils::Manifest.3 ExtUtils::Miniperl.3 ExtUtils::Mkbootstrap.3 \
	ExtUtils::Mksymlists.3 ExtUtils::Packlist.3 ExtUtils::testlib.3 \
	Fatal.3 Fcntl.3 File::Basename.3 File::CheckTree.3 \
	File::Compare.3 File::Copy.3 File::DosGlob.3 File::Find.3 \
	File::Glob.3 File::Path.3 File::Spec.3 File::Spec::Epoc.3 \
	File::Spec::Functions.3 File::Spec::Mac.3 File::Spec::OS2.3 \
	File::Spec::Unix.3 File::Spec::VMS.3 File::Spec::Win32.3 \
	File::Temp.3 File::stat.3 FileCache.3 FileHandle.3 FindBin.3 \
	Getopt::Long.3 Getopt::Std.3 I18N::Collate.3 \
	IO.3 IO::Dir.3 IO::File.3 IO::Handle.3 IO::Pipe.3 IO::Poll.3 \
	IO::Seekable.3 IO::Select.3 IO::Socket.3 IO::Socket::INET.3 \
	IO::Socket::UNIX.3 IPC::Msg.3 IPC::Open2.3 IPC::Open3.3 \
	IPC::Semaphore.3 IPC::SysV.3 Math::BigFloat.3 Math::BigInt.3 \
	Math::Complex.3 Math::Trig.3 NDBM_File.3 Net::Ping.3 \
	Net::hostent.3 Net::netent.3 Net::protoent.3 Net::servent.3 \
	O.3 Opcode.3 POSIX.3 Pod::Checker.3 Pod::Find.3 Pod::Html.3 \
	Pod::InputObjects.3 Pod::LaTeX.3 Pod::Man.3 Pod::ParseUtils.3 \
	Pod::Parser.3 Pod::Plainer.3 Pod::Select.3 Pod::Text.3 \
	Pod::Text::Color.3 Pod::Text::Overstrike.3 Pod::Text::Termcap.3 \
	Pod::Usage.3 SDBM_File.3 Safe.3 Search::Dict.3 SelectSaver.3 \
	SelfLoader.3 Shell.3 Socket.3 Symbol.3 Sys::Hostname.3 \
	Sys::Syslog.3 Term::ANSIColor.3 Term::Cap.3 Term::Complete.3 \
	Term::ReadLine.3 Test.3 Test::Harness.3 Text::Abbrev.3 \
	Text::ParseWords.3 Text::Soundex.3 Text::Tabs.3 Text::Wrap.3 \
	Tie::Array.3 Tie::Handle.3 Tie::Hash.3 Tie::RefHash.3 \
	Tie::Scalar.3 Tie::SubstrHash.3 Time::Local.3 Time::gmtime.3 \
	Time::localtime.3 Time::tm.3 UNIVERSAL.3 User::grent.3 \
	User::pwent.3 Win32.3 XSLoader.3 attributes.3 attrs.3 \
	autouse.3 base.3 blib.3 bytes.3 charnames.3 constant.3 \
	diagnostics.3 fields.3 filetest.3 integer.3 less.3 lib.3 \
	locale.3 open.3 ops.3 overload.3 re.3 sigtrap.3 strict.3 \
	subs.3 utf8.3 vars.3 warnings.3 warnings::register.3
.if defined(WITH_GDBM)
MAN3+=	GDBM_File.3
.endif

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}

test:
	@(cd ${WRKSRC}; make test)

BSDPAN_DEST=	${PREFIX}/lib/perl5/${PERL_VER}/BSDPAN
BSDPAN_FILES=	BSDPAN.pm BSDPAN/Override.pm Config.pm \
		ExtUtils/MM_Unix.pm ExtUtils/Packlist.pm
BSDPAN_WRKSRC=	${WRKDIR}/BSDPAN-${PORTVERSION}
BSDPAN_REVISION=1

post-patch:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g;' \
		-e 's|%%PERL_VER%%|${PERL_VER}|g;' \
		-e 's|%%PERL_VERSION%%|${PERL_VERSION}|g;' \
		-e 's|%%PERL_ARCH%%|${PERL_ARCH}|g;' \
		${FILESDIR}/use.perl \
		> ${WRKDIR}/use.perl

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/perl ${PREFIX}/bin/suidperl
	@${LN} -sf ${PREFIX}/bin/perl ${PREFIX}/bin/perl5
	@${LN} -sf ${PREFIX}/bin/perl ${PREFIX}/bin/perl${PERL_VER}
	${INSTALL_SCRIPT} ${WRKDIR}/use.perl ${PREFIX}/bin/use.perl
.for file in ${BSDPAN_FILES}
	${MKDIR} ${BSDPAN_DEST}/${file:H}
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${NOBINMODE} \
		${BSDPAN_WRKSRC}/${file} ${BSDPAN_DEST}/${file}
.endfor
	@(cd ${INCLUDEDIR} && ${PREFIX}/bin/h2ph *.h machine/*.h sys/*.h)
.if ${OSVERSION} < 500043 || ${OSVERSION} > 502100
	@fmt ${PKGMESSAGE}
.else
	@${PREFIX}/bin/use.perl port
.endif

.include <bsd.port.post.mk>
