# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	rapidjson
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	5
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

CMAKE_OFF=	RAPIDJSON_BUILD_TESTS

OPTIONS_DEFINE=	DOXYGEN EXAMPLES
OPTIONS_DEFAULT=${OPTIONS_DEFINE}
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	RAPIDJSON_BUILD_DOC
EXAMPLES_CMAKE_BOOL=	RAPIDJSON_BUILD_EXAMPLES

DATADIR=	${PREFIX}/share/doc/RapidJSON
PORTDATA=	*

.include <bsd.port.pre.mk>

CXXFLAGS+=	-Wno-c++98-compat # for EXAMPLES option, due to this bug: https://github.com/miloyip/rapidjson/issues/761
CXXFLAGS_powerpc=	-Wno-error
CXXFLAGS_powerpcspe=	-Wno-error
CXXFLAGS_powerpc64=	-Wno-error
CXXFLAGS_sparc64=	-Wno-error
.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-zero-as-null-pointer-constant
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_INSTALL_DIR}/examples"|CMAKE_INSTALL_PREFIX}/share/examples/${PORTNAME}"| ; s| -march=native||' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/example/CMakeLists.txt ${WRKSRC}/test/unittest/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|.*travis.*||' ${WRKSRC}/CMakeLists.txt   # travis_doc breaks cmake, see https://github.com/miloyip/rapidjson/issues/715
	@${REINPLACE_CMD} -e 's|add_subdirectory.*googletest.*|link_directories(${LOCALBASE}/lib)|' ${WRKSRC}/test/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${EXAMPLESDIR}/CMake*

.include <bsd.port.post.mk>
