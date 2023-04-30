PORTNAME=	vips
PORTVERSION=	8.14.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/libvips/libvips/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Free image processing system
WWW=		https://libvips.github.io/libvips \
		https://github.com/libvips/libvips

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang cpe gettext gnome localbase meson pkgconfig python shebangfix tar:xz
USE_GNOME=	glib20

MESON_ARGS=	--default-library=both \
		-Danalyze=true \
		-Dcplusplus=true \
		-Ddeprecated=true \
		-Ddoxygen=false \
		-Dexamples=true \
		-Dfontconfig=enabled \
		-Dintrospection=false \
		-Dmodules=disabled \
		-Dnifti=disabled \
		-Dnsgif=true \
		-Dopenslide=disabled \
		-Dpdfium=disabled \
		-Dppm=true \
		-Dquantizr=disabled \
		-Dradiance=true \
		-Dvapi=false \
		-Dzlib=enabled
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION:R}

SHEBANG_FILES=	tools/vipsprofile

OPTIONS_DEFINE=	CFITSIO DOCS FFTW GIF GSF HEIF IMAGEQUANT JPEG JXL LCMS2 LIBEXIF LIBRSVG2 MATIO OPENEXR ORC PANGO PNG POPPLER SPNG TIFF WEBP
OPTIONS_RADIO=	MAGICK
OPTIONS_RADIO_MAGICK=	IMAGEMAGICK GRAPHMAGICK
OPTIONS_DEFAULT=CFITSIO FFTW GIF GSF HEIF IMAGEMAGICK JPEG JXL LCMS2 LIBEXIF LIBRSVG2 MATIO OPENEXR ORC PANGO PNG POPPLER SPNG TIFF WEBP
GSF_DESC=	Structured file formats support
IMAGEQUANT_DESC=Image Quantization support
ORC_DESC=	ORC language support
MATIO_DESC=	Matlab MAT format support

CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
CFITSIO_MESON_ENABLED=	cfitsio
DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_MESON_ENABLED=	fftw
GIF_BUILD_DEPENDS=	cgif>=0.2.0:graphics/cgif
GIF_LIB_DEPENDS=	libcgif.so:graphics/cgif
GIF_MESON_ENABLED=	cgif
GRAPHMAGICK_LIB_DEPENDS=libGraphicsMagick.so:graphics/GraphicsMagick
GRAPHMAGICK_MESON_ON=	-Dmagick=enabled -Dmagick-package=GraphicsMagick
GSF_MESON_ENABLED=	gsf
GSF_USE=		GNOME=libgsf
HEIF_BUILD_DEPENDS=	libheif>=1.3.0:graphics/libheif
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_ENABLED=	heif
IMAGEMAGICK_MESON_ON=	-Dmagick=enabled -Dmagick-package=MagickCore
IMAGEMAGICK_USES=	magick
IMAGEQUANT_LIB_DEPENDS=	libimagequant.so:graphics/libimagequant
IMAGEQUANT_MESON_ENABLED=	imagequant
JPEG_BUILD_DEPENDS=	openjpeg>=2.4:graphics/openjpeg
JPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
JPEG_MESON_ENABLED=	jpeg openjpeg
JPEG_USES=		jpeg
JXL_BUILD_DEPENDS=	libjxl>=0.6:graphics/libjxl
JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_MESON_ENABLED=	jpeg-xl
LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_MESON_ENABLED=	lcms
LIBEXIF_BUILD_DEPENDS=	libexif>=0.6:graphics/libexif
LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_MESON_ENABLED=	exif
LIBRSVG2_MESON_ENABLED=	rsvg
LIBRSVG2_USE=		GNOME=cairo,librsvg2
MATIO_LIB_DEPENDS=	libmatio.so:math/matio
MATIO_MESON_ENABLED=	matio
OPENEXR_BUILD_DEPENDS=	openexr>=1.2.2:graphics/openexr
OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
OPENEXR_MESON_ENABLED=	openexr
ORC_BUILD_DEPENDS=	orc>=0.4.11:devel/orc
ORC_LIB_DEPENDS=	liborc-0.4.so:devel/orc
ORC_MESON_ENABLED=	orc
PANGO_MESON_ENABLED=	pangocairo
PANGO_USE=		GNOME=pango
PNG_BUILD_DEPENDS=	png>=1.2.9:graphics/png
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	png
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_MESON_ENABLED=	poppler
POPPLER_USE=		GNOME=cairo
SPNG_BUILD_DEPENDS=	libspng>=0.7:graphics/libspng
SPNG_LIB_DEPENDS=	libspng.so:graphics/libspng
SPNG_MESON_ENABLED=	spng
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MESON_ENABLED=	tiff
WEBP_BUILD_DEPENDS=	webp>=0.6:graphics/webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MESON_ENABLED=	webp

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MGRAPHMAGICK} && !${PORT_OPTIONS:MIMAGEMAGICK}
MESON_ARGS+=	-Dmagick=disabled
.endif

.include <bsd.port.mk>
