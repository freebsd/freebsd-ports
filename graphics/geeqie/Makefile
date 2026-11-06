PORTNAME=	geeqie
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image viewer forked from GQview
WWW=		https://www.geeqie.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene
TEST_DEPENDS=	appstreamcli:devel/appstream

USES=		desktop-file-utils gettext-tools gnome jpeg \
		lua:53 meson pkgconfig shebangfix \
		python:test
USE_GNOME=	cairo gdkpixbuf gtk40 glib20
USE_GITHUB=	yes
GH_ACCOUNT=	BestImageViewer
SHEBANG_FILES=	data/plugins/resize-image/downsize
MESON_ARGS=	-Dgit=disabled
MESON_ARGS+=	-Dhelp_pdf=disabled  # not installed
MESON_ARGS+=	-Dpandoc=disabled
MESON_ARGS+=	-Dyelp_build=disabled  # not installed
MESON_ARGS+=	-Ddoxygen=disabled

OPTIONS_DEFINE=	ARCHIVE EXIV2 FFMPEGTHUMBNAILER LCMS MAP NLS SPELL VIDEOMETADATA
OPTIONS_DEFAULT=ARCHIVE CFITSIO DJVU EXIV2 FFMPEGTHUMBNAILER HEIF JXL LCMS \
		OPENEXR OPENJPEG PDF RAW SPELL TIFF VIDEOMETADATA WEBP
OPTIONS_EXCLUDE=MAP  # see below
OPTIONS_GROUP=	FORMATS
OPTIONS_GROUP_FORMATS=	CFITSIO DJVU HEIF JXL OPENEXR OPENJPEG PDF RAW TIFF WEBP
OPTIONS_SUB=	yes

FORMATS_DESC=	Image formats support

ARCHIVE_MESON_ENABLED=	archive
ARCHIVE_USES=		libarchive

CFITSIO_MESON_ENABLED=	fits
CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio

DJVU_MESON_ENABLED=	djvu
DJVU_LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre

EXIV2_DESC=		Metadata editing
EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_MESON_ENABLED=	exiv2

FFMPEGTHUMBNAILER_DESC=	Video file thumbnails generating support
FFMPEGTHUMBNAILER_MESON_ENABLED=	videothumbnailer
FFMPEGTHUMBNAILER_LIB_DEPENDS=	libffmpegthumbnailer.so:multimedia/ffmpegthumbnailer

JXL_MESON_ENABLED=	jpegxl
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl

HEIF_MESON_ENABLED=	heif
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif

# not currently used as help file does not seem to be installed
HELP_PDF_MESON_ENABLED=	help_pdf
HELP_PDF_MESON_ARGS=	-Dhelp_pdf_stylesheet=${LOCALBASE}/share/xsl/docbook/fo/docbook.xsl
HELP_PDF_BUILD_DEPENDS=	fop:textproc/fop \
			pdfoutline:textproc/pdfoutline \
			pdftotext:graphics/poppler-utils \
			xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/fo/docbook.xsl:textproc/docbook-xsl

LCMS_DESC=		Color management system
LCMS_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS_MESON_ENABLED=	cms

MAP_DESC=		GPS map support
MAP_LIB_DEPENDS=	libshumate-1.0.so:x11-toolkits/libshumate
MAP_MESON_ENABLED=	gps_map
MAP_BROKEN=		needs lubshumate 1.5.0, ports have 1.4.1

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
OPENEXR_MESON_ENABLED=	exr

OPENJPEG_MESON_ENABLED=	j2k
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

PDF_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
PDF_MESON_ENABLED=	pdf

RAW_MESON_ENABLED=	libraw
RAW_LIB_DEPENDS=	libraw.so:graphics/libraw

SPELL_DESC=		Spelling checks
SPELL_MESON_ENABLED=	spell
SPELL_LIB_DEPENDS=	libspelling-1.so:x11-toolkits/libspelling

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	tiff

VIDEOMETADATA_DESC=		Video GPS metadata support
VIDEOMETADATA_MESON_ENABLED=	videometadata
VIDEOMETADATA_LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg
VIDEOMETADATA_IMPLIES=		EXIV2

WEBP_MESON_ENABLED=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

post-patch:
	@${REINPLACE_CMD} 's|python3 |${PYTHON_CMD} |' ${WRKSRC}/build-aux/untranslated-text.sh

.include <bsd.port.mk>
