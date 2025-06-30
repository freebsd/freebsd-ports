PORTNAME=	tumbler
PORTVERSION=	4.20.0
PORTREVISION=	4
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE
PKGNAMEPREFIX=	xfce4-
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Thumbnail service for Xfce desktop
WWW=		https://git.xfce.org/xfce/tumbler/

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng16.so:graphics/png

USES=		compiler:c11 gettext-tools gmake gnome libtool \
		localbase:ldflags pathfix pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf glib20 libgsf
USE_LDCONFIG=	yes
USE_XFCE=	libutil

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc-html \
		--enable-pixbuf-thumbnailer \
		--enable-xdg-cache \
		--without-html-dir
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		COVER EPUB FFMPEG FONTS GSTREAMER JPEG NLS ODF POPPLER
OPTIONS_DEFAULT=	EPUB FONTS GSTREAMER JPEG ODF POPPLER
OPTIONS_SUB=		yes

COVER_DESC=	Open Movie Database plugin (check pkg-message)
EPUB_DESC=	EPUB thumbnailer plugin
FONTS_DESC=	Fonts thumbnailer plugin
GSTREAMER_DESC=	GStreamer thumbnailer plugin

COVER_LIB_DEPENDS=	libcurl.so:ftp/curl
COVER_CONFIGURE_ENABLE=	cover-thumbnailer

EPUB_LIB_DEPENDS=	libgepub-0.7.so:textproc/libgepub
EPUB_CONFIGURE_ENABLE=	gepub-thumbnailer

FFMPEG_LIB_DEPENDS=		libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer
FFMPEG_CONFIGURE_ENABLE=	ffmpeg-thumbnailer

FONTS_LIB_DEPENDS=	libfreetype.so:print/freetype2
FONTS_CONFIGURE_ENABLE=	font-thumbnailer

GSTREAMER_USES=			gstreamer
GSTREAMER_CONFIGURE_ENABLE=	gstreamer-thumbnailer

JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpeg-thumbnailer

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

ODF_USE=		GNOME=libgsf
ODF_CONFIGURE_ENABLE=	odf-thumbnailer

POPPLER_LIB_DEPENDS=		libpoppler-glib.so:graphics/poppler-glib
POPPLER_CONFIGURE_ENABLE=	poppler-thumbnailer

.include <bsd.port.mk>
