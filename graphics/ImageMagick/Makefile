# New ports collection makefile for:	ImageMagick
# Date created:		15 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ImageMagick
PORTVERSION=	5.5.7.15
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://gd.tuwien.ac.at/pub/graphics/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/ImageMagick,} \
		ftp://ftp.crc.ca/pub/packages/graphics/imagemagick/ \
		ftp://ftp.imagemagick.org/pub/%SUBDIR%/ \
		ftp://ftp.planetmirror.com/pub/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/X11/graphics/%SUBDIR%/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/%SUBDIR%/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/graphics/%SUBDIR%/ \
		ftp://ftp.kddlabs.co.jp/graphics/%SUBDIR%/ \
		ftp://ftp.icm.edu.pl/pub/graphics/%SUBDIR%/ \
		ftp://giswitch.sggw.waw.pl/pub/graphics/%SUBDIR%/ \
		ftp://ftp.fifi.org/pub/%SUBDIR%/ \
		ftp://ftp.simplesystems.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME:L} ${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image processing tools

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_PERL5=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	# none
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-shared
INSTALLS_SHLIB=	yes

MAN1=		ImageMagick.1 Magick++-config.1 Magick-config.1 \
		composite.1 convert.1 identify.1 mogrify.1 montage.1
MAN4=		miff.4
MAN5=		quantize.5

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

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
CPPFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--without-threads
.endif

# Faster, but poor quality
.if defined(WITHOUT_IMAGEMAGICK_16BIT_PIXEL)
CONFIGURE_ARGS+=	--with-quantum-depth=8
PLIST_SUB+=		Q8=''
PLIST_SUB+=		Q16='@comment '
.else
PLIST_SUB+=		Q8='@comment '
PLIST_SUB+=		Q16=''
.endif

# Produce standard (small) GIFs
.if defined(HAVE_UNISYS_LICENSE) || \
    (defined(USA_RESIDENT) && ${USA_RESIDENT} == "YES")
CONFIGURE_ARGS+=	--enable-lzw
.endif

# Loadable coders, smaller executable, but PerlMagick not really works
# ('make test' there works)
.if defined(WITH_IMAGEMAGICK_MODULES)
CONFIGURE_ARGS+=	--with-modules
PLIST_SUB+=		MODULES=''
.else
PLIST_SUB+=		MODULES='@comment '
.endif

.if !defined(WITHOUT_IMAGEMAGICK_JPEG)
LIB_DEPENDS+=		jpeg.9:${PORTSDIR}/graphics/jpeg
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif

.if !defined(WITHOUT_IMAGEMAGICK_PNG)
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--without-png
.endif

.if !defined(WITHOUT_IMAGEMAGICK_TIFF)
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

# Produce BZip compressed MIFF images
.if defined(WITHOUT_IMAGEMAGICK_BZLIB)
CONFIGURE_ARGS+=	--without-bzlib
.endif

# HDF (Hierarchical Data Format) images
.if !defined(WITHOUT_IMAGEMAGICK_HDF)
LIB_DEPENDS+=		df.1:${PORTSDIR}/graphics/hdf
CONFIGURE_ARGS+=	--with-hdf
.endif

# FPX (FlashPIX) images
.if !defined(WITHOUT_IMAGEMAGICK_FPX)
LIB_DEPENDS+=		fpx.1:${PORTSDIR}/graphics/libfpx
.else
CONFIGURE_ARGS+=	--without-fpx
.endif

# JBIG images (lossless compression for bi-level images)
.if !defined(WITHOUT_IMAGEMAGICK_JBIG)
LIB_DEPENDS+=		jbig.1:${PORTSDIR}/graphics/jbigkit
.else
CONFIGURE_ARGS+=	--without-jbig
.endif

# JPEG2000 images (wavelet-based lossy compression)
.if !defined(WITHOUT_IMAGEMAGICK_JPEG2000)
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
.else
CONFIGURE_ARGS+=	--without-jp2
.endif

# LCMS (Little CMS) color management
.if !defined(WITHOUT_IMAGEMAGICK_LCMS)
LIB_DEPENDS+=		lcms.1:${PORTSDIR}/graphics/lcms
.else
CONFIGURE_ARGS+=	--without-lcms
.endif

# TTF (TrueType Font) support
.if !defined(WITHOUT_IMAGEMAGICK_TTF)
BUILD_DEPENDS+=		freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS+=		freetype.9:${PORTSDIR}/print/freetype2
USE_GHOSTSCRIPT=	yes
.else
CONFIGURE_ARGS+=	--without-ttf
.endif

# WMF (Windows Meta File) images
.if !defined(WITHOUT_IMAGEMAGICK_WMF)
LIB_DEPENDS+=		wmf.2:${PORTSDIR}/graphics/libwmf
.else
CONFIGURE_ARGS+=	--without-wmf
.endif

# SVG (Scalable Vector Graphics) images and MSL (Magick Scripting Language)
# both require XML
.if !defined(WITHOUT_IMAGEMAGICK_SVG) || !defined(WITHOUT_IMAGEMAGICK_MSL)
LIB_DEPENDS+=		xml2.5:${PORTSDIR}/textproc/libxml2
MAN1+=			conjure.1
PLIST_SUB+=		WITH_CONJURE=''
.else
CONFIGURE_ARGS+=	--without-xml
PLIST_SUB+=		WITH_CONJURE='@comment '
.endif

# DPS (Display PostScript) support
.if !defined(WITHOUT_IMAGEMAGICK_DPS)
CONFIGURE_ARGS+=	--with-dps
.else
CONFIGURE_ARGS+=	--without-dps
.endif

# PDF (Adobe Portable Document Format) support
.if !defined(WITHOUT_IMAGEMAGICK_PDF)
CONFIGURE_ARGS+=	--with-gslib
USE_GHOSTSCRIPT=	yes
.else
CONFIGURE_ARGS+=	--without-gslib
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX+=		-nox11
CONFIGURE_ARGS+=	--without-x --without-mpeg2
PLIST_SUB+=		X11='@comment '
.else
CONFLICTS+=		display
CONFIGURE_ARGS+=	--with-x
USE_XLIB=		yes
MAN1+=			animate.1 display.1 import.1
PLIST_SUB+=		X11=''
.if !defined(WITHOUT_IMAGEMAGICK_MPEG2)
CONFIGURE_ARGS+=	--with-mpeg2
LIB_DEPENDS+=		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
.else
CONFIGURE_ARGS+=	--without-mpeg2
.endif
.endif

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install
.else
INSTALL_TARGET=	install install-data-html
.endif

post-patch:
# do not use "-pthread" here
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS:S/-pthread/-lc_r/}|g ; \
		 s|-pthread|${PTHREAD_LIBS:S/-pthread/-lc_r/}|g ; \
		 s|^tagnames=|#tagnames=|g ; \
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

.include <bsd.port.mk>
