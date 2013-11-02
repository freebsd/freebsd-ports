# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lbreakout
PORTVERSION=	010315
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice clone of classical Breakout game

USE_SDL=	sdl
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lcompat"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|"SDL/SDL|"SDL|g ; \
		 s|<SDL/SDL|<SDL|g'

pre-install:
	${MKDIR} ${STAGEDIR}/var/games/${PORTNAME}

.include <bsd.port.mk>
