# New ports collection makefile for:	ImageMagick
# Version required:	3.4
# Date created:		15 November 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.6 1995/02/11 15:37:49 torstenb Exp $
#

DISTNAME=	ImageMagick-3.5
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/ImageMagick/
WRKSRC=		${WRKDIR}/ImageMagick
USE_IMAKE=	YES

LIB_DEPENDS+=	jpeg\\.5\\.:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	mpeg\\.1\\.:${PORTSDIR}/graphics/mpeg-lib
LIB_DEPENDS+=	tiff\\.3\\.:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

.include <bsd.port.mk>
