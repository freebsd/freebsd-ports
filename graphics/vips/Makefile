# Created by: Lev Serebryakov <lev@FreeBSD.org>

PORTNAME=	vips
PORTVERSION=	8.12.0
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/libvips/libvips/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Free image processing system

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang cpe gettext gmake gnome libtool localbase pathfix pkgconfig python shebangfix
USE_GNOME=	glib20

CONFIGURE_ARGS=	--disable-introspection \
		--without-doxygen \
		--without-imagequant \
		--without-nifti \
		--without-openslide \
		--without-pdfium
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION:R}

SHEBANG_FILES=	tools/vips-${PORTVERSION:R} tools/vipsprofile

OPTIONS_DEFINE=	CFITSIO DEBUG DOCS FFTW GIF GSF HEIF JPEG LCMS2 LIBEXIF LIBRSVG2 MATIO OPENEXR ORC PANGO PNG POPPLER TIFF WEBP X11
OPTIONS_RADIO=	MAGICK
OPTIONS_RADIO_MAGICK=	IMAGEMAGICK GRAPHMAGICK
OPTIONS_DEFAULT=CFITSIO FFTW GIF GSF HEIF IMAGEMAGICK JPEG LCMS2 LIBEXIF LIBRSVG2 MATIO OPENEXR ORC PANGO PNG POPPLER TIFF WEBP X11
GSF_DESC=	Structured file formats support
ORC_DESC=	ORC language support
HEIF_DESC=	HEIF image format support
MATIO_DESC=	Matlab MAT format support

CFITSIO_CONFIGURE_WITH=	cfitsio
CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
DEBUG_CONFIGURE_ENABLE=	debug
DEBUG_INSTALL_TARGET_OFF=	install-strip
DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_CONFIGURE_ENABLE=	gtk-doc gtk-doc-html
FFTW_CONFIGURE_WITH=	fftw
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
GIF_CONFIGURE_WITH=	giflib
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GRAPHMAGICK_CONFIGURE_ON=	--with-magickpackage=GraphicsMagick
GRAPHMAGICK_LIB_DEPENDS=libGraphicsMagick.so:graphics/GraphicsMagick
GSF_CONFIGURE_WITH=	gsf
GSF_USE=		GNOME=libgsf
HEIF_CONFIGURE_WITH=	heif
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
IMAGEMAGICK_CONFIGURE_ON=	--with-magickpackage=MagickCore
JPEG_CONFIGURE_WITH=	jpeg
JPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
JPEG_USES=		jpeg
LCMS2_CONFIGURE_WITH=	lcms
LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LIBEXIF_CONFIGURE_WITH=	libexif
LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBRSVG2_CONFIGURE_WITH=rsvg
LIBRSVG2_USE=		GNOME=cairo,librsvg2
MATIO_CONFIGURE_WITH=	matio
MATIO_LIB_DEPENDS=	libmatio.so:math/matio
OPENEXR_CONFIGURE_WITH=	OpenEXR
OPENEXR_LIB_DEPENDS=	libImath.so:math/Imath libOpenEXR.so:graphics/openexr
ORC_CONFIGURE_WITH=	orc
ORC_LIB_DEPENDS=	liborc-0.4.so:devel/orc
PANGO_CONFIGURE_WITH=	pangoft2
PANGO_USE=		GNOME=pango
PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png
POPPLER_CONFIGURE_WITH=	poppler
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_USE=		GNOME=cairo
TIFF_CONFIGURE_WITH=	tiff
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
WEBP_CONFIGURE_WITH=	libwebp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
X11_CONFIGURE_WITH=	x

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
.if ${PORT_OPTIONS:MX11}
USES+=		magick:7
.else
USES+=		magick:7,nox11
.endif
.endif

.if !${PORT_OPTIONS:MGRAPHMAGICK} && !${PORT_OPTIONS:MIMAGEMAGICK}
CONFIGURE_ARGS+=--without-magick
.endif

.include <bsd.port.mk>
