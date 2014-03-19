# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gthumb
PORTVERSION=	2.14.1
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Image viewer and browser for the GNOME 2 environment

LIB_DEPENDS=	unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XZ=		yes
USES=		bison gmake pathfix pkgconfig gettext
USE_GNOME=	gnomeprefix intlhack gnomedocutils gconf2
WANT_GSTREAMER=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gthumb.schemas gthumb-comments.schemas gthumb-file-manager.schemas \
		gthumb-image-viewer.schemas gthumb-importer.schemas gthumb-pixbuf-savers.schemas \
		gthumb-slideshow.schemas gthumb_change_date.schemas gthumb_contact_sheet.schemas \
		gthumb_convert_format.schemas gthumb_crop_options.schemas gthumb_image_print.schemas \
		gthumb_photo_importer.schemas gthumb_rename_series.schemas gthumb_resize_images.schemas \
		gthumb_resize_options.schemas gthumb_rotate_options.schemas gthumb_webalbums.schemas

PLIST_SUB=	GTHUMB_VER=2.14

OPTIONS_DEFINE=	EXIV2 CLUTTER GSTREAMER OPENRAW SOUP BRASERO YELP
OPTIONS_DEFAULT=	EXIV2 CLUTTER GSTREAMER OPENRAW SOUP BRASERO YELP
CLUTTER_DESC=	Fancy slideshows
GSTREAMER_DESC=	Video playback
SOUP_DESC=	Web services uploaders
BRASERO_DESC=	Write galleries to CD/DVD (large dependency)
YELP_DESC=	Viewer for built-in help system

NO_STAGE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIV2}
LIB_DEPENDS+=	exiv2.12:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--enable-exiv2
PLIST_SUB+=	EXIV2=""
.else
CONFIGURE_ARGS+=--disable-exiv2
PLIST_SUB+=	EXIV2="@comment "
.endif

.if ${PORT_OPTIONS:MCLUTTER}
LIB_DEPENDS+=	clutter-gtk-0.10.0:${PORTSDIR}/graphics/clutter-gtk
CONFIGURE_ARGS+=--enable-clutter
.else
CONFIGURE_ARGS+=--disable-clutter
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=--enable-gstreamer
PLIST_SUB+=	GSTREAMER=""
GCONF_SCHEMAS+=	gthumb-gstreamer.schemas
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

.if ${PORT_OPTIONS:MSOUP}
LIB_DEPENDS+=	soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome
CONFIGURE_ARGS+=--enable-libsoup --enable-gnome-keyring
PLIST_SUB+=	SOUP=""
GCONF_SCHEMAS+=	gthumb-facebook.schemas gthumb-picasaweb.schemas
.else
CONFIGURE_ARGS+=--disable-libsoup --disable-gnome-keyring
PLIST_SUB+=	SOUP="@comment "
.endif

.if ${PORT_OPTIONS:MBRASERO}
LIB_DEPENDS+=	brasero-burn.3:${PORTSDIR}/sysutils/brasero
CONFIGURE_ARGS+=--enable-libbrasero
PLIST_SUB+=	BRASERO=""
.else
CONFIGURE_ARGS+=--disable-libbrasero
PLIST_SUB+=	BRASERO="@comment "
.endif

.if ${PORT_OPTIONS:MYELP}
RUN_DEPENDS+=	yelp:${PORTSDIR}/x11/yelp
.endif

.include <bsd.port.mk>
