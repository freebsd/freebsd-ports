PORTNAME=	imv
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	https://git.sr.ht/~exec64/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple image viewer
WWW=		https://sr.ht/~exec64/imv/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libinih.so:devel/inih \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	bash:shells/bash

USES=		desktop-file-utils gl gnome meson pkgconfig
USE_GL=		egl
USE_GNOME=	cairo pango

CONFLICTS_INSTALL=	renameutils

OPTIONS_DEFINE=		FREEIMAGE HEIF JPEG NSGIF PNG SVG TEST TIFF
OPTIONS_DEFAULT=	ALL FREEIMAGE HEIF JPEG PNG SVG TIFF
OPTIONS_SINGLE=		WIN
OPTIONS_SINGLE_WIN=	ALL WAYLAND X11
OPTIONS_SUB=		yes

ALL_DESC=	Both Wayland and X11 support
FREEIMAGE_DESC=	FreeImage backend (support for many image formats)
NSGIF_DESC=	NetSurf GIF backend (support for animated GIF)
WIN_DESC=	Windowing system

ALL_CATEGORIES=		wayland
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

NSGIF_BROKEN=		fails to build with libnsgif 1.0.0, see also https://lists.sr.ht/~exec64/imv-devel/%3CCAFDf7UKQCAO5VXqykRCnpHG6u0owdXRnk5kt0S3b-aTkpuF66Q%40mail.gmail.com%3E
NSGIF_LIB_DEPENDS=	libnsgif.so:graphics/libnsgif
NSGIF_MESON_ENABLED=	libnsgif

PNG_LIB_DEPENDS=	libpng16.so:graphics/png
PNG_MESON_ENABLED=	libpng

SVG_USE=		GNOME=librsvg2
SVG_MESON_ENABLED=	librsvg

TEST_LIB_DEPENDS=	libcmocka.so:sysutils/cmocka
TEST_MESON_ENABLED=	test

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	libtiff

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-egl.so:graphics/wayland
WAYLAND_MESON_ON=	-Dwindows=wayland

X11_USES=	xorg
X11_USE=	GL=glu \
		XORG=x11,xcb
X11_MESON_ON=	-Dwindows=x11

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' \
		${WRKSRC}/src/imv.c \
		${WRKSRC}/doc/imv.1.txt

.include <bsd.port.mk>
