# New ports collection makefile for:	maxr
# Date created:		23 Dec 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	maxr
PORTVERSION=	0.2.6
CATEGORIES=	games
MASTER_SITES=	http://www.maxr.org/downloads/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Mechanized Assault and Exploration Reloaded

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer net

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
MAKE_JOBS_SAFE=	yes

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
