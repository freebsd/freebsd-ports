PORTNAME=	waffle
DISTVERSIONPREFIX=v
DISTVERSION=	1.8.1
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library that allows to defer selection of an OpenGL API until runtime
WWW=		https://www.waffle-gl.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${LOCALBASE}/lib/dri/swrast_dri.so:graphics/mesa-dri

USES=		cmake:indirect compiler:c11 gl localbase meson pkgconfig \
		python:build display:test
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
USE_GL=		egl gl
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/waffle1
BINARY_ALIAS=	python3=${PYTHON_CMD}

TESTING_UNSAFE=	Requires DRM device under /dev/, running X server, running Wayland compositor

OPTIONS_DEFINE=		DOCS GBM MANPAGES SURFACELESS TEST WAYLAND X11
OPTIONS_DEFAULT=	GBM MANPAGES SURFACELESS WAYLAND X11
OPTIONS_SUB=		yes

GBM_DESC=		GBM/DRM/KMS direct-on-hardware support
SURFACELESS_DESC=	Surfaceless EGL support

GBM_LIB_DEPENDS=	libudev.so:devel/libudev-devd
GBM_USE=		GL=gbm
GBM_MESON_ENABLED=	gbm

MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl
MANPAGES_USES=		gnome
MANPAGES_USE=		GNOME=libxslt:build
MANPAGES_MESON_TRUE=	build-manpages

SURFACELESS_MESON_ENABLED=	surfaceless_egl

TEST_LIB_DEPENDS=	libcmocka.so:sysutils/cmocka
TEST_MESON_TRUE=	build-tests

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
			wayland-scanner:graphics/wayland
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_MESON_ENABLED=	wayland

X11_USES=		xorg
X11_USE=		XORG=x11,xcb
X11_MESON_ENABLED=	glx x11_egl

.include <bsd.port.mk>
