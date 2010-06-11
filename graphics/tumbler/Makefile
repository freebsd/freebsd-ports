# New ports collection makefile for:	tumbler
# Date created:		2010-01-15
# Whom:			Ashish SHUKLA <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tumbler
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	graphics xfce
MASTER_SITES=	http://archive.xfce.org/src/apps/${PORTNAME}/0.1/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	D-Bus service for generating thumbnails

BUILD_DEPENDS=	dbus-binding-tool:${PORTSDIR}/devel/dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/glib-2.0.pc:${PORTSDIR}/devel/glib20 \
		${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/libpng.pc:${PORTSDIR}/graphics/png \
		glib>=2.16.0:${PORTSDIR}/devel/glib20 \
		dbus>=1.0.0:${PORTSDIR}/devel/dbus \
		dbus-glib>=0.72:${PORTSDIR}/devel/dbus-glib \
		png>=1.2.0:${PORTSDIR}/graphics/png

OPTIONS=	GTK2	"Enable GdkPixBuf thumbnailer plugin" On \
		JPEG	"Enable JPEG thumbnailer plugin with EXIF support"	On \
		FREETYPE	"Enable Freetype font thumbnailer plugin"	On \
		XDG	"Enable freedesktop.org cache plugin"	On

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"CFLAGS=-I${LOCALBASE}/include" "LDFLAGS=-L${LOCALBASE}/lib"
USE_GNOME=	glib20 gnomehack
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

.include <bsd.port.options.mk>

.if defined(WITH_GTK2)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/gdk-pixbuf-2.0.pc:${PORTSDIR}/x11-toolkits/gtk20 \
		gtk>=2.14:${PORTSDIR}/x11-toolkits/gtk20
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK2=""
WITH_PLUGINS=	true
.elif defined(WITHOUT_GTK2)
CONFIGURE_ARGS+=	--disable-pixbuf-thumbnailer
PLIST_SUB+=	GTK2="@comment "
.endif

.if defined(WITH_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
WITH_PLUGINS=	true
.elif defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--disable-jpeg-thumbnailer
PLIST_SUB+=	JPEG="@comment "
.endif

.if defined(WITH_FREETYPE)
BUILD_DEPENDS+=	freetype-config:${PORTSDIR}/print/freetype2
PLIST_SUB+=	FREETYPE=""
WITH_PLUGINS=	true
.elif defined(WITHOUT_FREETYPE)
CONFIGURE_ARGS+=	--disable-font-thumbnailer
PLIST_SUB+=	FREETYPE="@comment "
.endif

.if defined(WITHOUT_XDG)
CONFIGURE_ARGS+=	--disable-xdg-cache
PLIST_SUB+=	XDG="@comment "
.elif defined(WITH_XDG)
PLIST_SUB+=	XDG=""
WITH_PLUGINS=	true
.endif

.if defined(WITH_PLUGINS)
PLIST_SUB+=	PLUGINS=""
.else
PLIST_SUB+=	PLUGINS="@comment "
.endif

.include <bsd.port.mk>
