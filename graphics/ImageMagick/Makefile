# New ports collection makefile for:	ImageMagick
# Version required:	3.8.6
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.17 1997/06/03 15:58:15 davidn Exp $
#

DISTNAME=	ImageMagick-3.8.6
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
