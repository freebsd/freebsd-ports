# New ports collection makefile for:    ExtUtils-MakeMaker
# Date created:                         Mon Feb 23 00:13:01 EST 2004
# Whom:                                 Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-MakeMaker
PORTVERSION=	6.25
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
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

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.if ${PERL_LEVEL} >= 500800
.undef MAN1
PLIST_SUB+=	EXE_FILES="@comment "
.else
PLIST_SUB+=	EXE_FILES=""
.endif

post-patch:
.if ${PERL_LEVEL} >= 500800
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
