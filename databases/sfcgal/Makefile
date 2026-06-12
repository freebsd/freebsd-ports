PORTNAME=	sfcgal
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	databases math graphics
MASTER_SITES=	https://github.com/CGAL/cgal/releases/download/v${CGAL_VERSION}/:source1
DISTFILES=	CGAL-${CGAL_VERSION}.tar.xz:source1

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Wrapper library around CGAL for PostGIS
WWW=		https://oslandia.gitlab.io/SFCGAL/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3.0.0:devel/nlohmann-json
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		cmake compiler:c++17-lang eigen:3
USE_GITLAB=	yes
GL_ACCOUNT=	SFCGAL
GL_PROJECT=	SFCGAL
USE_LDCONFIG=	yes

CGAL_VERSION=	6.1.2
PLIST_SUB=	SHL3=${PORTVERSION} SHL1=${PORTVERSION:R:R} DEBUG_SUFFIX=${WITH_DEBUG:Dd}

CMAKE_ARGS+=	-DCGAL_DIR=${WRKDIR}/CGAL-${CGAL_VERSION} -DSFCGAL_BUILD_CLI=ON

.include <bsd.port.mk>
