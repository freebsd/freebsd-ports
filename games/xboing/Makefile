# Created by: janek
# $FreeBSD$

PORTNAME=	xboing
PORTVERSION=	2.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 arcade game

LICENSE=	MIT

USES=		imake xorg
USE_XORG=	xpm xext x11
WRKSRC=		${WRKDIR}/xboing

OPTIONS_DEFINE=SOUND
OPTIONS_DEFAULT=SOUND
OPTIONS_SUB=yes

SOUND_MAKE_ENV=	WITHOUT_AUDIO=True

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/X11/xboing/.xboing.scr

.include <bsd.port.mk>
