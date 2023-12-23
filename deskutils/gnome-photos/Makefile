PORTNAME=	gnome-photos
DISTVERSION=	43.0
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Photo application for GNOME
WWW=		https://wiki.gnome.org/Design/Apps/Photos

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	geoclue>=0:net/geoclue \
		itstool:textproc/itstool
LIB_DEPENDS=	libbabl-0.1.so:x11/babl \
		libdazzle-1.0.so:x11-toolkits/libdazzle \
		libexempi.so:textproc/exempi \
		libexiv2.so:graphics/exiv2 \
		libfribidi.so:converters/fribidi \
		libgdata.so:devel/libgdata \
		libgegl-0.4.so:graphics/gegl \
		libgeocode-glib-2.so:net/geocode-glib2 \
		libgexiv2.so:graphics/gexiv2 \
		libgfbgraph-0.2.so:net/gfbgraph \
		libgjs.so:lang/gjs \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgrilo-0.3.so:net/grilo \
		libhandy-1.so:x11-toolkits/libhandy \
		libjson-glib-1.0.so:devel/json-glib \
		libpng.so:graphics/png \
		libportal.so:deskutils/libportal \
		libportal-gtk3.so:deskutils/libportal-gtk3 \
		librest-0.7.so:devel/librest \
		libsoup-2.4.so:devel/libsoup \
		libtracker-sparql-3.0.so:sysutils/tracker3
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome jpeg localbase meson pkgconfig \
		tar:xz
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 gtk30 libxml2
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.photos.gschema.xml
MESON_ARGS=	--buildtype \
		plain

post-patch:
	@${REINPLACE_CMD} -e "s,'babl','babl-0.1'," \
		${WRKSRC}/meson.build
.include <bsd.port.mk>
