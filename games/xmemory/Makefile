# New ports collection makefile for:	xmemory
# Date Created:		Sat Feb  7 21:37:09 EST 1998
# Whom:			Dave Chapeskie <dchapes@ddm.on.ca>
#
# $FreeBSD$
#

PORTNAME=	xmemory
PORTVERSION=	3.7
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/multiplayer
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player memory game

USE_IMAKE=	yes
USE_XORG=	x11 xext
MAN1=		xmemory.1

post-install:
	@${MKDIR} ${LOCALBASE}/lib/X11/xmemory
	${INSTALL_DATA} ${WRKSRC}/home.mem ${WRKSRC}/sports.mem \
			${LOCALBASE}/lib/X11/xmemory
	${LN} -sf home.mem ${LOCALBASE}/lib/X11/xmemory/default.mem

.include <bsd.port.mk>
