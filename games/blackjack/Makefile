# New ports collection makefile for:	acm
# Version required:	1.0
# Date created:		23 February 1998
# Whom:			Peter Mutsaers
#
# $Id: Makefile,v 1.2 1998/04/22 22:55:26 mph Exp $
#

DISTNAME=	blackjack-1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	plm@xs4all.nl

BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11/qt

WRKSRC=		${WRKDIR}/blackjack

MAN1=		blackjack.1

.include <bsd.port.mk>
