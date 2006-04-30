# New ports collection makefile for:	fbm
# Date created:		21 January 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	fbm
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/convert
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fuzzy Pixmap Manipulation utilities

LIB_DEPENDS=	rle.1:${PORTSDIR}/graphics/urt

NO_WRKSUBDIR=	yes
NO_LATEST_LINK=	yes

MANL=	clr2gray.l fbcat.l fbclean.l fbconv.l fbedge.l fbext.l fbhalf.l \
	fbham.l fbhist.l fbinfo.l fbm.l fbm2pod.l fbmask.l fbmedian.l \
	fbnorm.l fbps.l fbquant.l fbrot.l fbsample.l fbsharp.l fbthin.l \
	gray2clr.l idiff.l pbm2ps.l pbmtitle.l qrt2fbm.l raw2fbm.l tiff2fbm.l \
	uunet2fbm.l

.include <bsd.port.mk>
