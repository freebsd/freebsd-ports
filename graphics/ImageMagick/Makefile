# New ports collection makefile for:	ImageMagick
# Version required:	4.0
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.27 1998/01/30 22:51:07 jseger Exp $
#

DISTNAME=	ImageMagick-4.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.freebsd.org/~jseger/ \
		ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.cci.fr/pub/unix/gfx/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/ \
		http://hpux.csc.liv.ac.uk/hppd/hpux/X11/Viewers/ImageMagick-4.0/

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=    jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		mpeg\\.1\\.:${PORTSDIR}/graphics/mpeg-lib \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34 \
		png\\.0\\.:${PORTSDIR}/graphics/png \
		jbig\\.0\\.:${PORTSDIR}/graphics/jbigkit \
		ttf\\.1\\.:${PORTSDIR}/print/freetype
BUILD_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig \
		picttoppm:${PORTSDIR}/graphics/netpbm \
		gs:${PORTSDIR}/print/ghostscript5

MAN1=	ImageMagick.1 animate.1 combine.1 convert.1 display.1 identify.1 import.1 mogrify.1 xtp.1
MAN4=	miff.4
MAN5=	quantize.5
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-lzw

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
