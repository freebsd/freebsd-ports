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

NO_WRKSUBDIR=	yes

INSTALL_TARGET= smaller $(INSTALL)

MANL=	clr2gray.l fbcat.l fbclean.l fbedge.l fbext.l fbhalf.l fbhist.l \
	fbinfo.l fbm.l fbm2pod.l fbmask.l fbnorm.l fbps.l fbquant.l fbrot.l \
	fbsample.l fbsharp.l gray2clr.l idiff.l pbm2ps.l pbmtitle.l raw2fbm.l \
	qrt2fbm.l fbham.l uunet2fbm.l tiff2fbm.l fbmedian.l fbconv.l fbthin.l

.include <bsd.port.mk>
