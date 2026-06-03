PORTNAME=	piglit
PORTVERSION=	20260502
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Automated OpenGL and OpenCL testsuite
WWW=		https://piglit.freedesktop.org/

LICENSE=	MIT GPLv2 GPLv3 LGPL20
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy1>=1.16:math/py-numpy1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers \
		wayland-protocols>=0:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libvulkan.so:graphics/vulkan-loader \
		libwaffle-1.so:graphics/waffle \
		libwayland-egl.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy1>=1.16:math/py-numpy1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		cmake compiler:c11 gl pkgconfig python shebangfix xorg
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_PROJECT=	piglit
GL_TAGNAME=	0730373391be9a944a16a2a975871c0e740c45f0
USE_GL=		egl gbm gl glu
USE_XORG=	x11 xcb xext xrender
SHEBANG_FILES=	piglit replayer/replayer.py

CMAKE_ON=	PIGLIT_BUILD_GLES2_TESTS PIGLIT_BUILD_GLES3_TESTS
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

DATADIR=	${PREFIX}/lib/piglit
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
