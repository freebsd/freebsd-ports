# New ports collection makefile for:	acm
# Version required:	1.0
# Date created:		23 February 1998
# Whom:			Peter Mutsaers
#
# $Id: Makefile,v 1.3 1998/07/27 23:24:37 asami Exp $
#

DISTNAME=	blackjack-1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	plm@xs4all.nl

BUILD_DEPENDS=	moc:${PORTSDIR}/x11-toolkits/qt
LIB_DEPENDS=	qt\\.1\\.3[0-9]:${PORTSDIR}/x11-toolkits/qt

WRKSRC=		${WRKDIR}/blackjack

MAN1=		blackjack.1

.include <bsd.port.mk>
