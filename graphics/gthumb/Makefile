# New ports collection makefile for:	gThumb2
# Date created:				17 Aug 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gthumb
PORTVERSION=	2.14.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	pav@FreeBSD.org
COMMENT=	An image viewer and browser for the GNOME 2 environment

LIB_DEPENDS=	unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XZ=	yes
USE_GETTEXT=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedocutils gconf2
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

OPTIONS=	EXIV2 "Exif support (image metadata)" On \
		CLUTTER "Fancy slideshows" On \
		GSTREAMER "Video playback" On \
		OPENRAW "Support for camera RAW files" On \
		SOUP "Web services uploaders" On \
		BRASERO "Write galleries to CD/DVD (large dependency)" On \
		YELP "Viewer for built-in help system" On

.include <bsd.port.pre.mk>

.if defined(WITH_EXIV2)
LIB_DEPENDS+=	exiv2.12:${PORTSDIR}/graphics/exiv2
CONFIGURE_ARGS+=--enable-exiv2
PLIST_SUB+=	EXIV2=""
.else
CONFIGURE_ARGS+=--disable-exiv2
PLIST_SUB+=	EXIV2="@comment "
.endif

.if defined(WITH_CLUTTER)
LIB_DEPENDS+=	clutter-gtk-0.10.0:${PORTSDIR}/graphics/clutter-gtk
CONFIGURE_ARGS+=--enable-clutter
.else
CONFIGURE_ARGS+=--disable-clutter
.endif

.if defined(WITH_GSTREAMER)
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=--enable-gstreamer
PLIST_SUB+=	GSTREAMER=""
GCONF_SCHEMAS+=	gthumb-gstreamer.schemas
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if defined(WITH_OPENRAW)
LIB_DEPENDS+=	openrawgnome.6:${PORTSDIR}/graphics/libopenraw
CONFIGURE_ARGS+=--enable-libopenraw
.else
CONFIGURE_ARGS+=--disable-libopenraw
.endif

.if defined(WITH_SOUP)
LIB_DEPENDS+=	soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome
CONFIGURE_ARGS+=--enable-libsoup --enable-gnome-keyring
PLIST_SUB+=	SOUP=""
GCONF_SCHEMAS+=	gthumb-facebook.schemas gthumb-picasaweb.schemas
.else
CONFIGURE_ARGS+=--disable-libsoup --disable-gnome-keyring
PLIST_SUB+=	SOUP="@comment "
.endif

.if defined(WITH_BRASERO)
LIB_DEPENDS+=	brasero-burn.3:${PORTSDIR}/sysutils/brasero
CONFIGURE_ARGS+=--enable-libbrasero
PLIST_SUB+=	BRASERO=""
.else
CONFIGURE_ARGS+=--disable-libbrasero
PLIST_SUB+=	BRASERO="@comment "
.endif

.if defined(WITH_YELP)
RUN_DEPENDS+=	yelp:${PORTSDIR}/x11/yelp
.endif

.include <bsd.port.post.mk>
