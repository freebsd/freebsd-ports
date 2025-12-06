PORTNAME=	xreader
PORTVERSION=	4.6.0
PORTREVISION=	1
CATEGORIES=	graphics print gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK multi-format document viewer
WWW=		https://github.com/linuxmint/xreader

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libxapp.so:x11/xapp \
		libpoppler-glib.so:graphics/poppler-glib

USES=		compiler:c11 desktop-file-utils gnome meson pkgconfig \
		python:build shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

SHEBANG_FILES=	install-scripts test

USE_XORG=	ice sm x11

USE_GNOME=	cairo gdkpixbuf gtk30 intltool libxml2
GLIB_SCHEMAS=	org.x.reader.gschema.xml

MESON_ARGS=	-Dmathjax-directory=${PREFIX}/www/MathJax \
		-Dpixbuf=true \
		-Dpdf=true
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^[0-9.]+$$	# ignore non-numeric tags

OPTIONS_DEFINE=	DBUS DOCS HELP INTROSPECTION KEYRING NLS PREVIEWER T1LIB \
		THUMBNAILER WAYLAND
OPTIONS_GROUP=	BACKENDS
OPTIONS_GROUP_BACKENDS=	COMICS DJVU DVI EPUB PS TIFF XPS
OPTIONS_DEFAULT=	COMICS DBUS DJVU EPUB HELP INTROSPECTION KEYRING PREVIEWER PS \
			THUMBNAILER TIFF WAYLAND XPS
OPTIONS_SUB=	yes
# https://github.com/linuxmint/xreader/pull/662
OPTIONS_EXCLUDE=	DOCS

COMICS_DESC=		Comic book archives support
DJVU_DESC=		DJVU support
DVI_DESC=		DVI viewer support
EPUB_DESC=		Epub support
HELP_DESC=		Install help files
INTROSPECTION_DESC=	Enable GObject Introspection
KEYRING_DESC=		Password-protected document support
PREVIEWER_DESC=		Print previewer support
T1LIB_DESC=		T1LIB for TYPE1 fonts to DVI (Enables DVI)
THUMBNAILER_DESC=	Thumbnailer support
XPS_DESC=		XPS support

COMICS_USES=		libarchive
COMICS_MESON_TRUE=	comics

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_TRUE=	enable_dbus

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre
DJVU_MESON_TRUE=	djvu

DVI_LIB_DEPENDS=	libspectre.so:print/libspectre
DVI_USE=		tex=kpathsea
DVI_MESON_TRUE=		dvi

EPUB_LIB_DEPENDS=	libwebkit2gtk-4.1.so:www/webkit2-gtk@41
EPUB_RUN_DEPENDS=	MathJax>0:www/mathjax
EPUB_MESON_TRUE=	epub

HELP_IMPLIES=		NLS
HELP_RUN_DEPENDS=	yelp>0:x11/yelp
HELP_MESON_TRUE=	help_files

INTROSPECTION_USE=	gnome=introspection:build
INTROSPECTION_MESON_TRUE=	introspection

KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret
KEYRING_MESON_TRUE=	keyring

NLS_USES=		gettext-tools

PREVIEWER_MESON_TRUE=	previewer

PS_LIB_DEPENDS=		libspectre.so:print/libspectre
PS_MESON_TRUE=		ps

T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_MESON_TRUE=	t1lib
T1LIB_IMPLIES=		DVI

THUMBNAILER_MESON_TRUE=	thumbnailer

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_TRUE=	tiff

XPS_LIB_DEPENDS=	libgxps.so:graphics/libgxps
XPS_MESON_TRUE=		xps

# XXX x11-toolkits/gtk30 built with WAYLAND disabled will not have <gdk/gdkwayland.h>
post-patch-WAYLAND-off:
	@${REINPLACE_CMD} -e '/gdkwayland/d' ${WRKSRC}/libdocument/ev-document-misc.h

.include <bsd.port.mk>
