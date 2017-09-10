# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	piglit
PORTVERSION=	20160809
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Automated OpenGL and OpenCL testsuite

LICENSE=	MIT GPLv2 GPLv3 LGPL20
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
LIB_DEPENDS=	libcaca.so:graphics/libcaca \
		libdrm.so:graphics/libdrm \
		libOpenCL.so:devel/ocl-icd \
		libpng.so:graphics/png \
		libwaffle-1.so:graphics/waffle
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

USE_GITHUB=	yes
GH_ACCOUNT=	dumbbell
GH_PROJECT=	piglit
GH_TAGNAME=	ca5350b4056ae63a93c4c207087b7634873b2ce2

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
