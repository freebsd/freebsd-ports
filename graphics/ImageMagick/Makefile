# New ports collection makefile for:	ImageMagick
# Version required:	3.6.2
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.4 1995/04/09 07:09:14 asami Exp $
#

DISTNAME=	ImageMagick-3.6.2
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/ImageMagick/

LIB_DEPENDS=	jpeg\\.5\\.:${PORTSDIR}/graphics/jpeg \
		mpeg\\.1\\.:${PORTSDIR}/graphics/mpeg-lib \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff \
		Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/ImageMagick
USE_IMAKE=	YES

pre-build:
	@(cd ${WRKSRC}/magick;make)

.include <bsd.port.mk>
