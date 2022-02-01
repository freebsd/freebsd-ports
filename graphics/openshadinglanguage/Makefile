PORTNAME=	openshadinglanguage
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.17.0
CATEGORIES?=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT?=	Advanced shading language for production GI renderers

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_FreeBSD_12_powerpc64=	fails to compile: llvm_ops.cpp:101:10: fatal error: 'iostream' file not found
BROKEN_riscv64=		fails to build: /usr/include/c++/v1/__threading_support:135:3: Unsupported architecture

BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

USES=		bison cmake compiler:c++14-lang localbase ncurses qt:5

USE_QT=		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	OpenShadingLanguage

CMAKE_ON=	ENABLERTTI OSL_BUILD_TESTS USE_LLVM_BITCODE USE_LIBCPLUSPLUS
CMAKE_OFF=	USE_BOOST_WAVE
CMAKE_ARGS+=	-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config${LLVM_VER}" \
		-DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR} -DCMAKE_CXX_STANDARD=14
# This flag fixes linking with clang 9.0 ??
CXXFLAGS+=	-DNDEBUG

OPTIONS_DEFINE=		MATERIALX OSLTOY
OPTIONS_SUB=		yes

MATERIALX_DESC=		Install material library
MATERIALX_CMAKE_BOOL=	OSL_BUILD_MATERIALX

OSLTOY_DESC=		Interactive shader edit and visualize tool
OSLTOY_CMAKE_BOOL=	USE_QT
OSLTOY_USE=		QT=buildtools_build,core,gui,qmake_build,widgets

#CXXFLAGS+=	-I${STAGEDIR}/include

# DISTVERSION has an extra digit which isn't in the lib name
# for LIBVERS we want the first three digits
PLIST_SUB=	SHL3=${PORTVERSION:R} SHL2=${PORTVERSION:R:R}

.include <bsd.port.options.mk>

.if ${LLVM_DEFAULT:M[678]0}
LLVM_VER=	90
.else
LLVM_VER=	${LLVM_DEFAULT}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
		-e 's,%%PYCMD%%,${PYTHON_CMD},' \
		${WRKSRC}/src/shaders/CMakeLists.txt \
		${WRKSRC}/src/shaders/MaterialX/CMakeLists.txt \
		${WRKSRC}/src/doc/CMakeLists.txt \
		${WRKSRC}/src/liboslexec/CMakeLists.txt

.if ${SLAVE_PORT} == yes
BUILD_DEPENDS+=	${PREFIX}/share/cmake/pybind11/pybind11Config.cmake:devel/pybind11
LIB_DEPENDS+=	liboslquery.so:graphics/openshadinglanguage
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openimageio>0:graphics/py-openimageio@${PY_FLAVOR}
PLIST=		${PKGDIR}/pkg-plist-pybind
USES+=		python
USE_PYTHON=	flavors
CMAKE_ON+=	USE_PYTHON
CMAKE_ARGS+=	-DPYTHON_VERSION=${PYTHON_VER}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/python/site-packages/oslquery.so ${STAGEDIR}${PYTHON_SITELIBDIR}
.else # SLAVE_PORT != yes
USES+=		python:build
BINARY_ALIAS+=	python=${PYTHON_CMD}
CMAKE_OFF+=	USE_PYTHON
USE_LDCONFIG=	yes
.endif # SLAVE_PORT

.include <bsd.port.mk>
