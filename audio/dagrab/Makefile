# New ports collection makefile for:	dagrab
# Date created:		2nd, Jan 1999
# Whom:			Chia-liang Kao <clkao@CirX.ORG>
#
# $FreeBSD$
#

PORTNAME=	dagrab
PORTVERSION=	0.3.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/cdrom

MAINTAINER=	clkao@CirX.ORG

MAN1=		dagrab.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dagrab ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dagrab.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
