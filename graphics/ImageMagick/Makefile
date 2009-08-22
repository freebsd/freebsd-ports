# New ports collection makefile for:	ImageMagick
# Date created:		15 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ImageMagick
DISTVERSION=	6.5.4-10
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	ftp://ftp.imagemagick.org/pub/ImageMagick/ \
		SF/${PORTNAME:L}/${PORTNAME}/00-6.5.4		 \

		ftp://ftp.nluug.nl/pub/ImageMagick/ \

		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/


MAINTAINER=	mm@FreeBSD.org
COMMENT=	Image processing tools

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_AUTOTOOLS=	libltdl:22
# For some reason, using our libtool breaks the build into pieces:
#USE_AUTOTOOLS+=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-shared --without-dps
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

MAN1=		ImageMagick.1 Magick++-config.1 Magick-config.1 Wand-config.1 \
		animate.1 conjure.1 compare.1 composite.1 convert.1 display.1 \
		MagickCore-config.1 MagickWand-config.1 \
		identify.1 import.1 mogrify.1 montage.1 stream.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

PLIST_SUB+=	PORTVERSION=${PORTVERSION:R}

OPTIONS=	X11				"X11 support" on \
		IMAGEMAGICK_TESTS	"Run bundled self-tests after build" on \
		IMAGEMAGICK_OPENMP	"OpenMP for SMP (needs threads)" off \
		IMAGEMAGICK_PERL		"Perl support" on \
		IMAGEMAGICK_MODULES		"Modules support" off \
		IMAGEMAGICK_BZLIB		"Bzlib support" on \
		IMAGEMAGICK_16BIT_PIXEL		"16bit pixel support" on \
		IMAGEMAGICK_DJVU	"DJVU format support (needs threads)" off \
		IMAGEMAGICK_LCMS		"LCMS support" on \
		IMAGEMAGICK_HDRI		"High Dynamic Range Images (HDRI)" off \
		IMAGEMAGICK_TTF			"Freetype support" on \
		IMAGEMAGICK_FONTCONFIG		"Fontconfig support" on \
		IMAGEMAGICK_JPEG		"JPG format support" on \
		IMAGEMAGICK_OPENEXR		"OpenEXR support (needs threads)" off \
		IMAGEMAGICK_PNG			"PNG format support" on \
		IMAGEMAGICK_TIFF		"TIFF format support" on \
		IMAGEMAGICK_FPX			"FPX format support" on \
		IMAGEMAGICK_JBIG		"JBIG format support" on \
		IMAGEMAGICK_JPEG2000		"JPEG2000 format support" on \
		IMAGEMAGICK_DOT		"GraphViz dot graphs support" off \
		IMAGEMAGICK_WMF			"WMF format support" off \
		IMAGEMAGICK_SVG			"SVG format support" off \
		IMAGEMAGICK_PDF			"PDF format support" on \
		IMAGEMAGICK_GSLIB	"libgs (Postscript SHLIB) support" off \
		IMAGEMAGICK_LQR		"Liquid Rescale support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMAGEMAGICK_PDF) && defined(WITH_GHOSTSCRIPT_VER) && $(WITH_GHOSTSCRIPT_VER) == "7"
IGNORE=		support for the PDF format requires ghostscript 8 and higher
.endif

.if defined(WITH_IMAGEMAGICK_HDRI)
BROKEN=			hdri support broken, disable in options
CONFIGURE_ARGS+=	--enable-hdri
.else
CONFIGURE_ARGS+=	--disable-hdri
.endif

.if defined(WITH_IMAGEMAGICK_OPENMP)
CONFIGURE_ARGS+=	--enable-openmp
.else
CONFIGURE_ARGS+=	--disable-openmp
.endif

.if !defined(WITHOUT_IMAGEMAGICK_PERL)
CONFIGURE_ARGS+=	--with-perl=${PERL5}
PLIST_SUB+=		WITH_PERL=''
MAN3=			Image::Magick.3
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
.else
CONFIGURE_ARGS+=	--without-perl
PLIST_SUB+=		WITH_PERL='@comment '
.endif

# PerlMagick not works with threads, if perl is not threaded, and vice versa
.if defined(WITH_IMAGEMAGICK_THREADS) || \
    (!defined(WITHOUT_IMAGEMAGICK_PERL) && \
     defined(PERL_THREADED) && ${PERL_THREADED} == "true")
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ENV+=		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
LDFLAGS+=		${PTHREAD_LIBS}
WITH_IMAGEMAGICK_THREADS=yes
.else
CONFIGURE_ARGS+=	--without-threads
.undef WITH_IMAGEMAGICK_THREADS
.if defined(WITH_IMAGEMAGICK_DJVU)
.	undef WITH_IMAGEMAGICK_DJVU
.endif
.endif

# Faster, but poor quality
.if defined(WITHOUT_IMAGEMAGICK_16BIT_PIXEL)
CONFIGURE_ARGS+=	--with-quantum-depth=8
PLIST_SUB+=		QBIT='Q8'
.else
PLIST_SUB+=		QBIT='Q16'
.endif

