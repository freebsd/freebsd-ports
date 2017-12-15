# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	rapidjson
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel textproc

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fast JSON parser/generator for C++ with both SAX/DOM style API

LICENSE=	unknown
LICENSE_NAME=	RapidJSON
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_armv7=		does not build: include/rapidjson/internal/../allocators.h:128:36: error: zero as null pointer constant

USE_GITHUB=	yes
GH_ACCOUNT=	miloyip

USES=		cmake compiler:c++11-lang pathfix

OPTIONS_DEFINE=	DOXYGEN EXAMPLES
OPTIONS_DEFAULT=${OPTIONS_DEFINE}
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	RAPIDJSON_BUILD_DOC
EXAMPLES_CMAKE_BOOL=	RAPIDJSON_BUILD_EXAMPLES

CXXFLAGS+=	-Wno-c++98-compat # for EXAMPLES option, due to this bug: https://github.com/miloyip/rapidjson/issues/761
CMAKE_ARGS=	-DRAPIDJSON_BUILD_TESTS:BOOL=OFF

DATADIR=	${PREFIX}/share/doc/RapidJSON
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_INSTALL_DIR}/examples"|CMAKE_INSTALL_PREFIX}/share/examples/${PORTNAME}"| ; s| -march=native||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/example/CMakeLists.txt ${WRKSRC}/test/unittest/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|.*travis.*||' ${WRKSRC}/CMakeLists.txt   # travis_doc breaks cmake, see https://github.com/miloyip/rapidjson/issues/715
	@${REINPLACE_CMD} -e 's|add_subdirectory.*googletest.*|link_directories(${LOCALBASE}/lib)|' ${WRKSRC}/test/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${EXAMPLESDIR}/CMake*

.include <bsd.port.mk>
