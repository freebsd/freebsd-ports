# New ports collection makefile for:    tgif
# Version required:     2.16-p12
# Date created:         19 Jan 1996
# Whom:                 bmc@WillsCreek.COM
#
# $Id$
#

DISTNAME=       tgif-2.16-p12
PKGNAME=	tgif-2.16.12
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/tgif/ \
	ftp://ftp.crl.research.digital.com/pub/X11/contrib/applications/tgif/ \
	ftp://ftp.cs.columbia.edu/archives/X11R6/contrib/applications/tgif/

MAINTAINER=	bmc@WillsCreek.COM

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtotiff:${PORTSDIR}/graphics/netpbm \
		ppmtoxpm:${PORTSDIR}/graphics/netpbm \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		xbmtopbm:${PORTSDIR}/graphics/netpbm \
		xpmtoppm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=      yes

post-install:

.include <bsd.port.mk>
