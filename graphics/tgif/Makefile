# New ports collection makefile for:    tgif
# Version required:     3.0-p17
# Date created:         10 Aug 1997
# Whom:                 bmc@WillsCreek.COM
#
# $Id: Makefile,v 1.7 1998/12/11 11:38:24 obrien Exp $
#

DISTNAME=	tgif-4.0.2
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=	bmc@WillsCreek.COM

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtotiff:${PORTSDIR}/graphics/netpbm \
		ppmtoxpm:${PORTSDIR}/graphics/netpbm \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		xbmtopbm:${PORTSDIR}/graphics/netpbm \
		xpmtoppm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
MAN1=		tgif.1

post-extract:
		${RM} -f ${WRKDIR}/${DISTNAME}/Tgif.tmpl
		${CP} ${WRKDIR}/${DISTNAME}/Tgif.tmpl-freebsd \
		      ${WRKDIR}/${DISTNAME}/Tgif.tmpl

.include <bsd.port.mk>
