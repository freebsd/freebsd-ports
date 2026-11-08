PORTNAME=	imv
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.1
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
		liblcms2.so:graphics/lcms2 \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	bash:shells/bash

USES=		desktop-file-utils gl gnome meson pkgconfig
USE_GL=		egl
USE_GNOME=	cairo pango

CONFLICTS_INSTALL=	renameutils

OPTIONS_DEFINE=		FF HEIF JPEG JXL NSBMP NSGIF PNG SVG TEST TIFF WEBP
OPTIONS_DEFAULT=	ALL HEIF JPEG JXL NSBMP NSGIF PNG SVG TIFF WEBP
OPTIONS_SINGLE=		WIN
OPTIONS_SINGLE_WIN=	ALL WAYLAND X11
OPTIONS_SUB=		yes

ALL_DESC=	Both Wayland and X11 support
FF_DESC=	Farbfeld support
NSBMP_DESC=	NetSurf BMP backend (support for BMP)
NSGIF_DESC=	NetSurf GIF backend (support for animated GIF)
WIN_DESC=	Windowing system

ALL_CATEGORIES=		wayland
ALL_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
ALL_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
ALL_USES=		xorg
ALL_USE=		GL=glu \
			XORG=x11,xcb
ALL_MESON_ON=		-Dwindows=all

FF_RUN_DEPENDS=		2ff:graphics/farbfeld
FF_MESON_ENABLED=	farbfeld

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_ENABLED=	libheif

JPEG_LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo
JPEG_MESON_ENABLED=	libjpeg

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_MESON_ENABLED=	libjxl

NSBMP_LIB_DEPENDS=	libnsbmp.so:graphics/libnsbmp
NSBMP_MESON_ENABLED=	libnsbmp

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
WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-egl.so:graphics/wayland
WAYLAND_MESON_ON=	-Dwindows=wayland

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MESON_ENABLED=	libwebp

X11_USES=	xorg
X11_USE=	GL=glu \
		XORG=x11,xcb
X11_MESON_ON=	-Dwindows=x11

# https://github.com/phoboslab/qoi is not yet ported
MESON_ARGS+=	-Dqoi=disabled

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' \
		${WRKSRC}/src/imv.c \
		${WRKSRC}/doc/imv.1.txt

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/imv_config ${STAGEDIR}${PREFIX}/etc/imv_config.sample

.include <bsd.port.mk>
