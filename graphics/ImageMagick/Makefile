# $FreeBSD$

PORTNAME=	ImageMagick
DISTVERSION=	6.8.9-4
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.imagemagick.org/download/ \
		http://www.imagemagick.org/download/legacy/ \
		http://servingzone.com/mirrors/ImageMagick/ \
		http://mirror.checkdomain.de/imagemagick/ \
		http://image_magick.veidrodis.com/image_magick/ \
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

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Image processing tools

#LICENSE=	APACHE20

# This port uses .la files, keep libtool:keepla! (magick/module.c)
USES=		gmake libtool:keepla pathfix perl5 pkgconfig shebangfix tar:xz
SHEBANG_FILES=	www/source/examples.pl
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKE=${MAKE_CMD}
CONFIGURE_ARGS=	--without-dps \
		--without-lcms
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SAMPLE_FILES=	coder.xml colors.xml delegates.xml log.xml magic.xml mime.xml \
		policy.xml quantization-table.xml thresholds.xml type-dejavu.xml \
		type-ghostscript.xml type-windows.xml type.xml


PLIST_SUB=	PORTVERSION=${PORTVERSION:R}

OPTIONS_DEFINE=	BZIP2 DOCS DJVU FFTW FONTCONFIG FPX FREETYPE \
		GRAPHVIZ GSLIB JPEG2000 JBIG JPEG LCMS2 LZMA LQR MODULES \
		OPENEXR OPENMP PANGO PDF PERL PNG SVG TESTS TIFF WEBP WMF \
		THREADS X11
OPTIONS_DEFAULT=	16BIT_PIXEL BZIP2 FFTW FONTCONFIG FPX FREETYPE \
		JPEG2000 JBIG JPEG LCMS2 LZMA LQR MODULES PDF PERL PNG SVG \
		TIFF WEBP WMF THREADS X11
OPTIONS_GROUP=	HALFSUPPORTED
OPTIONS_GROUP_HALFSUPPORTED=	16BIT_PIXEL HDRI

HALFSUPPORTED_DESC=	Half supported options (see help dialog)
16BIT_PIXEL_DESC=	16bit pixel support
JPEG2000_DESC=		OpenJPEG 2000 support via openjpeg
DJVU_DESC=		DJVU format support (needs THREADS)
GSLIB_DESC=		libgs (Postscript SHLIB) support
HDRI_DESC=		High dynamic range images support
MODULES_DESC=		Modules support
TESTS_DESC=		Run bundled self-tests after build

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHDRI}
CONFIGURE_ARGS+=	--enable-hdri
_HDRI=HDRI
.else
CONFIGURE_ARGS+=	--disable-hdri
_HDRI=""
.endif
PLIST_SUB+=	HDRI=${_HDRI}

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
CONFIGURE_ARGS+=	--with-perl=${PERL5} \
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
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}"
LDFLAGS+=		${PTHREAD_LIBS}
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

.if ${PORT_OPTIONS:M16BIT_PIXEL}
_QBIT=Q16
.else
# Faster, but poor quality
CONFIGURE_ARGS+=	--with-quantum-depth=8
_QBIT=Q8
.endif
PLIST_SUB+=		QBIT=${_QBIT}

.if defined(WITH_WINDOWS_FONT_DIR)
CONFIGURE_ARGS+=	--with-windows-font-dir=${WITH_WINDOWS_FONT_DIR}
.endif

# Loadable coders, smaller executable, but PerlMagick not really works
# ('make test' there works)
.if ${PORT_OPTIONS:MMODULES}
CONFIGURE_ARGS+=	--with-modules
PLIST_SUB+=		MODULES=''
.else
CONFIGURE_ARGS+=	--without-modules
PLIST_SUB+=		MODULES='@comment '
.endif

