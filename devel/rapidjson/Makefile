# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	rapidjson
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel textproc

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fast JSON parser/generator for C++ with both SAX/DOM style API

LICENSE=	unknown
LICENSE_NAME=	RapidJSON
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

BROKEN_powerpc64=	Does not build

DOXYGEN_BUILD_DEPENDS+=	doxygen:devel/doxygen

USE_GITHUB=	yes
GH_ACCOUNT=	miloyip

USES=		cmake compiler:c++11-lang pathfix

OPTIONS_DEFINE=	DOXYGEN EXAMPLES
OPTIONS_DEFAULT=${OPTIONS_DEFINE}
OPTIONS_SUB=	yes

DOXYGEN_CMAKE_ON=	-DRAPIDJSON_BUILD_DOC:BOOL=ON
DOXYGEN_CMAKE_OFF=	-DRAPIDJSON_BUILD_DOC:BOOL=OFF
EXAMPLES_CMAKE_ON=	-DRAPIDJSON_BUILD_EXAMPLES:BOOL=ON
EXAMPLES_CMAKE_OFF=	-DRAPIDJSON_BUILD_EXAMPLES:BOOL=OFF

CXXFLAGS+=	-Wno-c++98-compat # for EXAMPLES option, due to this bug: https://github.com/miloyip/rapidjson/issues/761
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"
CMAKE_ARGS=	-DRAPIDJSON_BUILD_TESTS:BOOL=OFF

DATADIR=	${PREFIX}/share/doc/RapidJSON
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_INSTALL_DIR}/examples"|CMAKE_INSTALL_PREFIX}/share/examples/${PORTNAME}"|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/example/CMakeLists.txt ${WRKSRC}/test/unittest/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|.*travis.*||' ${WRKSRC}/CMakeLists.txt   # travis_doc breaks cmake, see https://github.com/miloyip/rapidjson/issues/715
	@${REINPLACE_CMD} -e 's|add_subdirectory.*googletest.*|link_directories(${LOCALBASE}/lib)|' ${WRKSRC}/test/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${EXAMPLESDIR}/CMake*

.include <bsd.port.mk>
