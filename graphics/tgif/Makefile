# New ports collection makefile for:    tgif
# Version required:     3.0-p13
# Date created:         10 Oct 1996
# Whom:                 bmc@WillsCreek.COM
#
# $Id: Makefile,v 1.3 1996/11/18 09:53:40 asami Exp $
#

DISTNAME=       tgif-3.0-p13
PKGNAME=	tgif-3.0p13
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.cs.columbia.edu/pub/tgif/ \
	ftp://ftp.crl.research.digital.com/pub/X11/contrib/applications/tgif/

MAINTAINER=	bmc@WillsCreek.COM

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtotiff:${PORTSDIR}/graphics/netpbm \
		ppmtoxpm:${PORTSDIR}/graphics/netpbm \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		xbmtopbm:${PORTSDIR}/graphics/netpbm \
		xpmtoppm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=      yes

.include <bsd.port.mk>
