# Created by: Neil Blakey-Milner <nbm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rockdodger
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/rpkrawczyk/rockdodger/downloads/ \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:addons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_music${EXTRACT_SUFX}:addons \
		${PORTNAME}.png:addons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Addictive rock-dodging greeblie-killing platform game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		gmake
USE_SDL=	mixer image sdl

DESKTOP_ENTRIES="Rock Dodger" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-extract:
	${TAR} xfjp ${_DISTDIR}/${PORTNAME}_music${EXTRACT_SUFX} -C \
		${WRKSRC}/data/
	@cd ${WRKSRC}/data ; ${RM} *.mod

post-patch:
	@${REINPLACE_CMD} -e 's|@gamesdir@|${DATADIR}|; \
		s|@datadir@|${PREFIX}/share|' \
		${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's|magic.mod|magic.ogg|; \
		s|getzznew.mod|getzznew.ogg|; \
		s|4est_fulla3s.mod|4est_fulla3s.ogg|; \
		s|ramcharg.mod|ramcharg.ogg|; \
		s|front_1.mod|front_1.ogg|' \
		${WRKSRC}/sound.c
	@${REINPLACE_CMD} -e 's|*.mod|*.ogg|' \
		${WRKSRC}/data/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
