# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	flobopuyo
PORTVERSION=	0.20
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://www.ios-software.com/flobopuyo/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Clone of the famous PuyoPuyo

USES=		bison gmake dos2unix
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
