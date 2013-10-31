# $FreeBSD$

PORTNAME=	ImageMagick
PORTREVISION=	1
DISTVERSION=	6.8.0-7
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.imagemagick.org/download/ \
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

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Image processing tools

LICENSE=	AL2

USES=		pkgconfig:both pathfix perl5
USE_XZ=		yes
USE_PERL5=	run build patch
WANT_GNOME=	yes
USE_AUTOTOOLS=	libltdl
NO_STAGE=	yes
# For some reason, using our libtool breaks the build into pieces:
#USE_AUTOTOOLS+=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --without-dps --without-lcms
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		ImageMagick.1 Magick++-config.1 Magick-config.1 Wand-config.1 \
		animate.1 conjure.1 compare.1 composite.1 convert.1 display.1 \
		MagickCore-config.1 MagickWand-config.1 \
		identify.1 import.1 mogrify.1 montage.1 stream.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${PORTVERSION:R}

OPTIONS_DEFINE=	16BIT_PIXEL BZIP2 DOCS DJVU FFTW FONTCONFIG FPX FREETYPE \
		GRAPHVIZ GSLIB HDRI JASPER JBIG JPEG LCMS2 LZMA LQR MODULES \
		OPENEXR OPENMP PANGO PDF PERL PNG SVG TESTS TIFF WEBP WMF \
		THREADS
OPTIONS_DEFAULT=	16BIT_PIXEL BZIP2 FFTW FONTCONFIG FPX FREETYPE \
		JASPER JBIG JPEG LCMS2 LZMA LQR MODULES PDF PERL PNG SVG \
		TIFF WEBP WMF
16BIT_PIXEL_DESC=	16bit pixel support
DJVU_DESC=		DJVU format support (needs THREADS)
GSLIB_DESC=		libgs (Postscript SHLIB) support
HDRI_DESC=		High dynamic range images support
MODULES_DESC=		Modules support
TESTS_DESC=		Run bundled self-tests after build

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHDRI}
CONFIGURE_ARGS+=	--enable-hdri
.else
CONFIGURE_ARGS+=	--disable-hdri
.endif

.if ${PORT_OPTIONS:MTHREADS}
_IMAGEMAGICK_THREADS=yes
_IMAGEMAGICK_THREADS_MSG=with threads
PERL_THREADED!=	${SH} -c 'case `perl --version` in *freebsd-thread*) ${ECHO_CMD} yes ;; esac'
.else
_IMAGEMAGICK_THREADS=no
_IMAGEMAGICK_THREADS_MSG=without threads
_IMAGEMAGICK_THREADS_IGNORE_MSG=. Define WITH_THREADS
.endif

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--with-perl=${PERL5}
PLIST_SUB+=		WITH_PERL=''
MAN3=			Image::Magick.3
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VER}
# PerlMagick not works with threads, if perl is not threaded, and vice versa
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
. endif
.else
CONFIGURE_ARGS+=	--disable-openmp
.endif

# Faster, but poor quality
.if ${PORT_OPTIONS:M16BIT_PIXEL}
PLIST_SUB+=		QBIT='Q16'
.else
CONFIGURE_ARGS+=	--with-quantum-depth=8
PLIST_SUB+=		QBIT='Q8'
.endif

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
LIB_DEPENDS+=		IlmImf:${PORTSDIR}/graphics/OpenEXR
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
LIB_DEPENDS+=		djvulibre:${PORTSDIR}/graphics/djvulibre
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--without-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=		jpeg:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=		JPEG=""
.else
CONFIGURE_ARGS+=	--without-jpeg
PLIST_SUB+=		JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=		png15:${PORTSDIR}/graphics/png
PLIST_SUB+=		PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=		PNG="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=		tiff:${PORTSDIR}/graphics/tiff
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
LIB_DEPENDS+=		lqr-1:${PORTSDIR}/graphics/liblqr-1
.else
CONFIGURE_ARGS+=	--without-lqr
.endif

.if ${PORT_OPTIONS:MFFTW}
CONFIGURE_ARGS+=	--with-fftw
LIB_DEPENDS+=		fftw3:${PORTSDIR}/math/fftw3
.else
CONFIGURE_ARGS+=	--without-fftw
.endif

# Produce BZip compressed MIFF images
.if empty(PORT_OPTIONS:MBZIP2)
CONFIGURE_ARGS+=	--without-bzlib
.endif

