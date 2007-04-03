# New ports collection makefile for:	ImageMagick
# Date created:		15 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ImageMagick
DISTVERSION=	6.3.3-5
CATEGORIES=	graphics perl5
MASTER_SITES=	ftp://ftp.imagemagick.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.carnet.hr/misc/imagemagick/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/ImageMagick/ \
		ftp://ftp.kddlabs.co.jp/graphics/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/imagemagick.org/ \
		ftp://zoffy.asahi-net.or.jp/pub/graphics/ImageMagick/ \
		ftp://ftp.nluug.nl/pub/ImageMagick/ \
		ftp://ftp.sunet.se/pub/multimedia/graphics/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_LOCAL:S/%SUBDIR%/pav/}
MASTER_SITE_SUBDIR=	imagemagick

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Image processing tools

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15 libltdl:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-shared --mandir=${MANPREFIX}/man --without-dps
USE_LDCONFIG=	yes

MAN1=		ImageMagick.1 Magick++-config.1 Magick-config.1 Wand-config.1 \
		animate.1 conjure.1 compare.1 composite.1 convert.1 display.1 \
		identify.1 import.1 mogrify.1 montage.1 stream.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

PLIST_SUB+=	PORTVERSION=${PORTVERSION:R}

OPTIONS=	X11				"X11 support" on \
		IMAGEMAGICK_PERL		"Perl support" on \
		IMAGEMAGICK_MODULES		"Modules support" off \
		IMAGEMAGICK_BZLIB		"Bzlib support" on \
		IMAGEMAGICK_16BIT_PIXEL		"16bit pixel support" on \
		IMAGEMAGICK_LCMS		"LCMS support" on \
		IMAGEMAGICK_TTF			"Freetype support" on \
		IMAGEMAGICK_FONTCONFIG		"Fontconfig support" on \
		IMAGEMAGICK_JPEG		"JPG format support" on \
		IMAGEMAGICK_PNG			"PNG format support" on \
		IMAGEMAGICK_TIFF		"TIFF format support" on \
		IMAGEMAGICK_FPX			"FPX format support" on \
		IMAGEMAGICK_JBIG		"JBIG format support" on \
		IMAGEMAGICK_JPEG2000		"JPEG2000 format support" on \
		IMAGEMAGICK_DOT		"GraphViz dot graphs support" off \
		IMAGEMAGICK_WMF			"WMF format support" off \
		IMAGEMAGICK_SVG			"SVG format support" off \
		IMAGEMAGICK_PDF			"PDF format support" on \
		IMAGEMAGICK_MPEG2		"MPEG2 format support" on \
		IMAGEMAGICK_GSLIB	"libgs (Postscript SHLIB) support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GHOSTSCRIPT_GNU)
IGNORE=		requires newer version of ghostscript
.endif

.if !defined(WITHOUT_IMAGEMAGICK_PERL)
CONFIGURE_ARGS+=	--with-perl=${PERL5}
PLIST_SUB+=		WITH_PERL=''
MAN3=			Image::Magick.3
MAN3PREFIX=		${TARGETDIR}/lib/perl5/${PERL_VERSION}
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

.if !defined(WITHOUT_IMAGEMAGICK_JPEG)
LIB_DEPENDS+=		jpeg.9:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=		JPEG=""
.else
CONFIGURE_ARGS+=	--without-jpeg
PLIST_SUB+=		JPEG="@comment "
.endif

.if !defined(WITHOUT_IMAGEMAGICK_PNG)
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
PLIST_SUB+=		PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=		PNG="@comment "
.endif

.if !defined(WITHOUT_IMAGEMAGICK_TIFF)
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
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

# Produce BZip compressed MIFF images
.if defined(WITHOUT_IMAGEMAGICK_BZLIB)
CONFIGURE_ARGS+=	--without-bzlib
.endif

# FPX (FlashPIX) images
.if !defined(WITHOUT_IMAGEMAGICK_FPX)
LIB_DEPENDS+=		fpx.1:${PORTSDIR}/graphics/libfpx
CONFIGURE_ARGS+=	--with-fpx
PLIST_SUB+=		FPX=""
.else
PLIST_SUB+=		FPX="@comment "
.endif

# JBIG images (lossless compression for bi-level images)
.if !defined(WITHOUT_IMAGEMAGICK_JBIG)
LIB_DEPENDS+=		jbig.1:${PORTSDIR}/graphics/jbigkit
PLIST_SUB+=		JBIG=""
.else
CONFIGURE_ARGS+=	--without-jbig
PLIST_SUB+=		JBIG="@comment "
.endif

# JPEG2000 images (wavelet-based lossy compression)
.if !defined(WITHOUT_IMAGEMAGICK_JPEG2000)
LIB_DEPENDS+=		jasper.4:${PORTSDIR}/graphics/jasper
PLIST_SUB+=		JPEG2000=""
.else
CONFIGURE_ARGS+=	--without-jp2
PLIST_SUB+=		JPEG2000="@comment "
.endif

