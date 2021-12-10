# Created by: Loïc BARTOLETTI <lbartoletti@FreeBSD.org>

PORTNAME=	sfcgal
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
PORTREVISION=	1
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
GL_COMMIT=	815d5097f684dbc48b22041bf2047beab36df0a1
USE_LDCONFIG=	yes

PLIST_SUB=	SHL3=${PORTVERSION} SHL1=${PORTVERSION:R:R} DEBUG_SUFFIX=${WITH_DEBUG:Dd}

.include <bsd.port.mk>
