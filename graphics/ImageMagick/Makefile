# New ports collection makefile for:	ImageMagick
# Version required:	4.0.6
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.38 1998/05/04 20:22:29 jseger Exp $
#

DISTNAME=	ImageMagick-4.0.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.freebsd.org/~jseger/ \
		ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.cci.fr/pub/unix/gfx/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=    jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		mpeg\\.1\\.[2-9]:${PORTSDIR}/graphics/mpeg-lib \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34 \
		png\\.2\\.:${PORTSDIR}/graphics/png \
		jbig\\.0\\.9:${PORTSDIR}/graphics/jbigkit \
		ttf\\.1\\.:${PORTSDIR}/print/freetype
BUILD_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig \
		picttoppm:${PORTSDIR}/graphics/netpbm \
		gs:${PORTSDIR}/print/ghostscript5

MAN1=	ImageMagick.1 animate.1 combine.1 convert.1 display.1 identify.1 import.1 mogrify.1 montage.1 xtp.1
MAN4=	miff.4
MAN5=	quantize.5
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-lzw --enable-shared

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
