# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	netrek-client-cow
PORTVERSION=	3.3.2
CATEGORIES=	games
MASTER_SITES=	http://www.netrek.org/files/COW/ \
		http://quozl.us.netrek.org/netrek/

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Multi-player battle simulation with a Star Trek theme

LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		gmake sdl xorg
USE_SDL=	mixer sdl
USE_XORG=	x11 xau xcb xdmcp xext xpm xxf86vm

GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/netrek-client-cow.desktop \
		${WRKSRC}/sound.c \
		${WRKSRC}/x11sprite.c
	${REINPLACE_CMD} -e 's|8000, AUDIO_U8, 1|22050, AUDIO_U8, 2|' \
		${WRKSRC}/sound.c
	${REINPLACE_CMD} -e 's|games|bin|' \
		${WRKSRC}/netrek-client-cow.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/netrek-client-cow

.include <bsd.port.mk>