# GraphViz dot graphs
.if defined(WITH_IMAGEMAGICK_DOT)
LIB_DEPENDS+=		gvc.3:${PORTSDIR}/graphics/graphviz
CFLAGS+=		-I${LOCALBASE}/include/graphviz
LDFLAGS+=		-L${LOCALBASE}/lib/graphviz
.else
CONFIGURE_ARGS+=	--without-dot --without-gvc
.endif

# LCMS (Little CMS) color management
.if !defined(WITHOUT_IMAGEMAGICK_LCMS)
LIB_DEPENDS+=		lcms.1:${PORTSDIR}/graphics/lcms
.else
CONFIGURE_ARGS+=	--without-lcms
.endif

# Freetype (TrueType Font) support
.if !defined(WITHOUT_IMAGEMAGICK_TTF)
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-freetype
.else
CONFIGURE_ARGS+=	--without-freetype
.endif

# Fontconfig support
.if !defined(WITHOUT_IMAGEMAGICK_FONTCONFIG)
LIB_DEPENDS+=		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
CONFIGURE_ARGS+=	--with-fontconfig
CONFIGURE_ENV+=		FONTCONFIG_CFLAGS="-I${X11BASE}/include" \
			FONTCONFIG_LIBS="-L${X11BASE}/lib"
MAKE_ENV+=		FONTCONFIG_CFLAGS="-I${X11BASE}/include"
.else
CONFIGURE_ARGS+=	--without-fontconfig
.endif

# WMF (Windows Meta File) images
.if defined(WITH_IMAGEMAGICK_WMF)
.if !defined(WITH_IMAGEMAGICK_MODULES)
IGNORE=			WMF support requires WITH_IMAGEMAGICK_MODULES
.else
.if defined(WITHOUT_X11)
IGNORE=			WMF support requires X11 libraries, please unset WITHOUT_X11
.else
LIB_DEPENDS+=		wmf.2:${PORTSDIR}/graphics/libwmf
CONFIGURE_ARGS+=	--with-wmf=yes
.endif
.endif
.else
CONFIGURE_ARGS+=	--without-wmf
.endif

# SVG (Scalable Vector Graphics) images and MSL (Magick Scripting Language)
# both require XML
.if defined(WITH_IMAGEMAGICK_SVG) || !defined(WITHOUT_IMAGEMAGICK_MSL)
USE_GNOME+=		libxml2
CONFIGURE_ARGS+=	--with-xml
.else
CONFIGURE_ARGS+=	--without-xml
.endif
.if defined(WITH_IMAGEMAGICK_SVG)
.if defined(WITHOUT_X11)
IGNORE=			SVG support requires X11 libraries, please unset WITHOUT_X11
.endif
LIB_DEPENDS+=		rsvg-2.2:${PORTSDIR}/graphics/librsvg2
CONFIGURE_ARGS+=	--with-rsvg
CONFIGURE_ENV+=		RSVG_CFLAGS="-I${X11BASE}/include/librsvg-2" \
			RSVG_LIBS="-L${X11BASE}/lib"
.else
CONFIGURE_ARGS+=	--without-rsvg
.endif

# PDF (Adobe Portable Document Format) support
.if !defined(WITHOUT_IMAGEMAGICK_PDF)
USE_GHOSTSCRIPT=	yes
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX+=		-nox11
CONFIGURE_ARGS+=	--without-x --without-mpeg2
PLIST_SUB+=		X11='@comment '
.else
CONFLICTS+=		display-[0-9]*
CONFIGURE_ARGS+=	--with-x
USE_XLIB=		yes
PLIST_SUB+=		X11=''
.if !defined(WITHOUT_IMAGEMAGICK_MPEG2)
RUN_DEPENDS+=		mpeg2encode:${PORTSDIR}/multimedia/mpeg2codec
.endif
.endif

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install
.else
INSTALL_TARGET=	install install-data-html
.endif

post-patch:
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
# Respect Make flags
	@${REINPLACE_CMD} -E -e "s|^CPPFLAGS =|CPPFLAGS ?=|g" \
		-e "s|^CXXFLAGS =|CXXFLAGS ?=|g" -e "s|^CFLAGS =|CFLAGS ?=|g" \
		-e "s|^CC =|CC ?=|g" -e "s|^CPP =|CPP ?=|g" -e "s|^CXX =|CXX ?=|g" \
		-e "s|^LDFLAGS =|LDFLAGS ?=|g" ${WRKSRC}/Makefile.in

post-install:
.if defined(WITHOUT_IMAGEMAGICK_16BIT_PIXEL)
	@${TOUCH} ${PREFIX}/lib/ImageMagick/modules-Q8/coders/.keep
	@${TOUCH} ${PREFIX}/lib/ImageMagick/modules-Q8/filters/.keep
.else
	@${TOUCH} ${PREFIX}/lib/ImageMagick/modules-Q16/coders/.keep
	@${TOUCH} ${PREFIX}/lib/ImageMagick/modules-Q16/filters/.keep
.endif

.include <bsd.port.post.mk>
