# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	piglit
PORTVERSION=	20170922
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
GH_TAGNAME=	60996b829c85f3df192bc6228108c0a8eaa38afd

USES=		cmake:outsource compiler:c11 pkgconfig python:2
USE_GL=		egl gbm gl glu
USE_XORG=	x11 xcb xext xrender

CMAKE_ARGS+=	-DPIGLIT_BUILD_CL_TESTS:BOOL=ON

CMAKE_ARGS+=	-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/lib/piglit
PORTDATA=	*

.include <bsd.port.mk>
