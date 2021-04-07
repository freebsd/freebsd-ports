PORTNAME=	biloba
PORTVERSION=	0.9.3
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Biloba/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Strategy board game for 2 to 4 players

GNU_CONFIGURE=	yes
USES=		gmake sdl
USE_SDL=	image mixer sdl

PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}-server
PORTDATA=	*

# Fix build with clang11
CFLAGS+=	-fcommon

DESKTOP_ENTRIES="Biloba" \
		"A strategy board game for 2 to 4 players" \
		"${DATADIR}/biloba_icon.png" \
		"biloba" \
		"Game;LogicGame;" \
		false

post-install:
	${INSTALL_DATA} ${WRKSRC}/biloba_icon.png ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
