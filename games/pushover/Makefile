# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pushover
PORTVERSION=	0.0.5
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Pushover/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game where the goal is to push over all dominoes

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer ttf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gettext gmake lua pkgconfig sdl

PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Pushover" \
		"Push over all dominoes" \
		"${DATADIR}/pushover.ico" \
		"pushover" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|lua5.1|lua-${LUA_VER}|' ${WRKSRC}/configure

.include <bsd.port.mk>
