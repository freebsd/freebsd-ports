# New ports collection makefile for:	ImageMagick
# Date created:		15 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ImageMagick
PORTVERSION=	5.1.1
CATEGORIES=	graphics perl5
MASTER_SITES=	http://people.FreeBSD.org/~asami/distfiles/ \
		ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		df.1:${PORTSDIR}/graphics/hdf \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.3:${PORTSDIR}/graphics/png \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		ttf.4:${PORTSDIR}/print/freetype

# bzip2 for bzlib
BUILD_DEPENDS=  bzip2:${PORTSDIR}/archivers/bzip2 \
		fig2dev:${PORTSDIR}/print/transfig \
		picttoppm:${PORTSDIR}/graphics/netpbm \
		mpeg2decode:${PORTSDIR}/graphics/mpeg2codec \
		gs:${PORTSDIR}/print/ghostscript55

MAN1=		ImageMagick.1 animate.1 combine.1 convert.1 display.1 \
		identify.1 import.1 mogrify.1 montage.1
MAN3=		Image::Magick.3
MAN4=		miff.4
MAN5=		quantize.5

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
USE_AUTOCONF=	yes
INSTALLS_SHLIBS=	yes

CONFIGURE_ARGS= --prefix=${PREFIX} --enable-shared --with-perl=${PERL5} \
		--enable-16bit-pixel

.if defined(HAVE_UNISYS_LICENSE)
CONFIGURE_ARGS+= --enable-lzw
.endif

USE_PERL5=	YES
USE_XLIB=	YES
CONFIGURE_ENV=	LDFLAGS="$(LDFLAGS) -L${WRKSRC}/magick/.libs"

pre-configure:
	${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
