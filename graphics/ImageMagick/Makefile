# New ports collection makefile for:	ImageMagick
# Date created:		15 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ImageMagick
PORTVERSION=	5.3.1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%,imagemagick,} \
		ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/pub/graphics/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/multimedia/graphics/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/ImageMagick,} \
		ftp://ftp.simplesystems.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	bz2.1:${PORTSDIR}/archivers/bzip2 \
		fpx.1:${PORTSDIR}/graphics/libfpx \
		df.1:${PORTSDIR}/graphics/hdf \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.6:${PORTSDIR}/print/freetype2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_PERL5=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-shared --with-perl=${PERL5}
INSTALLS_SHLIB=	yes

MAN1=		ImageMagick.1 Magick++-config.1 Magick-config.1 \
		combine.1 convert.1 identify.1 mogrify.1 montage.1
MAN3=		Image::Magick.3
MAN4=		miff.4
MAN5=		quantize.5
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.if defined(PERL_THREADED) && ${PERL_THREADED} == "true"
CONFIGURE_ARGS+=	--with-threads
.else
CONFIGURE_ARGS+=	--without-threads
.endif

.if defined(WITH_16BIT_PIXEL)
CONFIGURE_ARGS+=	--enable-16bit-pixel
.else
CONFIGURE_ARGS+=	--disable-16bit-pixel
.endif

.if defined(HAVE_UNISYS_LICENSE)
CONFIGURE_ARGS+=	--enable-lzw
.endif

.if defined(WITH_MODULES)
LIB_DEPENDS+=	ltdl.1:${PORTSDIR}/devel/libtool
LIBTOOLFLAGS=	# none
CONFIGURE_ARGS+=	--with-modules
PLIST_SUB+=	MODULES=''
.else
PLIST_SUB+=	MODULES='@comment '
.endif

.if defined(NO_X)
PKGNAMESUFFIX=	-nox11
BUILD_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript6-nox11
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript6-nox11
CONFIGURE_ARGS+=	--without-x --without-wmf
PLIST_SUB+=	X11='@comment '
.else
LIB_DEPENDS+=	wmf.1:${PORTSDIR}/graphics/libwmf
BUILD_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript6
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript6
USE_XLIB=	yes
MAN1+=		animate.1 display.1 import.1
PLIST_SUB+=	X11=''
.endif

pre-patch:
	@${PERL} -pi -e 's|\(pthread,|\(c_r,|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|-D_REENTRANT|${PTHREAD_CFLAGS}|g' ${WRKSRC}/configure.in
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(top_builddir\)/ltdl/libltdlc.la|\$$\(LIBLTDL\)|g'
	@${PERL} -pi -e 's|lcms/lcms.h|lcms.h|g' ${WRKSRC}/magick/transform.c

.include <bsd.port.mk>
