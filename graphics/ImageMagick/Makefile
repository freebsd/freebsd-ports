# New ports collection makefile for:	ImageMagick
# Version required:	3.7.7
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.7 1995/10/03 21:58:08 ache Exp $
#

DISTNAME=	ImageMagick-3.7.7
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/ImageMagick/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=    jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg \
		mpeg\\.1\\.:${PORTSDIR}/graphics/mpeg-lib \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff \
		png\\.0\\.:${PORTSDIR}/graphics/png

PREFIX=		${LOCALBASE}
WRKSRC=		${WRKDIR}/ImageMagick
USE_IMAKE=	YES

# Yuck. Somehow, $LOCALBASE isn't expanded in the Makefiles...
post-patch:
	@mv ${WRKSRC}/Magick.tmpl ${WRKSRC}/Magick.tmpl.tmp
	@sed -e "s|!!LOCALBASE!!|${LOCALBASE}|g" <${WRKSRC}/Magick.tmpl.tmp >${WRKSRC}/Magick.tmpl

pre-build:
	@(cd ${WRKSRC}/magick;make)

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