# FPX (FlashPIX) images
.if ${PORT_OPTIONS:MFPX}
LIB_DEPENDS+=		fpx.[2-9]:${PORTSDIR}/graphics/libfpx
CONFIGURE_ARGS+=	--with-fpx
PLIST_SUB+=		FPX=""
.else
CONFIGURE_ARGS+=	--without-fpx
PLIST_SUB+=		FPX="@comment "
.endif

# JBIG images (lossless compression for bi-level images)
.if ${PORT_OPTIONS:MJBIG}
LIB_DEPENDS+=		jbig:${PORTSDIR}/graphics/jbigkit
PLIST_SUB+=		JBIG=""
.else
CONFIGURE_ARGS+=	--without-jbig
PLIST_SUB+=		JBIG="@comment "
.endif

# JPEG2000 images (wavelet-based lossy compression)
.if ${PORT_OPTIONS:MJASPER}
LIB_DEPENDS+=		jasper:${PORTSDIR}/graphics/jasper
PLIST_SUB+=		JPEG2000=""
.else
CONFIGURE_ARGS+=	--without-jp2
PLIST_SUB+=		JPEG2000="@comment "
.endif

# GraphViz dot graphs
.if ${PORT_OPTIONS:MGRAPHVIZ}
LIB_DEPENDS+=		gvc:${PORTSDIR}/graphics/graphviz
CFLAGS+=		-I${LOCALBASE}/include/graphviz
LDFLAGS+=		-L${LOCALBASE}/lib/graphviz
.else
CONFIGURE_ARGS+=	--without-gvc
.endif

# LZMA support
.if ${PORT_OPTIONS:MLZMA}
. if (${OSVERSION} >= 900000 && ${OSVERSION} < 900012) || (${OSVERSION} < 800505)
LIB_DEPENDS+=		lzma:${PORTSDIR}/archivers/xz
. endif
.else
CONFIGURE_ARGS+=	--without-lzma
.endif

# LCMS (Little CMS) color management version 2 and 1 (mutually exclusive)
.if ${PORT_OPTIONS:MLCMS2}
LIB_DEPENDS+=		lcms2:${PORTSDIR}/graphics/lcms2
.else
CONFIGURE_ARGS+=	--without-lcms2
.endif

# Freetype (TrueType Font) support
.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=		freetype:${PORTSDIR}/print/freetype2
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

# Webp support
.if ${PORT_OPTIONS:MWEBP}
LIB_DEPENDS+=		webp:${PORTSDIR}/graphics/webp
CONFIGURE_ARGS+=	--with-webp
PLIST_SUB+=		WEBP=""
.else
CONFIGURE_ARGS+=	--without-webp
PLIST_SUB+=		WEBP="@comment "
.endif

# Fontconfig support
.if ${PORT_OPTIONS:MFONTCONFIG}
LIB_DEPENDS+=		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
CONFIGURE_ARGS+=	--with-fontconfig
CONFIGURE_ENV+=		FONTCONFIG_CFLAGS="-I${LOCALBASE}/include" \
			FONTCONFIG_LIBS="-L${LOCALBASE}/lib"
MAKE_ENV+=		FONTCONFIG_CFLAGS="-I${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=	--without-fontconfig
.endif

# WMF (Windows Meta File) images
.if ${PORT_OPTIONS:MWMF}
. if !defined(WITHOUT_X11)
LIB_DEPENDS+=		wmf:${PORTSDIR}/graphics/libwmf
. else
LIB_DEPENDS+=		wmf:${PORTSDIR}/graphics/libwmf-nox11
. endif
CONFIGURE_ARGS+=	--with-wmf=yes
CFLAGS+=		-I${LOCALBASE}/include/freetype2
PLIST_SUB+=		WMF=""
.else
CONFIGURE_ARGS+=	--without-wmf
PLIST_SUB+=		WMF="@comment "
.endif

# SVG (Scalable Vector Graphics) requires both libxml2 and X11
.if ${PORT_OPTIONS:MSVG} && !defined(WITHOUT_X11)
USE_GNOME+=		libxml2
LIB_DEPENDS+=		rsvg-2:${PORTSDIR}/graphics/librsvg2
CONFIGURE_ARGS+=	--with-rsvg --with-xml
CONFIGURE_ENV+=		RSVG_CFLAGS="-I${LOCALBASE}/include/librsvg-2.0" \
			RSVG_LIBS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--without-rsvg --without-xml
