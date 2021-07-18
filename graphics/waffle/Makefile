# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>

PORTNAME=	waffle
DISTVERSION=	1.6.1-15
PORTREVISION=	1
CATEGORIES=	graphics

# Wayland xdg-shell support (to run on sway/wayfire/etc. that have removed wl-shell)
PATCH_SITES=	https://gitlab.freedesktop.org/bl4ckb0ne/${PORTNAME}/-/commit/
PATCHFILES=	39ad2b26f46e90cbae13a9cbc58e1f9df03f0980.patch:-p1 \
		e4a1e7e9670b77d5b145520d60c4b7570fe3c6ea.patch:-p1 \
		8c202f88ab4f0f851e3f19dd82bc6b5236120564.patch:-p1


MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library that allows to defer selection of an OpenGL API until runtime

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	cmake:devel/cmake

USES=		compiler:c11 gl localbase meson pkgconfig python:3.5+,build
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_COMMIT=	2485a41c321a29463b5c0af7813c2d1046e2f925
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
