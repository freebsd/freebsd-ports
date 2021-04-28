PORTNAME=	imv
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple image viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libinih.so:devel/inih \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 desktop-file-utils gettext-runtime gl gnome \
		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	eXeC64
USE_GL=		gl
USE_GNOME=	cairo glib20 pango

PLIST_FILES=	bin/imv \
		bin/imv-msg \
		etc/imv_config \
		man/man1/imv-msg.1.gz \
		man/man1/imv.1.gz \
		man/man5/imv.5.gz \
		share/applications/imv.desktop

OPTIONS_DEFINE=		FREEIMAGE HEIF JPEG NSGIF PNG SVG TEST TIFF
OPTIONS_DEFAULT=	FREEIMAGE HEIF JPEG NSGIF PNG SVG TIFF ALL
OPTIONS_SINGLE=		WIN
OPTIONS_SINGLE_WIN=	WAYLAND X11 ALL
OPTIONS_SUB=		yes

FREEIMAGE_DESC=	FreeImage backend (support for many image formats)
HEIF_DESC=	HEIF backend
NSGIF_DESC=	NetSurf GIF backend (support for animated GIF)
WIN_DESC=	Windowing system

ALL_LIB_DEPENDS+=	libwayland-client.so:graphics/wayland
ALL_USES=	xorg
ALL_USE=	gl=egl,glu xorg=x11,xcb
ALL_MESON_ON=	-Dwindows=all
ALL_PLIST_FILES=	bin/imv-wayland \
			bin/imv-x11

FREEIMAGE_LIB_DEPENDS=	libfreeimage.so:graphics/freeimage
FREEIMAGE_MESON_ENABLED=freeimage

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

WAYLAND_USE=		gl=egl
WAYLAND_MESON_ON=	-Dwindows=wayland

X11_USES=	xorg
X11_USE=	gl=glu \
		xorg=x11,xcb
X11_MESON_ON=	-Dwindows=x11

.include <bsd.port.mk>
