# Created by: Loïc BARTOLETTI <lbartoletti@FreeBSD.org>

PORTNAME=	sfcgal
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
CATEGORIES=	databases math graphics

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Wrapper library around CGAL for PostGIS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cgal>0:math/cgal
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake compiler:c++14-lang
USE_GITLAB=	yes
GL_ACCOUNT=	Oslandia
GL_PROJECT=	SFCGAL
GL_COMMIT=	2d6a1a89552f14fe2926038b7237686bb9e5472e
USE_LDCONFIG=	yes

PLIST_SUB=	SHL3=${PORTVERSION} SHL1=${PORTVERSION:R:R} DEBUG_SUFFIX=${WITH_DEBUG:Dd}

.include <bsd.port.mk>
