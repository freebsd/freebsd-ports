# New ports collection makefile for:	maxr
# Date created:		23 Dec 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	maxr
PORTVERSION=	0.2.3
CATEGORIES=	games
MASTER_SITES=	http://www.maxthegame.de/downloads/ \
		http://mirror.amdmi3.ru/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Mechanized Assault and Exploration Reloaded

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer net

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS=/ s|-lSDL_|`${SDL_CONFIG} --libs` &|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/SettingsData.*Path =/ s|"\(.*\)"|"${DATADIR}/\1"|' \
		${WRKSRC}/src/loaddata.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/maxr ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} "*" ${DATADIR}

.include <bsd.port.mk>
