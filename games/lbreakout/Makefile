PORTNAME=	lbreakout
PORTVERSION=	010315
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice clone of classical Breakout game
WWW=		https://sourceforge.net/projects/lgames/files/lbreakout/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandoned by upsteam, does not support large screen resolutions. Use games/lbreakouthd instead

USES=		gmake sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
LIBS+=		-lcompat

pre-install:
	${MKDIR} ${STAGEDIR}/var/games/${PORTNAME}

post-install:
	${MV} ${STAGEDIR}/var/games/${PORTNAME}/lbreakout.hscr \
		${STAGEDIR}/var/games/${PORTNAME}/lbreakout.hscr.sample

.include <bsd.port.mk>
