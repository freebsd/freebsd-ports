# New ports collection makefile for:	tumbler
# Date created:				2010-12-03
# Whom:					Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tumbler
PORTVERSION=	0.1.6
CATEGORIES=	deskutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
PKGNAMEPREFIX=	xfce4-
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Thumbnail service for Xfce desktop

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20 gnomehack intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv

CONFIGURE_ARGS=	--enable-xdg-cache \
		--disable-gtk-doc-html

OPTIONS=	NLS "Enable Native Language Support" on \
		APIDOCS "Install api documentation" off \
		PIXBUF "Enable gdk-pixbuf plugin thumbnailer" on \
		FONTS "Enable fonts plugin thumbnailer" on \
		JPEG "Enable JPEG and EXIF plugin thumbnailer" on \
		FFMPEG "Enable FFMPEG plugin thumbnailer" off \
		POPPLER "Enable PDF/PS plugin thumbnailer" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_APIDOCS)
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.endif

.if !defined(WITHOUT_PIXBUF)
USE_GNOME+=	gdkpixbuf2
CONFIGURE_ARGS+=--enable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF=""
.else
CONFIGURE_ARGS+=--disable-pixbuf-thumbnailer
PLIST_SUB+=	PIXBUF="@comment "
.endif

.if !defined(WITHOUT_FONTS)
CONFIGURE_ARGS+=--enable-font-thumbnailer
PLIST_SUB+=	FONTS=""
.else
CONFIGURE_ARGS+=--disable-font-thumbnailer
PLIST_SUB+=	FONTS="@comment "
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		exif.12:${PORTSDIR}/graphics/exif
CONFIGURE_ARGS+=--enable-jpeg-thumbnailer
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--disable-jpeg-thumbnailer
PLIST_SUB+=	JPEG="@comment "
.endif

.if !defined(WITHOUT_FFMPEG)
LIB_DEPENDS+=	ffmpegthumbnailer.4:${PORTSDIR}/multimedia/ffmpegthumbnailer
CONFIGURE_ARGS+=--enable-ffmpeg-thumbnailer
PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=--disable-ffmpeg-thumbnailer
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if !defined(WITHOUT_POPPLER)
LIB_DEPENDS+=	poppler-glib.5:${PORTSDIR}/graphics/poppler-gtk
CONFIGURE_ARGS+=--enable-poppler-thumbnailer
PLIST_SUB+=	POPPLER=""
.else
CONFIGURE_ARGS+=--disable-poppler-thumbnailer
PLIST_SUB+=	POPPLER="@comment "
.endif

.include <bsd.port.post.mk>
