# Created by: Martin Tournoij <carpetsmoker@rwxrwxrwx.net>
# $FreeBSD$

PORTNAME=	geeqie
PORTVERSION=	1.6
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.geeqie.org/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image viewer forked from GQview

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	bash:shells/bash

CONFLICTS=	geeqie-devel-[0-9]*

USES=		autoreconf compiler:c++11-lang gettext gmake gnome jpeg \
		localbase pkgconfig desktop-file-utils tar:xz lua:53 shebangfix
USE_GNOME=	cairo gdkpixbuf2 intltool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readmedir="${DOCSDIR}"
CONFIGURE_ARGS+=--disable-j2k  # not in ports (yet), disable proactively to avoid hidden dependency
SHEBANG_FILES=	plugins/*/geeqie-*

PORTDOCS=	*

OPTIONS_DEFINE=	EXIV2 LCMS LIRC MAP TIFF PDF FFMPEGTHUMBNAILER DOCS NLS HEIF WEBP DJVU OPENJPEG
OPTIONS_DEFAULT=EXIV2 LCMS GTK3 PDF FFMPEGTHUMBNAILER HEIF WEBP DJVU OPENJPEG
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=GTK2 GTK3
OPTIONS_SUB=	yes

EXIV2_DESC=	Metadata editing
LCMS_DESC=	Color adjusting
LIRC_DESC=	Remote control (broken)
MAP_DESC=	GPS map support via libchamplain
TOOLKIT_DESC=	Graphical user interface toolkit
GTK2_DESC=	Use GTK 2
GTK3_DESC=	Use GTK 3
HEIF_DESC=	HEIF image format support

EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_CONFIGURE_ENABLE=	exiv2

LCMS_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS_CONFIGURE_ENABLE=	lcms

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc
LIRC_CONFIGURE_ON=	--with-lirc-prefix="${LOCALBASE}"
LIRC_BROKEN=		does not build with old lirc from ports

MAP_LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
			libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
			libclutter-1.0.so:graphics/clutter \
			libcogl.so:graphics/cogl \
			libjson-glib-1.0.so:devel/json-glib

MAP_CONFIGURE_ENABLE=	map gpu-accel
MAP_REQUIRES=		GTK3
MAP_USES=		gl xorg
MAP_USE=		GL=egl XORG=xrandr,x11,xext,xdamage,xfixes,xcomposite,xi

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_ENABLE=	tiff

GTK2_USE=		GNOME=gtk20
GTK3_USE=		GNOME=gtk30
GTK3_CONFIGURE_ENABLE=	gtk3

PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
PDF_CONFIGURE_ENABLE=	pdf
PDF_REQUIRES=		GTK3

FFMPEGTHUMBNAILER_DESC=	Video file thumbnails generating support
FFMPEGTHUMBNAILER_CONFIGURE_ENABLE=	ffmpegthumbnailer
FFMPEGTHUMBNAILER_LIB_DEPENDS=	libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer

GTK2_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libfontconfig.so:x11-fonts/fontconfig

NLS_CONFIGURE_ENABLE=	nls

HEIF_CONFIGURE_ENABLE=	heif
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif

WEBP_CONFIGURE_ENABLE=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

DJVU_CONFIGURE_ENABLE=	djvu
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre

OPENJPEG_CONFIGURE_ENABLE=	j2k
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

.include <bsd.port.mk>