.if ${PORT_OPTIONS:MOPENEXR}
. if ${_IMAGEMAGICK_THREADS} == "no"
IGNORE=OpenEXR requires threads. ${_IMAGEMAGICK_THREADS_IGNORE_MSG}
. else
LIB_DEPENDS+=		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
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
LIB_DEPENDS+=		libdjvulibre.so:${PORTSDIR}/graphics/djvulibre
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--without-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=		libjpeg.so:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=		JPEG=""
.else
CONFIGURE_ARGS+=	--without-jpeg
PLIST_SUB+=		JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=		libpng15.so:${PORTSDIR}/graphics/png
PLIST_SUB+=		PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=		PNG="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=		libtiff.so:${PORTSDIR}/graphics/tiff
PLIST_SUB+=		TIFF=""
.else
CONFIGURE_ARGS+=	--without-tiff
PLIST_SUB+=		TIFF="@comment "
.endif

.if ${PORT_OPTIONS:MGSLIB}
CONFIGURE_ARGS+=	--with-gslib
USE_GHOSTSCRIPT=	yes
.else
CONFIGURE_ARGS+=	--without-gslib
.endif

.if ${PORT_OPTIONS:MLQR}
CONFIGURE_ARGS+=	--with-lqr
LIB_DEPENDS+=		liblqr-1.so:${PORTSDIR}/graphics/liblqr-1
.else
CONFIGURE_ARGS+=	--without-lqr
.endif

.if ${PORT_OPTIONS:MFFTW}
CONFIGURE_ARGS+=	--with-fftw
LIB_DEPENDS+=		libfftw3.so:${PORTSDIR}/math/fftw3
.else
CONFIGURE_ARGS+=	--without-fftw
.endif

# Produce BZip compressed MIFF images
.if empty(PORT_OPTIONS:MBZIP2)
CONFIGURE_ARGS+=	--without-bzlib
.endif

# FPX (FlashPIX) images
.if ${PORT_OPTIONS:MFPX}
LIB_DEPENDS+=		libfpx.so:${PORTSDIR}/graphics/libfpx
CONFIGURE_ARGS+=	--with-fpx
PLIST_SUB+=		FPX=""
.else
CONFIGURE_ARGS+=	--without-fpx
PLIST_SUB+=		FPX="@comment "
.endif

# JBIG images (lossless compression for bi-level images)
.if ${PORT_OPTIONS:MJBIG}
LIB_DEPENDS+=		libjbig.so:${PORTSDIR}/graphics/jbigkit
PLIST_SUB+=		JBIG=""
.else
CONFIGURE_ARGS+=	--without-jbig
PLIST_SUB+=		JBIG="@comment "
.endif

# JPEG2000 images (wavelet-based lossy compression)
.if ${PORT_OPTIONS:MJPEG2000}
LIB_DEPENDS+=		libopenjp2.so:${PORTSDIR}/graphics/openjpeg
PLIST_SUB+=		JPEG2000=""
.else
CONFIGURE_ARGS+=	--without-openjp2
PLIST_SUB+=		JPEG2000="@comment "
.endif

# GraphViz dot graphs
.if ${PORT_OPTIONS:MGRAPHVIZ}
LIB_DEPENDS+=		libgvc.so:${PORTSDIR}/graphics/graphviz
CFLAGS+=		-I${LOCALBASE}/include/graphviz
LDFLAGS+=		-L${LOCALBASE}/lib/graphviz
.else
CONFIGURE_ARGS+=	--without-gvc
.endif

# LZMA support
# needs manula override for base system...
.if ! ${PORT_OPTIONS:MLZMA}
CONFIGURE_ARGS+=	--without-lzma
.endif

# LCMS (Little CMS) color management version 2 and 1 (mutually exclusive)
.if ${PORT_OPTIONS:MLCMS2}
LIB_DEPENDS+=		liblcms2.so:${PORTSDIR}/graphics/lcms2
.else
CONFIGURE_ARGS+=	--without-lcms2
.endif

# Freetype (TrueType Font) support
.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=		libfreetype.so:${PORTSDIR}/print/freetype2
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

# Webp support
.if ${PORT_OPTIONS:MWEBP}
LIB_DEPENDS+=		libwebp.so:${PORTSDIR}/graphics/webp
CONFIGURE_ARGS+=	--with-webp
PLIST_SUB+=		WEBP=""
.else
CONFIGURE_ARGS+=	--without-webp
PLIST_SUB+=		WEBP="@comment "
.endif

