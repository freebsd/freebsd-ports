# $FreeBSD$

PORTNAME=	opensubdiv
DISTVERSIONPREFIX=	v
DISTVERSION=	3_3_3
CATEGORIES?=	graphics

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	High performance subdivision surface libraries

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	glfw>2.7.0:graphics/glfw

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenSubdiv

USE_GL=		gl glu glew
USE_LDCONFIG=	yes
CMAKE_ON=	NO_CUDA NO_DX NO_OMP

OPTIONS_DEFINE=		DOCS EXAMPLES OPENCL PTEX TBB TEST TUTORIALS
OPTIONS_DEFAULT=	TBB
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL_OFF=	NO_DOC
DOCS_BUILD_DEPENDS=	rst2html.py:textproc/py-docutils \
			doxygen>=1.8.4:devel/doxygen

EXAMPLES_CMAKE_BOOL_OFF=	NO_EXAMPLES
EXAMPLES_USE=		xorg=ice,sm,x11,xcursor,xext,xi,xinerama,xrandr,xxf86vm
EXAMPLES_LIB_DEPENDS=	libglfw.so:graphics/glfw

OPENCL_CMAKE_BOOL_OFF=	NO_OPENCL

OPENCL_CFLAGS=		-pthread
OPENCL_BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

PTEX_DESC=		ptex support
PTEX_CMAKE_BOOL_OFF=	NO_PTEX
PTEX_CMAKE_ON=		-DPTEX_LOCATION:STRING=${LOCALBASE} \
			-DPTEX_INCLUDE_DIR:STRING=${LOCALBASE}/include/ptex
PTEX_LIB_DEPENDS=	libPtex.so:graphics/ptex

TBB_DESC=		Intel threading building blocks
TBB_CMAKE_BOOL_OFF=	NO_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb

TEST_CMAKE_BOOL_OFF=	NO_REGRESSION NO_TESTS NO_GL_TESTS
TEST_LIB_DEPENDS=	libglfw.so:graphics/glfw
TEST_USE=		xorg=ice,sm,x11,xcursor,xext,xi,xinerama,xrandr,xxf86vm

TUTORIALS_DESC=		Install tutorial programs
TUTORIALS_CMAKE_BOOL_OFF=	NO_TUTORIALS

PLIST_SUB+=		LIBVERS=${PORTVERSION}

post-patch:
	${FIND} ${WRKSRC}/tutorials -name CMakeLists.txt -exec \
		${REINPLACE_CMD} -e 's|{CMAKE_BINDIR_BASE}/tutorials|{CMAKE_INSTALL_PREFIX}/${DATADIR_REL}/tutorials|g' {} +
	${FIND} ${WRKSRC}/examples -name CMakeLists.txt -exec \
		${REINPLACE_CMD} -e 's|{CMAKE_BINDIR_BASE}|{CMAKE_INSTALL_PREFIX}/${EXAMPLESDIR_REL}|g' {} +
	${FIND} ${WRKSRC}/regression -name CMakeLists.txt -exec \
		${REINPLACE_CMD} -e 's|{CMAKE_BINDIR_BASE}|{CMAKE_INSTALL_PREFIX}/tests/${PORTNAME}|g' {} +

.include <bsd.port.mk>
