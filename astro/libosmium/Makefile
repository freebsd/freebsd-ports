# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libosmium
PORTVERSION=	2.16.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast and flexible C++ library for working with OpenStreetMap data

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libboost_regex.so:devel/boost-libs \
		libgeos.so:graphics/geos \
		libexpat.so:textproc/expat2
BUILD_DEPENDS=	sparsehash>=0:devel/sparsehash \
		${LOCALBASE}/include/protozero/version.hpp:devel/protozero
RUN_DEPENDS=	${LOCALBASE}/include/protozero/version.hpp:devel/protozero

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	osmcode

CMAKE_ARGS=	-DBUILD_EXAMPLES:BOOL=OFF

# if/when corresponding port appears in the tree, this will need to
# be turned into dependency
CMAKE_ARGS+=	-DINSTALL_GDALCPP:BOOL=ON
CXXFLAGS+=	"-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1"

# although it builds tests the library itself is header-only
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	TEST DOCS
OPTIONS_DEFAULT=	TEST
TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	BUILD_TESTING

post-extract:
	@${RM} -rf ${WRKSRC}/include/utf8*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
