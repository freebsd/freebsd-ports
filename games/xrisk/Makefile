# New ports collection makefile for:    xrisk
# Date created:		4 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xrisk
PORTVERSION=	2.15
CATEGORIES=	games
MASTER_SITES=	http://my.pages.de/pub/comp/games/xrisk/ \
		http://www.mikro.biologie.tu-muenchen.de/pub/rec/games/xrisk/

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	A game for X11, much like the popular board game

USE_IMAKE=	yes
MAN6=		xrisk.6

RESTRICTED=	"Possible trademark infringement"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
