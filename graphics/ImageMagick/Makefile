# New ports collection makefile for:	ImageMagick
# Date created:		15 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ImageMagick
PORTVERSION=	5.2.9
CATEGORIES=	graphics perl5
MASTER_SITES=	ftp://ftp.yggdrasil.com/mirrors/site/ftp.simplesystems.org/pub/ImageMagick/ \
		ftp://ftp.cdrom.com/pub/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.simplesystems.org/pub/ImageMagick/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/ImageMagick

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	bz2.1:${PORTSDIR}/archivers/bzip2 \
		ltdl.1:${PORTSDIR}/devel/libtool \
		df.1:${PORTSDIR}/graphics/hdf \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.6:${PORTSDIR}/print/freetype2 \
		xml2.5:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	picttoppm:${PORTSDIR}/graphics/netpbm

.ifndef NO_X
BUILD_DEPENDS+=	mpeg2decode:${PORTSDIR}/graphics/mpeg2codec \
		gs:${PORTSDIR}/print/ghostscript6 \
		fig2dev:${PORTSDIR}/print/transfig
LIB_DEPENDS+=	wmf.1:${PORTSDIR}/graphics/libwmf
USE_XLIB=	yes
.else
BUILD_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript6-nox11
PKGNAMESUFFIX=	-nox11
.endif

USE_PERL5=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	# empty
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-shared \
		--with-perl=${PERL5}

.ifdef WITH_MODULES
CONFIGURE_ARGS+=--with-modules
PLIST_SUB+=	MODULES=''
.else
PLIST_SUB+=	MODULES='@comment '
.endif

.ifdef NO_X
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11='@comment '
.else
PLIST_SUB+=	X11=''
.endif

INSTALLS_SHLIB=	yes

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

MAN1=		ImageMagick.1 Magick++-config.1 Magick-config.1 \
		combine.1 convert.1 identify.1 mogrify.1 montage.1
MAN3=		Image::Magick.3
MAN4=		miff.4
MAN5=		quantize.5

.ifndef NO_X
MAN1+=		animate.1 display.1 import.1
.endif

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$$\(top_builddir\)/ltdl/libltdlc.la|\$$\(LIBLTDL\)|g'

.include <bsd.port.mk>
