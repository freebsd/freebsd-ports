# New ports collection makefile for:	ImageMagick
# Version required:	3.9.2
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.22 1997/11/29 01:35:38 jseger Exp $
#

DISTNAME=	ImageMagick-3.9.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.cci.fr/pub/unix/gfx/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/ \
		ftp://ftp.fifi.org/pub/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.ms.mff.cuni.cz/MIRRORS/ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.oce.nl/pub/Internet/audio+video/ImageMagick/ \
		http://hpux.csc.liv.ac.uk/hppd/hpux/X11/Viewers/ImageMagick-3.9.2/

MAINTAINER=	jseger@freebsd.org

LIB_DEPENDS=    jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		mpeg\\.1\\.:${PORTSDIR}/graphics/mpeg-lib \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34 \
		png\\.0\\.:${PORTSDIR}/graphics/png \
		jbig\\.0\\.:${PORTSDIR}/graphics/jbigkit

WRKSRC=		${WRKDIR}/ImageMagick
USE_IMAKE=	YES

post-patch:
	@perl -pi -e "s|!!LOCALBASE!!|${LOCALBASE}|g;" ${WRKSRC}/Magick.tmpl

pre-build:
	@(cd ${WRKSRC}/magick; make)

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
