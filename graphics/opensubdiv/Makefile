PORTNAME=	opensubdiv
DISTVERSIONPREFIX=	v
DISTVERSION=	3_6_0
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	High performance subdivision surface libraries
WWW=		https://graphics.pixar.com/opensubdiv

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	glfw>3.0.0:graphics/glfw

USES=		cmake gl localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenSubdiv

USE_GL=		opengl
USE_LDCONFIG=	yes
CMAKE_ON=	NO_CLEW NO_CUDA NO_DX NO_METAL

PLIST_SUB+=	LIBVERS=${PORTVERSION}

OPTIONS_DEFINE=		DOCS EXAMPLES OPENCL OPENMP PTEX TBB TEST TUTORIALS
OPTIONS_DEFAULT=	PTEX TBB
OPTIONS_DEFAULT_armv6=
OPTIONS_DEFAULT_armv7=
OPTIONS_DEFAULT_powerpc=
OPTIONS_DEFAULT_OTHER_ARCHS=	OPENMP
OPTIONS_SUB=		yes

PTEX_DESC=		ptex support
TBB_DESC=		Intel threading building blocks
TUTORIALS_DESC=		Install tutorial programs

DOCS_BUILD_DEPENDS=	rst2html:textproc/py-docutils \
			doxygen>=1.8.4:devel/doxygen
DOCS_USES=		python:build
DOCS_CMAKE_BOOL_OFF=	NO_DOC
DOCS_PORTDOCS=		*

EXAMPLES_LIB_DEPENDS=	libglfw.so:graphics/glfw
EXAMPLES_USES=		xorg
EXAMPLES_USE=		xorg=ice,sm,x11,xcursor,xext,xi,xinerama,xrandr,xxf86vm
EXAMPLES_CMAKE_BOOL_OFF=	NO_EXAMPLES

OPENCL_BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_USE=		gl=gl
OPENCL_CMAKE_BOOL_OFF=	NO_OPENCL
OPENCL_CFLAGS=		-pthread
OPENCL_LDFLAGS=		-lGLX

OPENMP_CMAKE_BOOL_OFF=	NO_OMP

PTEX_LIB_DEPENDS=	libPtex.so:graphics/ptex
PTEX_CMAKE_BOOL_OFF=	NO_PTEX
PTEX_CMAKE_ON=		-DPTEX_INCLUDE_DIR:STRING=${LOCALBASE}/include/ptex \
			-DPTEX_LOCATION:STRING=${LOCALBASE}

TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb
TBB_CMAKE_BOOL_OFF=	NO_TBB

TEST_LIB_DEPENDS=	libglfw.so:graphics/glfw
TEST_USES=		xorg
TEST_USE=		xorg=ice,sm,x11,xcursor,xext,xi,xinerama,xrandr,xxf86vm
TEST_CMAKE_BOOL_OFF=	NO_REGRESSION NO_TESTS

TUTORIALS_CMAKE_BOOL_OFF=	NO_TUTORIALS

post-patch:
	${FIND} ${WRKSRC}/tutorials -name CMakeLists.txt -exec \
		${REINPLACE_CMD} -e 's|{CMAKE_BINDIR_BASE}/tutorials|{CMAKE_INSTALL_PREFIX}/${DATADIR_REL}/tutorials|g' {} +
	${FIND} ${WRKSRC}/examples -name CMakeLists.txt -exec \
		${REINPLACE_CMD} -e 's|{CMAKE_BINDIR_BASE}|{CMAKE_INSTALL_PREFIX}/${EXAMPLESDIR_REL}|g' {} +
	${FIND} ${WRKSRC}/regression -name CMakeLists.txt -exec \
		${REINPLACE_CMD} -e 's|{CMAKE_BINDIR_BASE}|{CMAKE_INSTALL_PREFIX}/tests/${PORTNAME}|g' {} +

.include <bsd.port.mk>
