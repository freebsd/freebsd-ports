# $FreeBSD$

PORTNAME=	ImageMagick
DISTVERSION=	7.0.9-20
CATEGORIES=	graphics perl5
MASTER_SITES=	https://www.imagemagick.org/download/ \
		https://www.imagemagick.org/download/releases/ \
		http://servingzone.com/mirrors/ImageMagick/ \
		http://mirror.checkdomain.de/imagemagick/ \
		http://imagemagick.spd.co.il/ \
		http://www.champground.com/imagemagick/ \
		http://ftp.surfnet.nl/pub/ImageMagick/ \
		http://mirror.searchdaimon.com/ImageMagick/ \
		http://mirror.is.co.za/pub/imagemagick/ \
		http://imagemagick.mirrorcatalogs.com/ \
		ftp://ftp.imagemagick.org/pub/ImageMagick/ \
		ftp://mirror.aarnet.edu.au/pub/imagemagick/ \
		ftp://mirror.checkdomain.de/imagemagick/ \
		ftp://ftp.kddlabs.co.jp/graphics/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/imagemagick.org/ \
		ftp://ftp.nluug.nl/pub/ImageMagick/ \
		ftp://mirror.searchdaimon.com/ImageMagick/ \
		ftp://sunsite.icm.edu.pl/packages/ImageMagick/ \
		ftp://ftp.tpnet.pl/pub/graphics/ImageMagick/ \
		ftp://ftp.sunet.se/pub/multimedia/graphics/ImageMagick/ \
		ftp://ftp.is.co.za/pub/imagemagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/
PKGNAMESUFFIX=	7

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Image processing tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libltdl.so:devel/libltdl

TESTS_DEPENDS=	gsfonts>=0:print/gsfonts

# bin/Magick++-config
CONFLICTS_INSTALL=	ImageMagick ImageMagick-nox11 ImageMagick6 ImageMagick6-nox11

# This port uses .la files, keep libtool:keepla! (magick/module.c)
USES=		cpe gettext-runtime gmake gnome libtool:keepla \
		localbase pathfix perl5 pkgconfig:both shebangfix tar:xz
CPE_PRODUCT=	imagemagick
CPE_VENDOR=	imagemagick
SHEBANG_FILES=	www/source/examples.pl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKE=${MAKE_CMD}
CONFIGURE_ARGS=	--without-dps \
		--without-flif \
		--without-zstd
USE_LDCONFIG=	yes
USE_GNOME=	libxml2

SAMPLE_FILES=	colors.xml delegates.xml log.xml mime.xml policy.xml \
		quantization-table.xml thresholds.xml type-apple.xml \
		type-dejavu.xml type-ghostscript.xml type-urw-base35.xml \
		type-windows.xml type.xml

PLIST_SUB=	PORTVERSION=${PORTVERSION:R}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	BZIP2 DOCS DJVU FFTW FONTCONFIG FPX FREETYPE \
		GRAPHVIZ GSLIB JPEG2000 JBIG JPEG LCMS2 LZMA LQR MODULES \
		OPENEXR OPENMP PANGO PDF PERL PNG RAQM SVG TESTS TIFF WEBP WMF \
		THREADS X11 16BIT_PIXEL HDRI HEIF RAW
OPTIONS_DEFAULT=	16BIT_PIXEL BZIP2 FFTW FONTCONFIG FREETYPE \
		JPEG2000 JBIG JPEG LCMS2 LZMA LQR MODULES PDF PERL PNG RAQM SVG \
		TIFF WEBP WMF THREADS X11 HDRI RAW

DJVU_DESC=		DJVU format support (needs THREADS)
GSLIB_DESC=		libgs (Postscript SHLIB) support
TESTS_DESC=		Run bundled self-tests after build
#SIMD_CONFIGURE_WITH=	gcc-arch
CONFIGURE_ARGS+=	--without-gcc-arch

16BIT_PIXEL_DESC=	16bit pixel support
16BIT_PIXEL_CONFIGURE_OFF=--with-quantum-depth=8
16BIT_PIXEL_VARS=	_QBIT=Q16
16BIT_PIXEL_VARS_OFF=	_QBIT=Q8
PLIST_SUB+=		QBIT=${_QBIT}

# Produce BZip compressed MIFF images
BZIP2_DESC=		bzip2 compressed MIFF images
BZIP2_CONFIGURE_WITH=	bzlib

FFTW_CONFIGURE_WITH=	fftw
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3

FONTCONFIG_CONFIGURE_WITH=	fontconfig
FONTCONFIG_LIB_DEPENDS=		libfontconfig.so:x11-fonts/fontconfig

FREETYPE_CONFIGURE_WITH=	freetype
FREETYPE_LIB_DEPENDS=		libfreetype.so:print/freetype2

# FPX (FlashPIX) images
FPX_CONFIGURE_WITH=	fpx
FPX_LIB_DEPENDS=	libfpx.so:graphics/libfpx

