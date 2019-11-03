# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	rapidjson
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0-524
DISTVERSIONSUFFIX=	-gc4c6a654
CATEGORIES=	devel textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast JSON parser/generator for C++ with both SAX/DOM style API

LICENSE=	unknown
LICENSE_NAME=	RapidJSON
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	Tencent

USES=		cmake compiler:c++11-lang pathfix

NO_ARCH=	yes

CMAKE_OFF=	RAPIDJSON_BUILD_TESTS RAPIDJSON_BUILD_EXAMPLES

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_DEFAULT=${OPTIONS_DEFINE}
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	RAPIDJSON_BUILD_DOC

DATADIR=	${PREFIX}/share/doc/RapidJSON
PORTDATA=	*

CXXFLAGS+=	-Wno-error

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_INSTALL_DIR}/examples"|CMAKE_INSTALL_PREFIX}/share/examples/${PORTNAME}"| ; s| -march=native||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|.*travis.*||' ${WRKSRC}/CMakeLists.txt   # travis_doc breaks cmake: see https://github.com/miloyip/rapidjson/issues/715
	@${REINPLACE_CMD} -e 's|add_subdirectory.*googletest.*|link_directories(${LOCALBASE}/lib)|' ${WRKSRC}/test/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${EXAMPLESDIR}/CMake*

.include <bsd.port.mk>
