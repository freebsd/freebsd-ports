# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	imv
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple image viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libxkbcommon.so:x11/libxkbcommon
TEST_DEPENDS=	${LOCALBASE}/lib/libcmocka.so:sysutils/cmocka

USES=		compiler:c11 desktop-file-utils gettext-runtime gl gmake gnome \
		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	eXeC64
USE_GL=		gl
USE_GNOME=	cairo glib20 pango

MAKE_ARGS=	CONFIGPREFIX=${PREFIX}/etc \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		MANPREFIX=${PREFIX}/man \
		V=1 \
		WINDOWS=${_IMV_WINDOWS}
ALL_TARGET=	imv doc
TEST_TARGET=	check

PLIST_FILES=	bin/imv \
		bin/imv-msg \
		etc/imv_config \
		man/man1/imv-msg.1.gz \
		man/man1/imv.1.gz \
		man/man5/imv.5.gz \
		share/applications/imv.desktop

OPTIONS_DEFINE=		FREEIMAGE JPEG NSGIF PNG SVG TIFF
OPTIONS_DEFAULT=	FREEIMAGE JPEG NSGIF PNG SVG TIFF WAYLAND X11
OPTIONS_MULTI=		WINDOWS
OPTIONS_MULTI_WINDOWS=	WAYLAND X11
OPTIONS_SUB=		yes

FREEIMAGE_DESC=	FreeImage backend (support for many image formats)
NSGIF_DESC=	NetSurf GIF backend (support for animated GIF)
WINDOWS_DESC=	Windowing system

FREEIMAGE_LIB_DEPENDS=		libfreeimage.so:graphics/freeimage
FREEIMAGE_MAKE_ARGS_OFF=	BACKEND_FREEIMAGE=no
FREEIMAGE_MAKE_ARGS=		BACKEND_FREEIMAGE=yes

JPEG_LIB_DEPENDS=	libturbojpeg.so:graphics/libjpeg-turbo
JPEG_MAKE_ARGS_OFF=	BACKEND_LIBJPEG=no
JPEG_MAKE_ARGS=		BACKEND_LIBJPEG=yes

NSGIF_LIB_DEPENDS=	libnsgif.so:graphics/libnsgif
NSGIF_MAKE_ARGS_OFF=	BACKEND_LIBNSGIF=no
NSGIF_MAKE_ARGS=	BACKEND_LIBNSGIF=yes

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MAKE_ARGS_OFF=	BACKEND_LIBPNG=no
PNG_MAKE_ARGS=		BACKEND_LIBPNG=yes

SVG_USE=		GNOME=librsvg2
SVG_MAKE_ARGS_OFF=	BACKEND_LIBRSVG=no
SVG_MAKE_ARGS=		BACKEND_LIBRSVG=yes

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MAKE_ARGS_OFF=	BACKEND_LIBTIFF=no
TIFF_MAKE_ARGS=		BACKEND_LIBTIFF=yes

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-egl.so:graphics/wayland
WAYLAND_USE=		GL=egl
WAYLAND_VARS=		_IMV_WINDOWS=wayland

X11_USES=	xorg
X11_USE=	GL=glu \
		XORG=x11,xcb
X11_VARS=	_IMV_WINDOWS=x11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWAYLAND} && ${PORT_OPTIONS:MX11}
_IMV_WINDOWS=	all
PLIST_FILES+=	bin/imv-wayland \
		bin/imv-x11
.endif

.include <bsd.port.mk>