GRAPHVIZ_CONFIGURE_WITH=	gvc
GRAPHVIZ_LIB_DEPENDS=	libgvc.so:graphics/graphviz
GRAPHVIZ_CFLAGS=	-I${LOCALBASE}/include/graphviz
GRAPHVIZ_LDFLAGS=	-L${LOCALBASE}/lib/graphviz

HEIF_DESC=		ISO/IEC 23008-12:2017 HEIF file format support
HEIF_CONFIGURE_WITH=	heic
HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif

HDRI_DESC=		High dynamic range images support
HDRI_CONFIGURE_ENABLE=	hdri
HDRI_VARS=		_HDRI=HDRI
HDRI_VARS_OFF=		_HDRI=""
PLIST_SUB+=		HDRI=${_HDRI}

# JBIG images (lossless compression for bi-level images)
JBIG_CONFIGURE_WITH=	jbig
JBIG_LIB_DEPENDS=	libjbig.so:graphics/jbigkit

JPEG_CONFIGURE_WITH=	jpeg
JPEG_USES=		jpeg

# JPEG2000 images (wavelet-based lossy compression)
JPEG2000_DESC=		OpenJPEG 2000 support via openjpeg
JPEG2000_CONFIGURE_WITH=openjp2
JPEG2000_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

LCMS2_CONFIGURE_WITH=	lcms
LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2

LQR_CONFIGURE_WITH=	lqr
LQR_LIB_DEPENDS=	liblqr-1.so:graphics/liblqr-1
LQR_USE=		gnome=glib20

LZMA_CONFIGURE_WITH=	lzma

# Loadable coders, smaller executable, but PerlMagick not really works
# ('make test' there works)
MODULES_DESC=		Modules support
MODULES_CONFIGURE_WITH=	modules

PANGO_CONFIGURE_WITH=	pango
PANGO_USE=		gnome=pango
PANGO_IMPLIES=		X11

PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

RAQM_DESC=		Complex text layout support
RAQM_CONFIGURE_WITH=	raqm
RAQM_LIB_DEPENDS=	libraqm.so:print/libraqm

# libraw is by default liked to lcms2, whichs also ends up in IM regardless
# of the IM LCMS option.
RAW_DESC=		RAW format support (implies the lcms2 option)
RAW_CONFIGURE_WITH=	raw
RAW_LIB_DEPENDS=	libraw_r.so:graphics/libraw
RAW_IMPLIES=		LCMS2

SVG_DESC=		SVG vector image format support (via librsvg, implies the x11 option)
SVG_CONFIGURE_WITH=	rsvg
SVG_USE=		gnome=cairo,gdkpixbuf2,librsvg2
SVG_IMPLIES=		X11

TIFF_CONFIGURE_WITH=	tiff
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

WEBP_CONFIGURE_WITH=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

X11_CONFIGURE_WITH=	x
X11_USES=		xorg
X11_USE=		xorg=ice,sm,x11,xext,xt
X11_VARS=		CONFLICTS_INSTALL+="ImageMagick7-nox11-* \
			CONFLICTS+=display-[0-9]*
X11_VARS_OFF=		CONFLICTS_INSTALL+="ImageMagick7-*" \
			PKGNAMESUFFIX=7-nox11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREADS}
_IMAGEMAGICK_THREADS=yes
_IMAGEMAGICK_THREADS_MSG=with threads
. if exists(${PERL})
PERL_THREADED!=	${SH} -c 'case `perl --version` in *freebsd-thread*) ${ECHO_CMD} yes ;; esac'; ${ECHO_CMD}
. else
# if ${PERL} doesn't exists, assume we dealing with threaded perl.
PERL_THREADED=	yes
. endif
.else
_IMAGEMAGICK_THREADS=no
_IMAGEMAGICK_THREADS_MSG=without threads
_IMAGEMAGICK_THREADS_IGNORE_MSG=. Define WITH_THREADS
.endif

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--with-perl=${PERL} \
			--with-perl-options="MAKE=${MAKE_CMD}"
PLIST_SUB+=		WITH_PERL=''
# PerlMagick does not work with threads, if perl is not threaded, and vice versa
. if defined(PERL_THREADED)
_IMAGEMAGICK_THREADS_PERL_MSG=Perl is threaded
_IMAGEMAGICK_THREADS=yes
. else
_IMAGEMAGICK_THREADS_PERL_MSG=Perl is non-threaded
_IMAGEMAGICK_THREADS_IGNORE_MSG=. ${_IMAGEMAGICK_THREADS_PERL_MSG}. Reinstall Perl with threads or undefine WITH_IMAGEMAGICK_PERL
.  if ${_IMAGEMAGICK_THREADS} == "yes"
IGNORE=${_IMAGEMAGICK_THREADS_IGNORE_MSG} or undefine WITH_THREADS
.  endif
_IMAGEMAGICK_THREADS=no
. endif
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL='@comment '
.endif

