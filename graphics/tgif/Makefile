# New ports collection makefile for:    tgif
# Version required:     3.0-p9
# Date created:         10 Oct 1996
# Whom:                 bmc@WillsCreek.COM
#
# $Id: Makefile,v 1.2 1996/10/19 02:20:05 chuckr Exp $
#

DISTNAME=	tgif-3.0-p9
PKGNAME=	tgif-3.0.9
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/tgif

MAINTAINER=	bmc@WillsCreek.COM

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtotiff:${PORTSDIR}/graphics/netpbm \
		ppmtoxpm:${PORTSDIR}/graphics/netpbm \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		xbmtopbm:${PORTSDIR}/graphics/netpbm \
		xpmtoppm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=      yes

.include <bsd.port.mk>
