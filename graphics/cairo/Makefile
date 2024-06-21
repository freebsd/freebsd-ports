PORTNAME=	cairo
DISTVERSION=	1.18.2
PORTEPOCH=	3
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/

PATCH_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	f19e2fe080ddcfce93c8234a919fd882f3d63362.patch:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support
WWW=		https://www.cairographics.org/

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL-2.1
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING-MPL-1.1

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		liblzo2.so:archivers/lzo2 \
		libpng.so:graphics/png

USES=		cpe gnome localbase:ldflags meson pkgconfig python:build \
		shebangfix tar:xz xorg
CPE_VENDOR=	cairographics
USE_LDCONFIG=	yes
USE_XORG=	pixman

SHEBANG_FILES=	version.py

# spectre only used by tests; symbol-lookup because libbfd is difficult
# to use (https://sourceware.org/bugzilla/show_bug.cgi?id=14243);
# tests has circular dependencies
MESON_ARGS=	-Dspectre=disabled \
		-Dsymbol-lookup=disabled \
		-Dtests=disabled

DOCSDIR=	${PREFIX}/share/gtk-doc/html
PORTSCOUT=	skipv:5c-1.1,5c-1.2,5c-1.5

PLIST_SUB=	LIBVER=2.11802.2

OPTIONS_DEFINE=	DOCS GLIB X11
OPTIONS_DEFAULT=DOCS GLIB X11
OPTIONS_SUB=	yes

GLIB_DESC=	Enable GObject Functions Feature

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc

GLIB_USE=		GNOME=glib20
GLIB_MESON_ENABLED=	glib

X11_USE=		XORG=x11,xcb,xext,xorgproto,xrender
X11_MESON_ENABLED=	xcb xlib

.include <bsd.port.mk>
