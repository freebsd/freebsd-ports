PORTNAME=	xcheckers
PORTVERSION=	2.2.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://arton.cunst.net/xcheckers/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Checkers game for X11
WWW=		https://arton.cunst.net/xcheckers/index.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		imake xorg
USE_XORG=	x11 xext xpm

CFLAGS+=	-fcommon

pre-install:
	@${REINPLACE_CMD} 's:@LOCALBASE@:${LOCALBASE}:g' \
		${WRKSRC}/xcheckers.src/xcheckers.man

.include <bsd.port.mk>
