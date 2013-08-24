# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	ExtUtils-MakeMaker
PORTVERSION=	6.72
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Designed to write a Makefile for an extension module

USES=		perl5
USE_PERL5=	configure

MAN3=		ExtUtils::Command::MM.3 ExtUtils::Liblist.3 ExtUtils::MM.3 \
		ExtUtils::MM_AIX.3 ExtUtils::MM_Any.3 ExtUtils::MM_BeOS.3 \
		ExtUtils::MM_Cygwin.3 ExtUtils::MM_DOS.3 ExtUtils::MM_Darwin.3 \
		ExtUtils::MM_MacOS.3 ExtUtils::MM_NW5.3 ExtUtils::MM_OS2.3 \
		ExtUtils::MM_QNX.3 ExtUtils::MM_UWIN.3 ExtUtils::MM_Unix.3 \
		ExtUtils::MM_VMS.3 ExtUtils::MM_VOS.3 ExtUtils::MM_Win32.3 \
		ExtUtils::MM_Win95.3 ExtUtils::MY.3 ExtUtils::MakeMaker.3 \
		ExtUtils::MakeMaker::Config.3 ExtUtils::MakeMaker::FAQ.3 \
		ExtUtils::MakeMaker::Tutorial.3 ExtUtils::Mkbootstrap.3 \
		ExtUtils::Mksymlists.3 ExtUtils::testlib.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-ExtUtils-Manifest>=1.58:${PORTSDIR}/devel/p5-ExtUtils-Manifest \
		p5-version>=0.88:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-ExtUtils-Manifest>=1.58:${PORTSDIR}/devel/p5-ExtUtils-Manifest \
		p5-version>=0.88:${PORTSDIR}/devel/p5-version
.endif

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-CPAN-Meta>=2.113640:${PORTSDIR}/devel/p5-CPAN-Meta
RUN_DEPENDS+=	p5-CPAN-Meta>=2.113640:${PORTSDIR}/devel/p5-CPAN-Meta
.endif

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-CPAN-Meta-Requirements>=2.121:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements
RUN_DEPENDS+=	p5-CPAN-Meta-Requirements>=2.121:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements
.endif

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d; /my::bundles/d' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e '/^bundled\//d' ${WRKSRC}/MANIFEST
	@${RM} -fr ${WRKSRC}/bundled/
	@[ -e ${LOCALBASE}/lib/perl5/${PERL_VER}/mach/CORE/cc_runtime.h ] || \
		${SED} -i '' -e '/cc_runtime.h/d' ${WRKSRC}/lib/ExtUtils/MM_Unix.pm

.include <bsd.port.post.mk>
