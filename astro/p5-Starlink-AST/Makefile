# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Starlink-AST
PORTVERSION=	1.05
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TJENNESS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to the Starlink AST library

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Astro-FITS-CFITSIO>=0:astro/p5-Astro-FITS-CFITSIO \
		p5-Astro-FITS-Header>=0:astro/p5-Astro-FITS-Header
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Number-Delta>=0:devel/p5-Test-Number-Delta

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Starlink/AST/AST.so

.include <bsd.port.mk>
