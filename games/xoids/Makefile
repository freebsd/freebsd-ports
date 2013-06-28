# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xoids
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Window Asteroids style game with full color pixmaps

USES=		imake
USE_XORG=	xpm
MAN6=		xoids.6

post-extract:
	@${CP} ${WRKSRC}/xoids.1x ${WRKSRC}/xoids.man

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
