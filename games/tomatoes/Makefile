# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomatoes
PORTVERSION=	1.5
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-linux-src-${PORTVERSION}5${EXTRACT_SUFX} \
		${PORTNAME}-linux-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tomato-smashing, Q-Bert style

WRKSRC=		${WRKDIR}/tomatoes-${PORTVERSION}5
TDATA=		${WRKDIR}/tomatoes-${PORTVERSION}

USE_BZIP2=	yes
USE_SDL=	mixer image
USE_GL=		gl
USES=		gmake
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CXX}" \
		MPKDIR="${DATADIR}/" \
		MUSICDIR="${DATADIR}/music/" \
		HISCOREDIR="${DATADIR}/" \
		CONFIGDIR="${DATADIR}/" \
		CFLAGS="${CXXFLAGS} ${SDL_CFLAGS}" \
		LDFLAGS="${SDL_LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

SDL_CFLAGS=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include
SDL_LDFLAGS=	`${SDL_CONFIG} --libs` -lSDL_image -lSDL_mixer \
		-L${LOCALBASE}/lib -lGL -lGLU

DESKTOP_ENTRIES="Tomatoes" \
		"${COMMENT}" \
		"${DATADIR}/icon.png" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/music
	${INSTALL_DATA} ${TDATA}/config.cfg ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${TDATA}/tomatoes.mpk ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/icon.png ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${TDATA}/music/IHaveNoTomatoes.it ${STAGEDIR}${DATADIR}/music

.include <bsd.port.mk>
