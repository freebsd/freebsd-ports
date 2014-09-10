# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	maxr
PORTVERSION=	0.2.8
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.maxr.org/downloads/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Mechanized Assault and Exploration Reloaded

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer net

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="M.A.X.R." \
		"Mechanized Assault and Exploration Reloaded" \
		"${DATADIR}/maxr.png" \
		"maxr" \
		"Game;StrategyGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS=/ s|-lSDL_|`${SDL_CONFIG} --libs` &|' \
		-e '/^LIBS=/ s|-lSDL |`${SDL_CONFIG} --libs` |' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|cp -a|cp -RpP|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
