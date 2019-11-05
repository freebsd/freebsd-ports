# Created by: Steven H. Samorodin (samorodi@NUXI.com)
# $FreeBSD$

PORTNAME=	ishido
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	LOCAL/obrien

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tile placement game

USES=		xorg
USE_XORG=	x11
MAKE_ENV=	X11BASE=${LOCALBASE}

do-install:
	${INSTALL_MAN} ${WRKSRC}/ishido.6 ${STAGEDIR}${PREFIX}/man/man6
	${INSTALL} ${COPY} ${STRIP} ${WRKSRC}/ishido ${STAGEDIR}${PREFIX}/bin
	${INSTALL} ${COPY} ${WRKSRC}/ishido_scores ${STAGEDIR}${PREFIX}/share/misc/ishido_scores

.include <bsd.port.mk>
