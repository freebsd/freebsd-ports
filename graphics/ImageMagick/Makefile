# New ports collection makefile for:	ImageMagick
# Date created:		15 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ImageMagick
PORTVERSION=	5.2.1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/
MASTER_SITE_SUBDIR=	jseger

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	bz2.1:${PORTSDIR}/archivers/bzip2 \
		df.1:${PORTSDIR}/graphics/hdf \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ttf.4:${PORTSDIR}/print/freetype \
		xml.5:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55 \
		mpeg2decode:${PORTSDIR}/graphics/mpeg2codec \
		picttoppm:${PORTSDIR}/graphics/netpbm \
		fig2dev:${PORTSDIR}/print/transfig

USE_PERL5=	yes
USE_XLIB=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-shared --enable-16bit-pixel --without-modules \
		--with-perl=${PERL5}
INSTALLS_SHLIB=	yes

.if defined(HAVE_UNISYS_LICENSE)
CONFIGURE_ARGS+= --enable-lzw
.endif

MAN1=		ImageMagick.1 animate.1 combine.1 convert.1 display.1 \
		identify.1 import.1 mogrify.1 montage.1
MAN3=		Image::Magick.3
MAN4=		miff.4
MAN5=		quantize.5

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
