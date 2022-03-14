PORTNAME=	libosmium
DISTVERSIONPREFIX=	v
DISTVERSION=	2.18.0
CATEGORIES=	astro geography devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast and flexible C++ library for working with OpenStreetMap data

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs \
		protozero>=0:devel/protozero \
		gdal>=0:graphics/gdal \
		protozero>=0:devel/protozero \
		expat>=0:textproc/expat2 \
		liblz4>=0:archivers/liblz4 \
		geos>=0:graphics/geos
#		proj>=0:graphics/proj

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	osmcode
CMAKE_ON=	INSTALL_GDALCPP  # until it appears as a port
CMAKE_ON+=	BUILD_HEADERS
CMAKE_OFF=	BUILD_EXAMPLES
CMAKE_OFF+=	WITH_PROJ  # the ports version is not supported

# although it builds tests the library itself is header-only
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	TEST DOCS
OPTIONS_DEFAULT=	TEST
TEST_TEST_TARGET=	test
TEST_CMAKE_BOOL=	BUILD_TESTING

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name "*.cpp" -o -name "*.hpp" \) \
		-not -name "memory_mapping.hpp" \
		-not -name "test_memory_mapping.cpp" \
		-not -name "test_memory.cpp" \
		-exec ${REINPLACE_CMD} \
			-e 's,^#ifdef __linux__,#if defined(__linux__) || defined(__FreeBSD__),' \
			-e 's,^#ifndef __linux__,#if !defined(__linux__) && !defined(__FreeBSD__),' {} \;

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
