# New ports collection makefile for:    tgif
# Version required:     4.1.11
# Date created:         30 Jan 1999
# Whom:                 bmc@WillsCreek.COM
#
# $Id: Makefile,v 1.14 1999/04/16 16:07:02 mharo Exp $
#

DISTNAME=	tgif-4.1.11
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
