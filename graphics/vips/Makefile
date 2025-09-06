PORTNAME=	vips
PORTVERSION=	8.17.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/libvips/libvips/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Free image processing system
WWW=		https://www.libvips.org/ \
		https://github.com/libvips/libvips

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang cpe gettext-tools gnome localbase meson pkgconfig python tar:xz
USE_GNOME=	glib20

BINARY_ALIAS=	python3=${PYTHON_CMD}
MESON_ARGS=	--default-library=both \
		-Danalyze=true \
		-Dcplusplus=true \
		-Dcpp-docs=false \
		-Ddeprecated=true \
		-Dexamples=true \
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

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

CONFLICTS_INSTALL=	vips vips-nox11

OPTIONS_DEFINE=	CFITSIO DOCS FFTW FONTCONFIG GIF HEIF IMAGEQUANT JPEG JXL LCMS2 LIBARCHIVE LIBEXIF LIBRSVG2 MATIO OPENEXR PANGO PNG POPPLER SPNG TIFF WEBP
OPTIONS_RADIO=	MAGICK SIMD
OPTIONS_RADIO_MAGICK=	IMAGEMAGICK GRAPHICSMAGICK
OPTIONS_RADIO_SIMD=	HIGHWAY ORC
OPTIONS_DEFAULT=CFITSIO FFTW FONTCONFIG GIF HEIF HIGHWAY IMAGEMAGICK JPEG JXL LCMS2 LIBARCHIVE LIBEXIF LIBRSVG2 MATIO OPENEXR PANGO PNG POPPLER SPNG TIFF WEBP
FONTCONFIG_IMPLIES=	PANGO
LIBARCHIVE_DESC=Save image pyramid via libarchive
HIGHWAY_DESC=	SIMD support via Highway (preferred)
IMAGEQUANT_DESC=Image Quantization support
GRAPHICSMAGICK_DESC=	Image processing via GraphicsMagick
MATIO_DESC=	Matlab MAT format support
ORC_DESC=	Accelerate loops with ORC
SPNG_DESC=	Simple PNG support

CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
CFITSIO_MESON_ENABLED=	cfitsio
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>=0:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_ENABLED=	introspection
DOCS_MESON_TRUE=	docs
DOCS_USE=		GNOME=introspection:build
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_MESON_ENABLED=	fftw
FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
FONTCONFIG_MESON_ENABLED=	fontconfig
GIF_BUILD_DEPENDS=	cgif>=0.2.0:graphics/cgif
GIF_LIB_DEPENDS=	libcgif.so:graphics/cgif
GIF_MESON_ENABLED=	cgif
GRAPHICSMAGICK_LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick@${FLAVOR}
GRAPHICSMAGICK_MESON_ON=-Dmagick=enabled -Dmagick-package=GraphicsMagick
HEIF_BUILD_DEPENDS=	libheif>=1.4.0:graphics/libheif
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_MESON_ENABLED=	heif
HIGHWAY_BUILD_DEPENDS=	highway>=1.0.5:devel/highway
HIGHWAY_LIB_DEPENDS=	libhwy.so:devel/highway
HIGHWAY_MESON_ENABLED=	highway
IMAGEMAGICK_MESON_ON=	-Dmagick=enabled -Dmagick-package=MagickCore
IMAGEMAGICK_USES=	magick:${FLAVOR}
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
LIBARCHIVE_BUILD_DEPENDS=	libarchive>=3.0.0:archivers/libarchive
LIBARCHIVE_MESON_ENABLED=	archive
LIBARCHIVE_USES=	libarchive
LIBRSVG2_MESON_ENABLED=	rsvg
LIBRSVG2_USE=		GNOME=cairo,librsvg2
MATIO_LIB_DEPENDS=	libmatio.so:math/matio
MATIO_MESON_ENABLED=	matio
OPENEXR_BUILD_DEPENDS=	openexr>=1.2.2:graphics/openexr
OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
OPENEXR_MESON_ENABLED=	openexr
ORC_BUILD_DEPENDS=	orc>=0.4.31:devel/orc
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

.if !${PORT_OPTIONS:MGRAPHICSMAGICK} && !${PORT_OPTIONS:MIMAGEMAGICK}
MESON_ARGS+=	-Dmagick=disabled
.endif

.include <bsd.port.mk>