.if defined(WITH_WINDOWS_FONT_DIR)
CONFIGURE_ARGS+=	--with-windows-font-dir=${WITH_WINDOWS_FONT_DIR}
.endif

# Loadable coders, smaller executable, but PerlMagick not really works
# ('make test' there works)
.if defined(WITH_IMAGEMAGICK_MODULES)
CONFIGURE_ARGS+=	--with-modules
PLIST_SUB+=		MODULES=''
.else
CONFIGURE_ARGS+=	--without-modules
PLIST_SUB+=		MODULES='@comment '
.endif

.if !defined(WITHOUT_IMAGEMAGICK_OPENEXR)
LIB_DEPENDS+=		IlmImf:${PORTSDIR}/graphics/OpenEXR
PLIST_SUB+=		OPENEXR=""
.else
CONFIGURE_ARGS+=	--without-openexr
PLIST_SUB+=		OPENEXR="@comment "
.endif

.if !defined(WITHOUT_IMAGEMAGICK_DJVU)
LIB_DEPENDS+=		djvulibre:${PORTSDIR}/graphics/djvulibre-nox11
PLIST_SUB+=		DJVU=""
.else
CONFIGURE_ARGS+=	--without-djvu
PLIST_SUB+=		DJVU="@comment "
.endif

.if !defined(WITHOUT_IMAGEMAGICK_JPEG)
LIB_DEPENDS+=		jpeg:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=		JPEG=""
.else
CONFIGURE_ARGS+=	--without-jpeg
PLIST_SUB+=		JPEG="@comment "
.endif

.if !defined(WITHOUT_IMAGEMAGICK_PNG)
LIB_DEPENDS+=		png:${PORTSDIR}/graphics/png
PLIST_SUB+=		PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=		PNG="@comment "
.endif

.if !defined(WITHOUT_IMAGEMAGICK_TIFF)
LIB_DEPENDS+=		tiff:${PORTSDIR}/graphics/tiff
PLIST_SUB+=		TIFF=""
.else
CONFIGURE_ARGS+=	--without-tiff
PLIST_SUB+=		TIFF="@comment "
.endif

.if defined(WITH_IMAGEMAGICK_GSLIB)
CONFIGURE_ARGS+=	--with-gslib
USE_GHOSTSCRIPT=	yes
.else
CONFIGURE_ARGS+=	--without-gslib
.endif

.if !defined(WITHOUT_IMAGEMAGICK_LQR)
CONFIGURE_ARGS+=	--with-lqr
LIB_DEPENDS+=		lqr-1.3:${PORTSDIR}/graphics/liblqr-1
.else
CONFIGURE_ARGS+=	--without-lqr
.endif

# Produce BZip compressed MIFF images
.if defined(WITHOUT_IMAGEMAGICK_BZLIB)
CONFIGURE_ARGS+=	--without-bzlib
.endif

# FPX (FlashPIX) images
.if !defined(WITHOUT_IMAGEMAGICK_FPX)
LIB_DEPENDS+=		fpx.[2-9]:${PORTSDIR}/graphics/libfpx
CONFIGURE_ARGS+=	--with-fpx
PLIST_SUB+=		FPX=""
.else
CONFIGURE_ARGS+=	--without-fpx
PLIST_SUB+=		FPX="@comment "
.endif

# JBIG images (lossless compression for bi-level images)
.if !defined(WITHOUT_IMAGEMAGICK_JBIG)
LIB_DEPENDS+=		jbig:${PORTSDIR}/graphics/jbigkit
PLIST_SUB+=		JBIG=""
.else
CONFIGURE_ARGS+=	--without-jbig
PLIST_SUB+=		JBIG="@comment "
.endif

# JPEG2000 images (wavelet-based lossy compression)
.if !defined(WITHOUT_IMAGEMAGICK_JPEG2000)
LIB_DEPENDS+=		jasper:${PORTSDIR}/graphics/jasper
PLIST_SUB+=		JPEG2000=""
.else
CONFIGURE_ARGS+=	--without-jp2
PLIST_SUB+=		JPEG2000="@comment "
.endif

# GraphViz dot graphs
.if defined(WITH_IMAGEMAGICK_DOT)
LIB_DEPENDS+=		gvc:${PORTSDIR}/graphics/graphviz
CFLAGS+=		-I${LOCALBASE}/include/graphviz
LDFLAGS+=		-L${LOCALBASE}/lib/graphviz
.else
CONFIGURE_ARGS+=	--without-gvc
.endif

# LCMS (Little CMS) color management
.if !defined(WITHOUT_IMAGEMAGICK_LCMS)
LIB_DEPENDS+=		lcms:${PORTSDIR}/graphics/lcms
.else
CONFIGURE_ARGS+=	--without-lcms
.endif

# Freetype (TrueType Font) support
.if !defined(WITHOUT_IMAGEMAGICK_TTF)
LIB_DEPENDS+=		freetype:${PORTSDIR}/print/freetype2
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

