# New ports collection makefile for:    ExtUtils-MakeMaker
# Date created:                         Mon Feb 23 00:13:01 EST 2004
# Whom:                                 Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-MakeMaker
PORTVERSION=	6.21
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Designed to write a Makefile for an extension module

PERL_CONFIGURE=	YES
CONFIGURE_ARGS=	INSTALLDIRS=site

MAN1=	instmodsh.1
MAN3=	ExtUtils::Installed.3 ExtUtils::MM_OS2.3 ExtUtils::MakeMaker.3 \
	ExtUtils::Install.3 ExtUtils::Manifest.3 ExtUtils::Command.3 \
	ExtUtils::MM_Unix.3 ExtUtils::Mksymlists.3 ExtUtils::MM.3 \
	ExtUtils::MM_Win32.3 ExtUtils::MM_UWIN.3 ExtUtils::testlib.3 \
	ExtUtils::MakeMaker::vmsish.3 ExtUtils::MY.3 ExtUtils::MM_DOS.3 \
	ExtUtils::MM_Cygwin.3 ExtUtils::MM_MacOS.3 ExtUtils::MM_Win95.3 \
	ExtUtils::MM_VMS.3 ExtUtils::MM_BeOS.3 ExtUtils::Liblist.3 \
	ExtUtils::MakeMaker::Tutorial.3 ExtUtils::Packlist.3 \
	ExtUtils::Mkbootstrap.3 ExtUtils::MakeMaker::FAQ.3 \
	ExtUtils::Command::MM.3 ExtUtils::MakeMaker::bytes.3 \
	ExtUtils::MM_NW5.3 ExtUtils::MM_Any.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/Pod/Man.pm:${PORTSDIR}/textproc/p5-podlators
RUN_DEPENDS+=	${BUILD_DEPENDS}
BROKEN=		"Broken pkg-plist"
.endif

.include <bsd.port.post.mk>
