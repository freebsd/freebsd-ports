# New ports collection makefile for:	ImageMagick
# Version required:	3.9.0
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.18 1997/07/17 15:12:42 max Exp $
#

DISTNAME=	ImageMagick-3.9.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.wizards.dupont.com/pub/ImageMagick/ \
		ftp://ftp.cci.fr/pub/unix/gfx/ImageMagick/ \
		ftp://gd.tuwien.ac.at/pub/graphics/ImageMagick/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/image/ImageMagick/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=    jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		mpeg\\.1\\.:${PORTSDIR}/graphics/mpeg-lib \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff \
		png\\.0\\.:${PORTSDIR}/graphics/png \
		jbig\\.0\\.:${PORTSDIR}/graphics/jbigkit

WRKSRC=		${WRKDIR}/ImageMagick
USE_IMAKE=	YES

post-patch:
	@mv ${WRKSRC}/Magick.tmpl ${WRKSRC}/Magick.tmpl.tmp
	@sed -e "s|!!LOCALBASE!!|${LOCALBASE}|g" <${WRKSRC}/Magick.tmpl.tmp >${WRKSRC}/Magick.tmpl

pre-build:
	@(cd ${WRKSRC}/magick; make)

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