# Fontconfig support
.if !defined(WITHOUT_IMAGEMAGICK_FONTCONFIG)
LIB_DEPENDS+=		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
CONFIGURE_ARGS+=	--with-fontconfig
CONFIGURE_ENV+=		FONTCONFIG_CFLAGS="-I${LOCALBASE}/include" \
			FONTCONFIG_LIBS="-L${LOCALBASE}/lib"
MAKE_ENV+=		FONTCONFIG_CFLAGS="-I${LOCALBASE}/include"
.else
CONFIGURE_ARGS+=	--without-fontconfig
.endif

# WMF (Windows Meta File) images
.if defined(WITH_IMAGEMAGICK_WMF)
LIB_DEPENDS+=		wmf:${PORTSDIR}/graphics/libwmf
CONFIGURE_ARGS+=	--with-wmf=yes
PLIST_SUB+=		WMF=""
.else
CONFIGURE_ARGS+=	--without-wmf
PLIST_SUB+=		WMF="@comment "
.endif

# SVG (Scalable Vector Graphics) images and MSL (Magick Scripting Language)
# both require XML
.if defined(WITH_IMAGEMAGICK_SVG) || !defined(WITHOUT_IMAGEMAGICK_MSL)
USE_GNOME+=		libxml2
CONFIGURE_ARGS+=	--with-xml
.else
CONFIGURE_ARGS+=	--without-xml
.endif

# SVG (Scalable Vector Graphics) requires X11
.if defined(WITH_IMAGEMAGICK_SVG) && !defined(WITHOUT_X11)
LIB_DEPENDS+=		rsvg-2:${PORTSDIR}/graphics/librsvg2
CONFIGURE_ARGS+=	--with-rsvg
CONFIGURE_ENV+=		RSVG_CFLAGS="-I${LOCALBASE}/include/librsvg-2" \
			RSVG_LIBS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--without-rsvg
.endif

# PDF (Adobe Portable Document Format) support
.if !defined(WITHOUT_IMAGEMAGICK_PDF)
USE_GHOSTSCRIPT=	yes
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX+=		-nox11
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11='@comment '
.else
CONFLICTS+=		display-[0-9]*
CONFIGURE_ARGS+=	--with-x
USE_XORG=		xext xt
PLIST_SUB+=		X11=''
.endif

.if ${ARCH} == sparc64 && ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install
.else
INSTALL_TARGET=	install install-data-html
.endif

#.if ${OSVERSION} >= 800000
#WITHOUT_IMAGEMAGICK_TESTS=yes
#.endif

.if ${ARCH} == sparc64
WITHOUT_IMAGEMAGICK_TESTS=yes
.endif

post-patch:
# prevent perllocal.pod from being written
	@${REINPLACE_CMD} -e '/PERL/s|install && \\$$|pure_install \&\& \\|' ${WRKSRC}/Makefile.in	
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
	@${PERL} -pi -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/ltdl/ltdl.c
	@${PERL} -pi -e 's|timestamp: %ld|timestamp: %d|g' \
		${WRKSRC}/magick/xwindow.c
.if defined(WITH_IMAGEMAGICK_THREADS)
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
.if defined(WITH_IMAGEMAGICK_SVG) && defined(WITHOUT_X11)
	@${ECHO_CMD} "WARNING: SVG support requires X11, building without SVG."
.endif
.if defined(WITH_IMAGEMAGICK_DJVU) && !defined(WITH_IMAGEMAGICK_THREADS)
	@${ECHO_CMD} "WARNING: DjVu requires threads and will not be supported."
.endif
#.if ${OSVERSION} >= 800000
#	@${ECHO_CMD} "WARNING: constitute (cmy) tests fail on 8.x. Disabling tests."
#.endif

post-install:
.if defined(WITHOUT_IMAGEMAGICK_16BIT_PIXEL)
	@${TOUCH} ${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-Q8/coders/.keep
	@${TOUCH} ${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-Q8/filters/.keep
.else
	@${TOUCH} ${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-Q16/coders/.keep
	@${TOUCH} ${PREFIX}/lib/ImageMagick-${PORTVERSION:R}/modules-Q16/filters/.keep
.endif

test check:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} limits -m 20m ${MAKE} check

.if !defined(WITHOUT_IMAGEMAGICK_TESTS)
.	for m in TTF
.		if defined(WITHOUT_IMAGEMAGICK_$m)
WITHOUT_IMAGEMAGICK_TESTS=yes
.		endif
.	endfor
.endif
.if !defined(WITHOUT_IMAGEMAGICK_TESTS)
.	for m in MODULES HDRI
.		if defined(WITH_IMAGEMAGICK_$m)
WITHOUT_IMAGEMAGICK_TESTS=yes
.		endif
.	endfor
.endif

.if defined(WITH_IMAGEMAGICK_TESTS) && !defined(WITHOUT_IMAGEMAGICK_TESTS)
# jpeg-7 fails in ValidateImageFormatsOnDisk
.if defined(WITH_IMAGEMAGICK_TEST_JPEG7)
post-build:	test
.endif
.endif

.include <bsd.port.post.mk>