.endif

# Pango support
.if ${PORT_OPTIONS:MPANGO} && !defined(WITHOUT_X11)
LIB_DEPENDS+=		pangocairo-1\.0:${PORTSDIR}/x11-toolkits/pango
PLIST_SUB+=		PANGO=""
.else
CONFIGURE_ARGS+=	--without-pango
PLIST_SUB+=		PANGO="@comment "
.endif

# PDF (Adobe Portable Document Format) support
.if ${PORT_OPTIONS:MPDF}
USE_GHOSTSCRIPT=	yes
.endif

.if defined(WITHOUT_X11)
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
INSTALL_TARGET=	install install-docDATA install-data-html
.else
INSTALL_TARGET=	install
.endif

# Test suite, requires installed ghostscript to pass

.if defined(PACKAGE_BUILDING) || ${PORT_OPTIONS:MTESTS}
USE_GHOSTSCRIPT_BUILD=yes
.endif

post-patch:
# prevent perllocal.pod from being written
	@${REINPLACE_CMD} -e '/PERL/s|install && \\$$|pure_install \&\& \\|' \
		-e 's/install-docDATA install-filters/install-filters/' \
		${WRKSRC}/Makefile.in
# remove the autogenerated Magick.c so it will be regenerated from
# Magick.xs on _this_ system:
	@${RM} -f ${WRKSRC}/PerlMagick/Magick.c
	@${PERL} -pi -e 's|^tagnames=|#tagnames=|g ; \
		 s|lcms/lcms.h|lcms.h|g ; \
		 s|lcms_lcms_h|lcms_h|g' ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# version neither libraries nor directories
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|pkgdocdir =.*$$|pkgdocdir = ${DOCSDIR}/|g ; \
		 s|-\$$\(VERSION\)||; \
		 s| install-data-html||g'
# do not version lib directories
	@${PERL} -pi -e 's|^(MagickLibSubdir).*$$|\1="ImageMagick"|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${PERL} -pi -e 's|lcms/lcms.h|lcms.h|g' ${WRKSRC}/magick/transform.c
#	@${PERL} -pi -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/ltdl/ltdl.c
	@${PERL} -pi -e 's|timestamp: %ld|timestamp: %d|g' \
		${WRKSRC}/magick/xwindow.c
.if ${_IMAGEMAGICK_THREADS} == "yes"
. for i in Magick++/lib/ImageMagick++.pc.in wand/Wand.pc.in magick/ImageMagick.pc.in
	@${PERL} -pi -e 's|^(Libs.+)$$|\1 ${PTHREAD_LIBS}|; \
		s|^(Cflags.+)$$|\1 ${PTHREAD_CFLAGS}|' \
		${WRKSRC}/${i}
. endfor
.endif
# deprecated gvCleanup
	@${REINPLACE_CMD} -e "s|gvCleanup|gvFreeContext|g" \
		${WRKSRC}/coders/dot.c

pre-configure:
.if defined(_IMAGEMAGICK_THREADS_PERL_MSG)
	@${ECHO_CMD} '###################################################################'
	@${ECHO_CMD} NOTICE: ${_IMAGEMAGICK_THREADS_PERL_MSG}. Building ImageMagick ${_IMAGEMAGICK_THREADS_MSG}.
	@${ECHO_CMD} '###################################################################'
.endif

.if ${PORT_OPTIONS:MSVG} && defined(WITHOUT_X11)
	@${ECHO_CMD} NOTICE: SVG format support disabled, requires X11
.endif

post-install: test
.if ${PORT_OPTIONS:MPERL}
	@${RM} -f ${PREFIX}/lib/perl5/${PERL_VER}/mach/perllocal.pod
.endif
.if ${PORT_OPTIONS:MMODULES}
. if ${PORT_OPTIONS:M16BIT_PIXEL}
	@${TOUCH} ${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-Q16/coders/.keep
	@${TOUCH} ${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-Q16/filters/.keep
. else
	@${TOUCH} ${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-Q8/coders/.keep
	@${TOUCH} ${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-Q8/filters/.keep
. endif
.endif

test check:
.if (${PORT_OPTIONS:MTESTS} || defined(PACKAGE_BUILDING))
	-cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} limits -m 20m ${MAKE} check
.endif

.include <bsd.port.post.mk>
