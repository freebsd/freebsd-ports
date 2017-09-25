# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libosmium
PORTVERSION=	2.13.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast and flexible C++ library for working with OpenStreetMap data

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libboost_regex.so:devel/boost-libs \
		libgeos.so:graphics/geos \
		libexpat.so:textproc/expat2
BUILD_DEPENDS=	sparsehash>=0:devel/sparsehash \
		${LOCALBASE}/include/utf8.h:devel/utf8cpp
RUN_DEPENDS=	${LOCALBASE}/include/utf8.h:devel/utf8cpp

BROKEN_powerpc64=	fails to compile: types_from_string.hpp: error: 'strtoll' is not a member of 'std'

USE_GITHUB=	yes
GH_ACCOUNT=	osmcode

USES=		cmake compiler:c++11-lib
CMAKE_ARGS=	-DBUILD_EXAMPLES:BOOL=OFF

# if/when corresponding ports appear in the tree, these will need to
# be turned from depends
CMAKE_ARGS+=	-DINSTALL_GDALCPP:BOOL=ON \
		-DINSTALL_PROTOZERO:BOOL=ON

# though it builds tests, the library itself is header-only
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
