# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	tumbler
PORTVERSION=	0.1.30
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
PKGNAMEPREFIX=	xfce4-
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Thumbnail service for Xfce desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USES=		pathfix pkgconfig gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	configenv

CONFIGURE_ARGS=	--enable-xdg-cache \
		--disable-gtk-doc-html

OPTIONS_DEFINE=	DOCS NLS PIXBUF FONTS JPEG FFMPEG POPPLER \
		GSTREAMER ODF OPENRAW COVER
OPTIONS_DEFAULT=	PIXBUF FONTS JPEG POPPLER ODF
FONTS_DESC=	Fonts thumbnailer plugin
COVER_DESC=	Open Movie Database thumbnailer plugin
GSTREAMER_DESC=	GStreamer (1.0) thumbnailer plugin

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.else
CONFIGURE_ARGS+=--disable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF="@comment "
.endif

.if ${PORT_OPTIONS:MFONTS}
# PIXBUF needs to be set
.if ! ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.endif
LIB_DEPENDS+=	libfreetype.so:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=--enable-font-thumbnailer
PLIST_SUB+=	FONTS=""
.else
CONFIGURE_ARGS+=--disable-font-thumbnailer
PLIST_SUB+=	FONTS="@comment "
.endif

.if ${PORT_OPTIONS:MJPEG}
.if ! ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.endif
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libexif.so:${PORTSDIR}/graphics/exif
CONFIGURE_ARGS+=--enable-jpeg-thumbnailer
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--disable-jpeg-thumbnailer
PLIST_SUB+=	JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
.if ! ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.endif
LIB_DEPENDS+=	libffmpegthumbnailer.so:${PORTSDIR}/multimedia/ffmpegthumbnailer
CONFIGURE_ARGS+=--enable-ffmpeg-thumbnailer
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=--disable-ffmpeg-thumbnailer
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPOPPLER}
.if ! ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.endif
LIB_DEPENDS+=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
CONFIGURE_ARGS+=--enable-poppler-thumbnailer
PLIST_SUB+=	POPPLER=""
.else
CONFIGURE_ARGS+=--disable-poppler-thumbnailer
PLIST_SUB+=	POPPLER="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
.if ! ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.endif
USE_GSTREAMER1=	yes
CONFIGURE_ARGS+=--enable-gstreamer-thumbnailer
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-gstreamer-thumbnailer
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if ${PORT_OPTIONS:MODF}
.if ! ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.endif
USE_GNOME+=	libgsf
CONFIGURE_ARGS+=--enable-odf-thumbnailer
PLIST_SUB+=	ODF=""
.else
CONFIGURE_ARGS+=--disable-odf-thumbnailer
PLIST_SUB+=	ODF="@comment "
.endif

.if ${PORT_OPTIONS:MOPENRAW}
.if ! ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.endif
LIB_DEPENDS+=	libopenraw.so:${PORTSDIR}/graphics/libopenraw
CONFIGURE_ARGS+=--enable-raw-thumbnailer
PLIST_SUB+=	RAW=""
.else
CONFIGURE_ARGS+=--disable-raw-thumbnailer
PLIST_SUB+=	RAW="@comment "
.endif

.if ${PORT_OPTIONS:MCOVER}
.if ! ${PORT_OPTIONS:MPIXBUF}
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.endif
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--enable-cover-thumbnailer
PLIST_SUB+=	COVER=""
.else
CONFIGURE_ARGS+=--disable-cover-thumbnailer
PLIST_SUB+=	COVER="@comment "
.endif

.include <bsd.port.mk>