.if ${_IMAGEMAGICK_THREADS} == "yes"
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ENV+=		PTHREAD_LIBS="-lpthread"
LDFLAGS+=		-lpthread
.else
CONFIGURE_ARGS+=	--without-threads
_IMAGEMAGICK_THREADS=no
.endif

# OpenMP
.if ${PORT_OPTIONS:MOPENMP}
. if ${_IMAGEMAGICK_THREADS} == "no"
IGNORE=OpenMP requires threads${_IMAGEMAGICK_THREADS_IGNORE_MSG}
. else
CONFIGURE_ARGS+=	--enable-openmp
USES+=		compiler:openmp
. endif
.else
CONFIGURE_ARGS+=	--disable-openmp
.endif

.if defined(WITH_WINDOWS_FONT_DIR)
CONFIGURE_ARGS+=	--with-windows-font-dir=${WITH_WINDOWS_FONT_DIR}
.endif

.if ${PORT_OPTIONS:MOPENEXR}
. if ${_IMAGEMAGICK_THREADS} == "no"
IGNORE=OpenEXR requires threads. ${_IMAGEMAGICK_THREADS_IGNORE_MSG}
. else
LIB_DEPENDS+=		libIlmImf.so:graphics/openexr \
			libImath.so:graphics/ilmbase
PLIST_SUB+=		OPENEXR=""
. endif
.else
CONFIGURE_ARGS+=	--without-openexr
PLIST_SUB+=		OPENEXR="@comment "
.endif

.if ${PORT_OPTIONS:MDJVU}
. if ${_IMAGEMAGICK_THREADS} == "no"
IGNORE=DjVu requires threads${_IMAGEMAGICK_THREADS_IGNORE_MSG}
. endif
LIB_DEPENDS+=		libdjvulibre.so:graphics/djvulibre
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--without-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MGSLIB}
CONFIGURE_ARGS+=	--with-gslib
. if ${PORT_OPTIONS:MX11}
USES+=		ghostscript:x11
. else
USES+=		ghostscript
. endif
.else
CONFIGURE_ARGS+=	--without-gslib
.endif

# WMF (Windows Meta File) images
.if ${PORT_OPTIONS:MWMF}
. if ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=		libwmf.so:graphics/libwmf
. else
LIB_DEPENDS+=		libwmf.so:graphics/libwmf-nox11
. endif
CONFIGURE_ARGS+=	--with-wmf=yes
PLIST_SUB+=		WMF=""
.else
CONFIGURE_ARGS+=	--without-wmf
PLIST_SUB+=		WMF="@comment "
.endif

# PDF (Adobe Portable Document Format) support
.if ${PORT_OPTIONS:MPDF}
. if ${PORT_OPTIONS:MX11}
USES+=		ghostscript:x11
. else
USES+=		ghostscript
. endif
.endif

.if ${PORT_OPTIONS:MPDF} || ${PORT_OPTIONS:MGSLIB}
RUN_DEPENDS+=	gsfonts>=0:print/gsfonts
.endif

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install-strip install-docDATA install-data-html
.else
INSTALL_TARGET=	install-strip
.endif

.if ${PORT_OPTIONS:MTESTS}
. if ${PORT_OPTIONS:MX11}
USES+=		ghostscript:x11,build
. else
USES+=		ghostscript:build
. endif
.endif

post-patch:
# strip library name of variable parts that can change due to
# the HDRI and Q16 option
	@${REINPLACE_CMD}  -e 's|_@MAGICK_ABI_SUFFIX@||g; \
		s|\.@MAGICK_ABI_SUFFIX@||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@\.@MAGICK_ABI_SUFFIX@|@|g' \
		${WRKSRC}/PerlMagick/Makefile.PL.in \
		${WRKSRC}/PerlMagick/quantum/Makefile.PL.in \
		${WRKSRC}/Magick++/lib/Magick++.pc.in \
		${WRKSRC}/MagickCore/MagickCore.pc.in \
		${WRKSRC}/MagickWand/MagickWand.pc.in

pre-configure:
.if defined(_IMAGEMAGICK_THREADS_PERL_MSG)
	@${ECHO_CMD} '###################################################################'
	@${ECHO_CMD} NOTICE: ${_IMAGEMAGICK_THREADS_PERL_MSG}. Building ImageMagick ${_IMAGEMAGICK_THREADS_MSG}.
	@${ECHO_CMD} '###################################################################'
.endif

.if ${PORT_OPTIONS:MSVG} && ! ${PORT_OPTIONS:MX11}
	@${ECHO_CMD} NOTICE: SVG format support disabled, requires X11
.endif

post-install:
.for i in ${SAMPLE_FILES}
	@${MV} ${STAGEDIR}${PREFIX}/etc/ImageMagick-7/${i} \
		${STAGEDIR}${PREFIX}/etc/ImageMagick-7/${i}.sample
.endfor

post-install-TESTS-on: test

do-test:
	-cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} limits -m 20m ${MAKE} ${_MAKE_JOBS} check

.include <bsd.port.mk>
