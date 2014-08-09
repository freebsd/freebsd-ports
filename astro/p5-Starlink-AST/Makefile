# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Starlink-AST
PORTVERSION=	1.04
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TJENNESS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to the Starlink AST library

BUILD_DEPENDS=	p5-Test-Number-Delta>=0:${PORTSDIR}/devel/p5-Test-Number-Delta \
		p5-Astro-FITS-CFITSIO>=0:${PORTSDIR}/astro/p5-Astro-FITS-CFITSIO \
		p5-Astro-FITS-Header>=0:${PORTSDIR}/astro/p5-Astro-FITS-Header
RUN_DEPENDS=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

post-stage:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Starlink/AST/AST.so
	${RM} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Starlink/AST/AST.bs

.include <bsd.port.mk>
