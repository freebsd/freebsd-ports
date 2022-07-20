PORTNAME=	piglit
PORTVERSION=	20200910
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Automated OpenGL and OpenCL testsuite

LICENSE=	MIT GPLv2 GPLv3 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		vulkan-headers>0:graphics/vulkan-headers \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libvulkan.so:graphics/vulkan-loader \
		libwaffle-1.so:graphics/waffle \
		libwayland-egl.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_PROJECT=	piglit
GL_COMMIT=	136a7f5fa0703603be1ffb338abe4865e76a8058

PATCH_SITES=		https://gitlab.freedesktop.org/mesa/piglit/-/commit/
PATCH_DIST_STRIP=	-p1
PATCHFILES+=		7f1916da04fc.patch # https://gitlab.freedesktop.org/mesa/piglit/-/merge_requests/383
PATCHFILES+=		c6a4d8aa8e68.patch # https://gitlab.freedesktop.org/mesa/piglit/-/merge_requests/383
PATCHFILES+=		0443b6a18648.patch # https://gitlab.freedesktop.org/mesa/piglit/-/merge_requests/383
PATCHFILES+=		96d8ddd0a658.patch # https://gitlab.freedesktop.org/mesa/piglit/-/merge_requests/383
PATCHFILES+=		d5f4cfd3b0da.patch # https://gitlab.freedesktop.org/mesa/piglit/-/merge_requests/383
PATCHFILES+=		64c468c6c7e3.patch # https://gitlab.freedesktop.org/mesa/piglit/-/merge_requests/383
PATCHFILES+=		681e86f53c2e.patch # https://gitlab.freedesktop.org/mesa/piglit/-/merge_requests/383

USES=		cmake compiler:c11 gl pkgconfig python:3.5+ shebangfix xorg
USE_GL=		egl gbm gl glu
USE_XORG=	x11 xcb xext xrender
SHEBANG_FILES=	piglit

CMAKE_ON=	PIGLIT_BUILD_GLES2_TESTS PIGLIT_BUILD_GLES3_TESTS
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/lib/piglit
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
