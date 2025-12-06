PORTNAME=	geeqie
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image viewer forked from GQview
WWW=		https://www.geeqie.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash
BUILD_DEPENDS=	xxd:sysutils/xxd
TEST_DEPENDS=	appstreamcli:devel/appstream

USES=		desktop-file-utils gettext-tools gnome jpeg \
		lua:53 meson pkgconfig shebangfix
USE_GNOME=	cairo gdkpixbuf gtk30 glib20
USE_GITHUB=	yes
GH_ACCOUNT=	BestImageViewer
SHEBANG_FILES=	plugins/*/geeqie-* \
		plugins/resize-image/downsize
CFLAGS+=	-Wno-deprecated-declarations
MESON_ARGS=	-Ddoxygen=disabled
MESON_ARGS+=	-Dpandoc=disabled
MESON_ARGS+=	-Devince=disabled
MESON_ARGS+=	-Dgit=disabled

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	EXIV2 LCMS MAP FFMPEGTHUMBNAILER ARCHIVE SPELL DOCS NLS
OPTIONS_DEFAULT=EXIV2 LCMS MAP FFMPEGTHUMBNAILER ARCHIVE SPELL \
		TIFF PDF HEIF DJVU OPENJPEG RAW JXL WEBP
OPTIONS_GROUP=	FORMATS
OPTIONS_GROUP_FORMATS=	TIFF PDF HEIF DJVU OPENJPEG RAW JXL WEBP
OPTIONS_SUB=	yes

FORMATS_DESC=	Image formats support

EXIV2_DESC=		Metadata editing
EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_MESON_ENABLED=	exiv2

LCMS_DESC=		Color adjusting
LCMS_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS_MESON_ENABLED=	cms

MAP_DESC=		GPS map support via libchamplain
MAP_LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
			libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
			libclutter-1.0.so:graphics/clutter
MAP_MESON_ENABLED=	gps-map

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	tiff

PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
PDF_MESON_ENABLED=	pdf

FFMPEGTHUMBNAILER_DESC=	Video file thumbnails generating support
FFMPEGTHUMBNAILER_MESON_ENABLED=	videothumbnailer
FFMPEGTHUMBNAILER_LIB_DEPENDS=	libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer

HEIF_MESON_ENABLED=	heif
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif

DJVU_MESON_ENABLED=	djvu
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre

OPENJPEG_MESON_ENABLED=	j2k
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

RAW_MESON_ENABLED=	libraw
RAW_LIB_DEPENDS=	libraw.so:graphics/libraw

ARCHIVE_MESON_ENABLED=	archive
ARCHIVE_USES=		libarchive

JXL_MESON_ENABLED=	jpegxl
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl

WEBP_MESON_ENABLED=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

SPELL_DESC=		Spelling check through gspell
SPELL_MESON_ENABLED=	spell
SPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

DOCS_BUILD_DEPENDS=	yelp-build:textproc/yelp-tools

.include <bsd.port.mk>
