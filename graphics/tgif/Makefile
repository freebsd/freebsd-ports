# New ports collection makefile for:    tgif
# Version required:     4.1.15
# Date created:         30 Jan 1999
# Whom:                 bmc@WillsCreek.COM
#
# $Id: Makefile,v 1.15 1999/05/22 07:48:20 mharo Exp $
#

DISTNAME=	tgif-4.1.15
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=	bmc@WillsCreek.COM

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
MAN1=		tgif.1

post-extract:
		${RM} -f ${WRKDIR}/${DISTNAME}/Tgif.tmpl
		${CP} ${WRKDIR}/${DISTNAME}/Tgif.tmpl-freebsd \
		      ${WRKDIR}/${DISTNAME}/Tgif.tmpl

.include <bsd.port.mk>
