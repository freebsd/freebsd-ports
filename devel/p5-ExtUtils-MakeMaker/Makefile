# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	ExtUtils-MakeMaker
PORTVERSION=	7.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Designed to write a Makefile for an extension module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-CPAN-Meta>=0:devel/p5-CPAN-Meta

CONFLICTS=	p5-ExtUtils-Command-[0-9]*

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-ExtUtils-Manifest>=1.70:devel/p5-ExtUtils-Manifest
RUN_DEPENDS+=	p5-ExtUtils-Manifest>=1.70:devel/p5-ExtUtils-Manifest
.endif

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d; /my::bundles/d' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e '/^bundled\//d' ${WRKSRC}/MANIFEST
	@${RM} -fr ${WRKSRC}/bundled/

.include <bsd.port.post.mk>
