# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	piglit
PORTVERSION=	20180910
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Automated OpenGL and OpenCL testsuite

LICENSE=	MIT GPLv2 GPLv3 LGPL20
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libcaca.so:graphics/libcaca \
		libdrm.so:graphics/libdrm \
		libOpenCL.so:devel/ocl-icd \
		libpng.so:graphics/png \
		libwaffle-1.so:graphics/waffle
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	dumbbell
GH_PROJECT=	piglit
GH_TAGNAME=	a0db4427446ab50882a721ae3084fa26cc9e751a

USES=		cmake compiler:c11 pkgconfig python:2.7 shebangfix
USE_GL=		egl gbm gl glu
USE_XORG=	x11 xcb xext xrender
SHEBANG_FILES=	piglit

CMAKE_ARGS+=	-DPIGLIT_BUILD_CL_TESTS:BOOL=ON

CMAKE_ARGS+=	-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/lib/piglit
PORTDATA=	*

OPTIONS_DEFINE=	DOCS WAYLAND
OPTIONS_DEFAULT=WAYLAND

WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon

post-patch-WAYLAND-off:
	@${REINPLACE_CMD} -e '/pkg_check_modules.*wayland/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
