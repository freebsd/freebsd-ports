PORTNAME=	flobopuyo
PORTVERSION=	0.20
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	http://www.ios-software.com/flobopuyo/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Clone of the famous PuyoPuyo
WWW=		http://www.ios-software.com/?page=projet&quoi=29&lg=AN

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison dos2unix gmake sdl tar:tgz
DOS2UNIX_FILES=	IosVector.cpp PuyoGame.cpp
USE_SDL=	sdl mixer image

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="FloboPuyo" \
		"Clone of the famous PuyoPuyo" \
		"${DATADIR}/gfx/Neutral.png" \
		"flobopuyo" \
		"Game;BlocksGame;" \
		false

post-extract:
	@${FIND} ${WRKSRC} -name '._*' -delete

.include <bsd.port.mk>
