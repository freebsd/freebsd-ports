PORTNAME=	biloba
PORTVERSION=	0.9.3
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Biloba/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Strategy board game for 2 to 4 players
WWW=		https://biloba.sourceforge.net/

USES=		gmake sdl
GNU_CONFIGURE=	yes
USE_SDL=	image mixer sdl

PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}-server
PORTDATA=	*

# Fix build with clang11
CFLAGS+=	-fcommon

DESKTOP_ENTRIES="Biloba" \
		"" \
		"${DATADIR}/biloba_icon.png" \
		"biloba" \
		"Game;LogicGame;" \
		false

post-install:
	${INSTALL_DATA} ${WRKSRC}/biloba_icon.png ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
