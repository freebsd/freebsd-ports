# New ports collection makefile for:	ImageMagick
# Version required:     4.2.9
# Date created:		15 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=       ImageMagick-4.2.9
CATEGORIES=	graphics perl5
MASTER_SITES=	ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.3:${PORTSDIR}/graphics/png \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		ttf.4:${PORTSDIR}/print/freetype
BUILD_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig \
		picttoppm:${PORTSDIR}/graphics/netpbm \
		mpeg2decode:${PORTSDIR}/graphics/mpeg2codec \
		gs:${PORTSDIR}/print/ghostscript5

MAN1=	ImageMagick.1 animate.1 combine.1 convert.1 display.1 identify.1 import.1 mogrify.1 montage.1 xtp.1
MAN3=	Image::Magick.3
MAN4=	miff.4
MAN5=	quantize.5

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX} --enable-lzw --enable-shared --with-perl=${PERL5}
USE_PERL5=	YES
CONFIGURE_ENV=  LDFLAGS="$(LDFLAGS) -L${WRKSRC}/magick/.libs"
post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
