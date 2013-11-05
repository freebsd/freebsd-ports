# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	ExtUtils-MakeMaker
PORTVERSION=	6.82
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Designed to write a Makefile for an extension module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-PP>=2.27203:${PORTSDIR}/converters/p5-JSON-PP
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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
	@${RM} ${WRKSRC}/lib/ExtUtils/MM_Unix.pm.orig

.include <bsd.port.post.mk>
