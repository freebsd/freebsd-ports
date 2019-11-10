# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vips
PORTVERSION=	8.8.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/libvips/libvips/releases/download/v${PORTVERSION}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Free image processing system

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgirepository-1.0.so:devel/gobject-introspection \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2

USES=		compiler:c++11-lang cpe gettext gmake gnome libtool \
		pathfix pkgconfig python shebangfix

SHEBANG_FILES=	tools/vips-${PORTVERSION:R} tools/vipsprofile
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-nifti \
			--without-openslide \
			--without-pdfium \
			--without-imagequant

INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS_DEFINE=		DOCS X11 GSF FFTW ORC LCMS2 OPENEXR HEIF POPPLER LIBRSVG2 MATIO CFITSIO WEBP PANGO TIFF GIF PNG JPEG LIBEXIF
OPTIONS_RADIO=		MAGICK
OPTIONS_RADIO_MAGICK=	IMAGEMAGICK GRAPHMAGICK
OPTIONS_DEFAULT=	X11 GSF FFTW ORC LCMS2 OPENEXR HEIF POPPLER LIBRSVG2 MATIO CFITSIO WEBP PANGO TIFF GIF PNG JPEG LIBEXIF IMAGEMAGICK

DOCS_CONFIGURE_ENABLE=	gtk-doc gtk-doc-html
DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc

X11_CONFIGURE_WITH=	x

IMAGEMAGICK_CONFIGURE_ON=	--with-magickpackage=MagickCore
GRAPHMAGICK_CONFIGURE_ON=	--with-magickpackage=GraphicsMagick

GSF_DESC=		Structured file formats support
GSF_CONFIGURE_WITH=	gsf
GSF_USE=		GNOME=libgsf

FFTW_CONFIGURE_WITH=	fftw
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3

ORC_DESC=		ORC language support
ORC_CONFIGURE_WITH=	orc
ORC_LIB_DEPENDS=	liborc-0.4.so:devel/orc

LCMS2_CONFIGURE_WITH=	lcms
LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2

OPENEXR_CONFIGURE_WITH=	OpenEXR
OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr \
			libImath.so:graphics/ilmbase

HEIF_DESC=		HEIF image format support
HEIF_CONFIGURE_WITH=	heif
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif

POPPLER_CONFIGURE_WITH=	poppler
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_USE=		GNOME=cairo

LIBRSVG2_CONFIGURE_WITH=rsvg
LIBRSVG2_USE=		GNOME=librsvg2 GNOME=cairo

MATIO_DESC=		Matlab MAT format support
MATIO_CONFIGURE_WITH=	matio
MATIO_LIB_DEPENDS=	libmatio.so:math/matio \
			libhdf5.so:science/hdf5

CFITSIO_CONFIGURE_WITH=	cfitsio
CFITSIO_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio

WEBP_CONFIGURE_WITH=	libwebp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

PANGO_CONFIGURE_WITH=	pangoft2
PANGO_USE=		GNOME=pango

TIFF_CONFIGURE_WITH=	tiff
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

GIF_CONFIGURE_WITH=	giflib
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib

PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

JPEG_CONFIGURE_WITH=	jpeg
JPEG_USES=		jpeg

LIBEXIF_CONFIGURE_WITH=	libexif
LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
. if ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=		libMagickCore-7.so:graphics/ImageMagick7
. else
LIB_DEPENDS+=		libMagickCore-7.so:graphics/ImageMagick7-nox11
. endif
.elif ${PORT_OPTIONS:MGRAPHMAGICK}
LIB_DEPENDS+=		libGraphicsMagick.so:graphics/GraphicsMagick
.else
CONFIGURE_ARGS+=	--without-magick
.endif

.include <bsd.port.mk>
