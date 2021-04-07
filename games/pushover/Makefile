PORTNAME=	pushover
PORTVERSION=	0.0.5
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Pushover/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game where the goal is to push over all dominoes

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gettext gmake localbase:ldflags lua pkgconfig sdl
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer ttf

PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Pushover" \
		"Push over all dominoes" \
		"${DATADIR}/pushover.ico" \
		"pushover" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|lua5.1|lua-${LUA_VER}|' ${WRKSRC}/configure

.include <bsd.port.mk>
