PORTNAME=	xviewer
DISTVERSION=	3.4.16
CATEGORIES=	graphics gnome
DIST_SUBDIR=	gnome

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	74d7d4ba2584c658ae6fb87208543671664943cc.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fast and functional image viewer
WWW=		https://github.com/linuxmint/xviewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^[0-9.]+$$	# ignore non-numeric tags

BUILD_DEPENDS=	itstool:textproc/itstool \
		${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools
LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxapp.so:x11/xapp \
		libpeas-1.0.so:devel/libpeas1
RUN_DEPENDS=	yelp:x11/yelp

USES=		meson compiler:c++11-lang desktop-file-utils gettext-tools \
		gnome localbase pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	atk cairo gdkpixbuf2xlib glib20 gtk30 introspection pango
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.viewer.enums.xml org.x.viewer.gschema.xml

OPTIONS_DEFINE=	DOCS JPEG LCMS2 LIBEXIF LIBRSVG2 XMP
OPTIONS_DEFAULT=	JPEG LCMS2 LIBEXIF LIBRSVG2 XMP
XMP_DESC=	Adobe Extensible Metadata Platform support
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

JPEG_USES=		jpeg
JPEG_MESON_ENABLED=	jpeg

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_MESON_ENABLED=	lcms

LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_MESON_ENABLED=	exif

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_MESON_ENABLED=	rsvg

XMP_LIB_DEPENDS=	libexempi.so:textproc/exempi
XMP_MESON_ENABLED=	exempi

.include <bsd.port.mk>
