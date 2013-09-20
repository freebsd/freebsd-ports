# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	qonk
PORTVERSION=	0.3.1
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small space build and conquer strategy game

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl gfx ttf image

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lSDL |`${SDL_CONFIG} --libs` |' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|settings.h|../&|; s|canvas.h|../&|' \
		${WRKSRC}/src/ui/menusystem.cpp

.include <bsd.port.mk>
