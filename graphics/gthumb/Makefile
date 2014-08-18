# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/gthumb/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	gthumb
PORTVERSION=	3.2.8
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Image viewer and browser for the GNOME 3 environment

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		desktop-file-utils bison gettext gmake pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack librsvg2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-libchamplain \
		--enable-librsvg
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gthumb.change-date.gschema.xml \
		org.gnome.gthumb.comments.gschema.xml \
		org.gnome.gthumb.contact-sheet.gschema.xml \
		org.gnome.gthumb.convert-format.gschema.xml \
		org.gnome.gthumb.crop.gschema.xml \
		org.gnome.gthumb.enums.xml \
		org.gnome.gthumb.facebook.gschema.xml \
		org.gnome.gthumb.file-manager.gschema.xml \
		org.gnome.gthumb.flickr.gschema.xml \
		org.gnome.gthumb.gschema.xml \
		org.gnome.gthumb.gstreamer-tools.gschema.xml \
		org.gnome.gthumb.image-print.gschema.xml \
		org.gnome.gthumb.image-viewer.gschema.xml \
		org.gnome.gthumb.importer.gschema.xml \
		org.gnome.gthumb.photo-importer.gschema.xml \
		org.gnome.gthumb.picasaweb.gschema.xml \
		org.gnome.gthumb.pixbuf-savers.gschema.xml \
		org.gnome.gthumb.rename-series.gschema.xml \
		org.gnome.gthumb.resize-images.gschema.xml \
		org.gnome.gthumb.resize.gschema.xml \
		org.gnome.gthumb.rotate.gschema.xml \
		org.gnome.gthumb.slideshow.gschema.xml \
		org.gnome.gthumb.webalbums.gschema.xml

PLIST_SUB=	GTHUMB_VER=3.2

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	EXIV2 CLUTTER GSTREAMER OPENRAW BRASERO YELP SECRET WEBP WEBSERVICES
OPTIONS_DEFAULT=	EXIV2 CLUTTER GSTREAMER OPENRAW BRASERO YELP SECRET WEBP WEBSERVICES
CLUTTER_DESC=	Fancy slideshows
GSTREAMER_DESC=	Video playback
WEBSERVICES_DESC=	Web services
BRASERO_DESC=	Write galleries to CD/DVD (large dependency)
YELP_DESC=	Viewer for built-in help system
SECRET_DESC=	Libsecret support for storing passwords
WEBP_DESC=	Support for Google WebP conversion tool
EXIV2_LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2
EXIV2_CONFIGURE_ENABLE=	exiv2
CLUTTER_LIB_DEPENDS=	libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3
CLUTTER_CONFIGURE_ENABLE=	clutter
GSTREAMER_USE=	GSTREAMER1=yes
GSTREAMER_CONFIGURE_ENABLE=	gstreamer
OPENRAW_LIB_DEPENDS=	libopenrawgnome.so:${PORTSDIR}/graphics/libopenraw
OPENRAW_CONFIGURE_ENABLE=	libopenraw
BRASERO_LIB_DEPENDS=	libbrasero-media3.so:${PORTSDIR}/sysutils/brasero
BRASERO_CONFIGURE_ENABLE=	brasero	
YELP_RUN_DEPENDS=	yelp:${PORTSDIR}/x11/yelp
SECRET_LIB_DEPENDS=	libsecret-1.so:${PORTSDIR}/security/libsecret
SECRET_CONFIGURE_ENABLE=	secret	
WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp
WEBP_CONFIGURE_ENABLE=	webp	
WEBSERVICES_LIB_DEPENDS=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
				libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
				libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
WEBSERVICES_CONFIGURE_ON=	--enable-libsoup --enable-webkit2 --enable-libjson-glib	
WEBSERVICES_CONFIGURE_OFF=	--disable-libsoup --disable-webkit2 --disable-libjson-glib

.include <bsd.port.mk>
