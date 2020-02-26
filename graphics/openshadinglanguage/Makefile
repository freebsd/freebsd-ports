# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openshadinglanguage
DISTVERSIONPREFIX=	Release-
DISTVERSION=	1.10.9
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Advanced shading language for production GI renderers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libImath.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libpugixml.so:textproc/pugixml
RUN_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

USES=		bison cmake compiler:c++11-lang ncurses python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenShadingLanguage

# Use LLVM linker where available
.if exists(/usr/bin/ld.lld) && (${/usr/bin/ld:L:tA} != /usr/bin/ld.lld)
LDFLAGS+=	-fuse-ld=lld
.endif

LLVM_VER=	90
CMAKE_ON=	ENABLERTTI OSL_BUILD_TESTS USE_LLVM_BITCODE USE_LIBCPLUSPLUS
CMAKE_OFF=	USE_BOOST_WAVE
CMAKE_ARGS+=	-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config${LLVM_VER}" \
		-DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR}
# This flag fixes linking with clang 9.0 ??
CXXFLAGS+=	-DNDEBUG

OPTIONS_DEFINE=		OSLTOY
OPTIONS_SUB=		yes
OSLTOY_DESC=		Interactive shader edit and visualize tool
OSLTOY_CMAKE_BOOL=	USE_QT
OSLTOY_USES=		qt:5
OSLTOY_USE=		QT=buildtools,core,gui,qmake_build,widgets

CXXFLAGS+=	-I${STAGEDIR}/include

PLIST_SUB+=	LIBVERS=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's,bash,sh,' \
		${WRKSRC}/src/liboslexec/serialize-bc.bash
	@${REINPLACE_CMD} -e 's,%%DATADIR%%,${DATADIR},' \
		-e 's,%%PYCMD%%,${PYTHON_CMD},' \
		${WRKSRC}/src/shaders/CMakeLists.txt \
		${WRKSRC}/src/shaders/MaterialX/CMakeLists.txt \
		${WRKSRC}/src/doc/CMakeLists.txt

.include <bsd.port.mk>
