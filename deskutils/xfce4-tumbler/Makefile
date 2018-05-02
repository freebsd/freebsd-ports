# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	tumbler
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/xfce/${PORTNAME}/${PORTVERSION:R}/
PKGNAMEPREFIX=	xfce4-
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Thumbnail service for Xfce desktop

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gettext-tools gmake libtool localbase:ldflags pathfix \
		pkgconfig tar:bzip2 xfce
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 intltool gdkpixbuf2 librsvg2 cairo libgsf
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-xdg-cache \
		--enable-pixbuf-thumbnailer \
		--disable-gtk-doc-html \
		--without-html-dir

OPTIONS_DEFINE=	NLS FONTS JPEG FFMPEG POPPLER \
		GSTREAMER ODF COVER
OPTIONS_DEFAULT=	FONTS JPEG POPPLER GSTREAMER ODF

FONTS_DESC=	Fonts thumbnailer plugin
COVER_DESC=	Open Movie Database plugin (check pkg-message)
GSTREAMER_DESC=	GStreamer thumbnailer plugin

NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
FONTS_LIB_DEPENDS=	libfreetype.so:print/freetype2
FONTS_CONFIGURE_ENABLE=	font-thumbnailer
JPEG_LIB_DEPENDS=	libexif.so:graphics/libexif
JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpeg-thumbnailer
FFMPEG_LIB_DEPENDS=	libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer
FFMPEG_CONFIGURE_ENABLE=	ffmpeg-thumbnailer
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_CONFIGURE_ENABLE=	poppler-thumbnailer
GSTREAMER_USE=	gstreamer1=yes
GSTREAMER_CONFIGURE_ENABLE=	gstreamer-thumbnailer
ODF_USE=	gnome=libgsf
ODF_CONFIGURE_ENABLE=	odf-thumbnailer
COVER_LIB_DEPENDS=	libcurl.so:ftp/curl
COVER_CONFIGURE_ENABLE=	cover-thumbnailer
OPTIONS_SUB=	yes

SUB_FILES=	pkg-message

.include <bsd.port.mk>
