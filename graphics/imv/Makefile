PORTNAME=	imv
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.1
PORTREVISION=	2
CATEGORIES=	graphics wayland
MASTER_SITES=	https://git.sr.ht/~exec64/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple image viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libinih.so:devel/inih \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c11 desktop-file-utils gettext-runtime gl gnome meson \
		pkgconfig shebangfix
USE_GL=		egl
USE_GNOME=	cairo glib20 pango
SHEBANG_FILES=	contrib/imv-folder

CONFLICTS_INSTALL=	renameutils

OPTIONS_DEFINE=		FREEIMAGE HEIF JPEG NSGIF PNG SVG TEST TIFF
OPTIONS_DEFAULT=	ALL FREEIMAGE HEIF JPEG NSGIF PNG SVG TIFF
OPTIONS_SINGLE=		WIN
OPTIONS_SINGLE_WIN=	ALL WAYLAND X11
OPTIONS_SUB=		yes

ALL_DESC=	Both Wayland and X11 support
FREEIMAGE_DESC=	FreeImage backend (support for many image formats)
NSGIF_DESC=	NetSurf GIF backend (support for animated GIF)
WIN_DESC=	Windowing system

ALL_LIB_DEPENDS+=	libwayland-client.so:graphics/wayland
ALL_USES=		xorg
ALL_USE=		GL=glu \
			XORG=x11,xcb
ALL_MESON_ON=		-Dwindows=all

FREEIMAGE_LIB_DEPENDS=		libfreeimage.so:graphics/freeimage
FREEIMAGE_MESON_ENABLED=	freeimage

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_ENABLED=	libheif

JPEG_LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo
JPEG_MESON_ENABLED=	libjpeg

NSGIF_LIB_DEPENDS=	libnsgif.so:graphics/libnsgif
NSGIF_MESON_ENABLED=	libnsgif

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	libpng

SVG_USE=		GNOME=librsvg2
SVG_MESON_ENABLED=	librsvg

TEST_LIB_DEPENDS=	libcmocka.so:sysutils/cmocka
TEST_MESON_ENABLED=	test

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	libtiff

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-egl.so:graphics/wayland
WAYLAND_MESON_ON=	-Dwindows=wayland

X11_USES=	xorg
X11_USE=	GL=glu \
		XORG=x11,xcb
X11_MESON_ON=	-Dwindows=x11

post-patch:
	@${REINPLACE_CMD} -e 's|--sort=version|-V|g' ${WRKSRC}/contrib/imv-folder

.include <bsd.port.mk>
