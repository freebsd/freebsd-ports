# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/gthumb/Makefile 19673 2014-05-18 19:14:26Z gusi $

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

OPTIONS_DEFINE=	EXIV2 CLUTTER GSTREAMER OPENRAW BRASERO YELP SECRET WEBP WEBSERVICES
OPTIONS_DEFAULT=	EXIV2 CLUTTER GSTREAMER OPENRAW BRASERO YELP SECRET WEBP WEBSERVICES
CLUTTER_DESC=	Fancy slideshows
GSTREAMER_DESC=	Video playback
WEBSERVICES_DESC=	Web services
BRASERO_DESC=	Write galleries to CD/DVD (large dependency)
YELP_DESC=	Viewer for built-in help system
SECRET_DESC=	Libsecret support for storing passwords
WEBP_DESC=	Support for Google WebP conversion tool

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIV2}
LIB_DEPENDS+=	libexiv2.so:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--enable-exiv2
PLIST_SUB+=	EXIV2=""
.else
CONFIGURE_ARGS+=--disable-exiv2
PLIST_SUB+=	EXIV2="@comment "
.endif

.if ${PORT_OPTIONS:MCLUTTER}
LIB_DEPENDS+=	libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3
CONFIGURE_ARGS+=--enable-clutter
.else
CONFIGURE_ARGS+=--disable-clutter
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER1=	yes
CONFIGURE_ARGS+=--enable-gstreamer
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if ${PORT_OPTIONS:MOPENRAW}
LIB_DEPENDS+=	libopenrawgnome.so:${PORTSDIR}/graphics/libopenraw
CONFIGURE_ARGS+=--enable-libopenraw
.else
CONFIGURE_ARGS+=--disable-libopenraw
.endif

.if ${PORT_OPTIONS:MWEBSERVICES}
LIB_DEPENDS+=	libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome \
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3 		
CONFIGURE_ARGS+=--enable-libsoup --enable-webkit2 --enable-libjson-glib
PLIST_SUB+=	WEBSERVICES=""
.else
CONFIGURE_ARGS+=--disable-libsoup --disable-webkit2 --disable-libjson-glib
PLIST_SUB+=	WEBSERVICES="@comment "
.endif

.if ${PORT_OPTIONS:MBRASERO}
LIB_DEPENDS+=	libbrasero-media3.so:${PORTSDIR}/sysutils/brasero
CONFIGURE_ARGS+=--enable-libbrasero
PLIST_SUB+=	BRASERO=""
.else
CONFIGURE_ARGS+=--disable-libbrasero
PLIST_SUB+=	BRASERO="@comment "
.endif

.if ${PORT_OPTIONS:MYELP}
RUN_DEPENDS+=	yelp:${PORTSDIR}/x11/yelp
.endif

.if ${PORT_OPTIONS:MWEBP}
LIB_DEPENDS+=	libwebp.so:${PORTSDIR}/graphics/webp
CONFIGURE_ARGS+=--enable-webp
PLIST_SUB+=	WEBP=""
.else
CONFIGURE_ARGS+=--disable-webp
PLIST_SUB+=	WEBP="@comment "
.endif

.if ${PORT_OPTIONS:MSECRET}
LIB_DEPENDS+=	libsecret-1.so:${PORTSDIR}/security/libsecret
CONFIGURE_ARGS+=--enable-libsecret
PLIST_SUB+=	SECRET=""
.else
CONFIGURE_ARGS+=--disable-libsecret
PLIST_SUB+=	SECRET="@comment "
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gthumb/extensions/lib*.so

.include <bsd.port.mk>
