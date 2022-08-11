PORTNAME=	xcheckers
PORTVERSION=	2.2.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://arton.cunst.net/xcheckers/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checkers game for X11

BROKEN_FreeBSD_13=	duplicate symbol: board
BROKEN_FreeBSD_14=	duplicate symbol: board

USES=		imake xorg
USE_XORG=	x11 xext xpm

post-patch:
	@${REINPLACE_CMD} '/^#/d' ${WRKSRC}/Local.config

pre-install:
	@${REINPLACE_CMD} 's:@LOCALBASE@:${LOCALBASE}:g' \
		${WRKSRC}/xcheckers.src/xcheckers.man

.include <bsd.port.mk>
