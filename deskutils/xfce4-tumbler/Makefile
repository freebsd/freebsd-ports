PORTNAME=	tumbler
PORTVERSION=	4.18.2
PORTREVISION=	1
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
USE_GNOME=	cairo gdkpixbuf2 glib20 intltool libgsf
USE_XFCE=	libutil
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message
CONFIGURE_ARGS=	--enable-xdg-cache \
		--enable-pixbuf-thumbnailer \
		--disable-gtk-doc-html \
		--without-html-dir

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	COVER EPUB FFMPEG FONTS GSTREAMER JPEG \
		NLS ODF POPPLER
OPTIONS_DEFAULT=EPUB FONTS GSTREAMER JPEG ODF POPPLER
OPTIONS_SUB=	yes

COVER_DESC=	Open Movie Database plugin (check pkg-message)
EPUB_DESC=	EPUB thumbnailer plugin
FONTS_DESC=	Fonts thumbnailer plugin
GSTREAMER_DESC=	GStreamer thumbnailer plugin

COVER_CONFIGURE_ENABLE=	cover-thumbnailer
COVER_LIB_DEPENDS=	libcurl.so:ftp/curl

EPUB_CONFIGURE_ENABLE=	gepub-thumbnailer
EPUB_LIB_DEPENDS=	libgepub-0.6.so:textproc/libgepub

FFMPEG_CONFIGURE_ENABLE=	ffmpeg-thumbnailer
FFMPEG_LIB_DEPENDS=	libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer

FONTS_CONFIGURE_ENABLE=	font-thumbnailer
FONTS_LIB_DEPENDS=	libfreetype.so:print/freetype2

GSTREAMER_CONFIGURE_ENABLE=	gstreamer-thumbnailer
GSTREAMER_USES=		gstreamer

JPEG_CONFIGURE_ENABLE=	jpeg-thumbnailer
JPEG_USES=		jpeg

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

ODF_CONFIGURE_ENABLE=	odf-thumbnailer
ODF_USE=		gnome=libgsf

POPPLER_CONFIGURE_ENABLE=	poppler-thumbnailer
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

.include <bsd.port.mk>