# Fontconfig support
.if ${PORT_OPTIONS:MFONTCONFIG}
LIB_DEPENDS+=		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
CONFIGURE_ARGS+=	--with-fontconfig
CONFIGURE_ENV+=		FONTCONFIG_CFLAGS="-I${LOCALBASE}/include" \
			FONTCONFIG_LIBS="-L${LOCALBASE}/lib"
MAKE_ENV+=		FONTCONFIG_CFLAGS="-I${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=	--without-fontconfig
.endif

# WMF (Windows Meta File) images
.if ${PORT_OPTIONS:MWMF}
. if ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=		libwmf.so:${PORTSDIR}/graphics/libwmf
. else
LIB_DEPENDS+=		libwmf.so:${PORTSDIR}/graphics/libwmf-nox11
. endif
CONFIGURE_ARGS+=	--with-wmf=yes
CFLAGS+=		-I${LOCALBASE}/include/freetype2
PLIST_SUB+=		WMF=""
.else
CONFIGURE_ARGS+=	--without-wmf
PLIST_SUB+=		WMF="@comment "
.endif

# SVG (Scalable Vector Graphics) requires both libxml2 and X11
.if ${PORT_OPTIONS:MSVG} && ${PORT_OPTIONS:MX11}
USE_GNOME+=		libxml2
LIB_DEPENDS+=		librsvg-2.so:${PORTSDIR}/graphics/librsvg2
CONFIGURE_ARGS+=	--with-rsvg --with-xml
CONFIGURE_ENV+=		RSVG_CFLAGS="-I${LOCALBASE}/include/librsvg-2.0" \
			RSVG_LIBS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--without-rsvg --without-xml
.endif

# Pango support
.if ${PORT_OPTIONS:MPANGO} && ${PORT_OPTIONS:MX11}
USE_GNOME+=		pango
PLIST_SUB+=		PANGO=""
.else
CONFIGURE_ARGS+=	--without-pango
PLIST_SUB+=		PANGO="@comment "
.endif

# PDF (Adobe Portable Document Format) support
.if ${PORT_OPTIONS:MPDF}
USE_GHOSTSCRIPT=	yes
.endif

.if ! ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=	--without-x
CONFLICTS+=		ImageMagick-6*
PLIST_SUB+=		X11='@comment '
PKGNAMESUFFIX=		-nox11
.else
CONFLICTS+=		ImageMagick-nox11-6*
CONFLICTS+=		display-[0-9]*
CONFIGURE_ARGS+=	--with-x
USE_XORG=		xext xt
PLIST_SUB+=		X11=''
.endif

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install-strip install-docDATA install-data-html
.else
INSTALL_TARGET=	install-strip
.endif

.if ${PORT_OPTIONS:MTESTS}
USE_GHOSTSCRIPT_BUILD=yes
.endif

pre-configure:
.if defined(_IMAGEMAGICK_THREADS_PERL_MSG)
	@${ECHO_CMD} '###################################################################'
	@${ECHO_CMD} NOTICE: ${_IMAGEMAGICK_THREADS_PERL_MSG}. Building ImageMagick ${_IMAGEMAGICK_THREADS_MSG}.
	@${ECHO_CMD} '###################################################################'
.endif

.if ${PORT_OPTIONS:MSVG} && ! ${PORT_OPTIONS:MX11}
	@${ECHO_CMD} NOTICE: SVG format support disabled, requires X11
.endif

post-install: test
.if ${PORT_OPTIONS:MPERL}
	@${RM} -f ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH}/perllocal.pod*
	@${RM} -f ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Image/Magick/.packlist
.endif
.if ${PORT_OPTIONS:MMODULES}
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-${_QBIT}${_HDRI}/coders/.keep
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-${_QBIT}${_HDRI}/filters/.keep
.endif
.for i in ${SAMPLE_FILES}
	@${MV} ${STAGEDIR}${PREFIX}/etc/ImageMagick-6/${i} \
		${STAGEDIR}${PREFIX}/etc/ImageMagick-6/${i}.sample
.endfor

test check:
.if ${PORT_OPTIONS:MTESTS}
	-cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} limits -m 20m ${MAKE} check
.endif

.include <bsd.port.mk>
