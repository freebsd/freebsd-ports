# New ports collection makefile for:	ImageMagick
# Version required:     4.1.6
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.63 1998/12/14 20:03:28 jseger Exp $
#

DISTNAME=       ImageMagick-4.1.6
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.freebsd.org/~jseger/ \
		ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.cci.fr/pub/unix/gfx/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		png.2:${PORTSDIR}/graphics/png \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		ttf.3:${PORTSDIR}/print/freetype
BUILD_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig \
		picttoppm:${PORTSDIR}/graphics/netpbm \
		mpeg2decode:${PORTSDIR}/graphics/mpeg2codec \
		gs:${PORTSDIR}/print/ghostscript5

MAN1=	ImageMagick.1 animate.1 combine.1 convert.1 display.1 identify.1 import.1 mogrify.1 montage.1 xtp.1
MAN3=	Image::Magick.3
MAN4=	miff.4
MAN5=	quantize.5

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-lzw --enable-shared --with-perl=${PERL5}
USE_PERL5=	YES
CONFIGURE_ENV=  LDFLAGS="$(LDFLAGS) -L${WRKSRC}/magick/.libs"
post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
