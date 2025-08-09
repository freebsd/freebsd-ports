PORTNAME=	openshadinglanguage
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.12.0
# PORTREVISION must be set with ?= so as not to stomp over
# py-openimageio's PORTREVISION.
# Also, just to be on the safe side, when resetting,
# best keep PORTREVISION?=	0.
PORTREVISION?=	3
CATEGORIES?=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT?=	Advanced shading language for production GI renderers
WWW=		https://github.com/AcademySoftwareFoundation/OpenShadingLanguage

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_riscv64=	fails to build: /usr/include/c++/v1/__threading_support:135:3: Unsupported architecture

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	fails static_assert(sizeof(ustringhash) == sizeof(size_t)

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libpartio.so:graphics/partio \
		libpugixml.so:textproc/pugixml

USES=		bison cmake compiler:c++17-lang llvm:lib localbase ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	OpenShadingLanguage

CMAKE_ARGS+=	-DCMAKE_CXX_STANDARD:INTEGER=17 -DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR} \
		-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config${LLVM_VERSION}"
CMAKE_ON=	ENABLE_RTTI OSL_BUILD_TESTS USE_LIBCPLUSPLUS USE_LLVM_BITCODE

# DISTVERSION has an extra digit which isn't in the lib name
# for LIBVERS we want the first three digits
PLIST_SUB=	SHL2=${DISTVERSION:R:R} SHL3=${DISTVERSION:R}

OPTIONS_DEFINE=		OSLTOY
OPTIONS_SUB=		yes

OSLTOY_DESC=		Interactive shader edit and visualize tool
OSLTOY_USES=		qt:6 gl
OSLTOY_USE=		GL=gl,opengl QT=base
OSLTOY_CMAKE_BOOL=	USE_QT

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
		-e 's,%%PYCMD%%,${PYTHON_CMD},' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/src/shaders/CMakeLists.txt \
		${WRKSRC}/src/doc/CMakeLists.txt \
		${WRKSRC}/src/liboslexec/CMakeLists.txt

.if ${SLAVE_PORT} == yes
BUILD_DEPENDS+=	${PREFIX}/share/cmake/pybind11/pybind11Config.cmake:devel/pybind11
LIB_DEPENDS+=	liboslquery.so:graphics/openshadinglanguage
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openimageio>0:graphics/py-openimageio@${PY_FLAVOR}
USES+=		python
USE_PYTHON=	flavors
CMAKE_ARGS+=	-DPYTHON_VERSION=${PYTHON_VER}
CMAKE_ON+=	USE_PYTHON
PLIST=		${PKGDIR}/pkg-plist-pybind

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/python/site-packages/oslquery.so ${STAGEDIR}${PYTHON_SITELIBDIR}
.else # SLAVE_PORT != yes
# using python:env as this port doesn't need to use python
# a python util script is installed for user consumption
# it is not required for using the port, only to assist developers using the libs
USES+=		python:build shebangfix
USE_LDCONFIG=	yes
CMAKE_OFF+=	USE_PYTHON
BINARY_ALIAS+=	python=${PYTHON_CMD}
SHEBANG_FILES+=	src/build-scripts/serialize-bc.py
.endif # SLAVE_PORT

.include <bsd.port.mk>
