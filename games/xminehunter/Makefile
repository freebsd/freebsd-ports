# New ports collection makefile for:	xminehunter
# Version required:	0.4
# Date created:		09 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1998/08/05 09:30:59 asami Exp $
#

DISTNAME=	xminehunter-0.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	Xpm.5:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/xminehunter
REQUIRES_MOTIF=	yes
ALL_TARGET=	xminehunter

.include <bsd.port.mk>
