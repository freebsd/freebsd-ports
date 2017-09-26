# Created by: Eric Stith
# $FreeBSD$

PORTNAME=	Geo-Proj4
PORTVERSION=	1.06
CATEGORIES=	graphics devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Cartographic projections wrapper for Proj library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libproj.so:graphics/proj

CONFIGURE_ENV=	GEOPROJ_FWTOOLS_DIR=${LOCALBASE}
MAKE_ENV=	INC=-I${LOCALBASE}/include
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Geo/Proj4/Proj4.so

.include <bsd.port.mk>
