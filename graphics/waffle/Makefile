# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	waffle
DISTVERSION=	1.6.0-7
CATEGORIES=	graphics

# Wayland xdg-shell support (to run on sway/wayfire/etc. that have removed wl-shell)
PATCH_SITES=	https://gitlab.freedesktop.org/oreaus/${PORTNAME}/commit/
PATCHFILES=	3cdce7b38cbd91cd7288e21940b279bf7ddc5757.diff:-p1

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library that allows to defer selection of an OpenGL API until runtime

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cmake:devel/cmake

USES=		compiler:c11 gl localbase meson pkgconfig python:3.5+,build
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_COMMIT=	b71cfa674db5828a2be04a42ce9996d6677629ee
USE_GL=		egl gl
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/waffle1
BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		DOCS GBM MANPAGES SURFACELESS WAYLAND X11
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

WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
			wayland-scanner:graphics/wayland
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_MESON_ENABLED=	wayland

X11_USES=		xorg
X11_USE=		XORG=x11,xcb
X11_MESON_ENABLED=	glx x11_egl

.include <bsd.port.mk>
