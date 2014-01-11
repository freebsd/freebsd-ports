# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pushover
PORTVERSION=	0.0.5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Pushover/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A puzzle game where the goal is to push over all dominoes

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer ttf
USE_LUA=	5.1
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gettext gmake pkgconfig

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
	@${REINPLACE_CMD} -e 's|lua5.1|lua-5.1|' ${WRKSRC}/configure

.include <bsd.port.mk>
