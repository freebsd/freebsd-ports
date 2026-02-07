PORTNAME=	zatacka
PORTVERSION=	0.1.8
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Nibbles-like multiplayer game
WWW=		https://zatacka.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

USES=		gmake sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl ttf image
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="Zatacka" \
		"Nibbles-like multiplayer game" \
		"" \
		"zatacka" \
		"Game;ArcadeGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|__linux__|__FreeBSD__|; s|\[30\]|[PATH_MAX]|' \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
