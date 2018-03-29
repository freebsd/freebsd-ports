# Created by: Nikolai Lifanov <lifanov@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nxengine
PORTVERSION=	2.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	games
MASTER_SITES+=	https://www.cavestory.org/downloads/:data \
		SF/lifanov-ports-distfiles/games/${PORTNAME}/:icons
DISTFILES+=	${PORTNAME}.png:icons \
		cavestoryen.zip:data
EXTRACT_ONLY=	${DISTFILES:[2..3]:S/:data//}

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Engine-rewrite of the classic platformer Cave Story

LICENSE=	GPLv3 FREEWARE
LICENSE_COMB=	multi
LICENSE_NAME_FREEWARE=	Cave Story freeware license
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE
LICENSE_FILE_FREEWARE=	${WRKDIR}/CaveStory/Readme.txt
LICENSE_PERMS_FREEWARE=	dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES_GPLv3=	${DISTFILES:[3]}
LICENSE_DISTFILES_FREEWARE=	${DISTFILES:[2]:S/:data//}

LIB_DEPENDS=	libpng16.so:graphics/png

DESKTOP_ENTRIES="NXEngine" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;AdventureGame;" ""

USES=		cmake:outsource compiler:c++11-lang
USE_SDL=	mixer2 sdl2
SUB_FILES=	${PORTNAME}

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-evo

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nx ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/nxengine ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/data; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/data)
	(cd ${WRKDIR}/CaveStory; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${STAGEDIR}${DATADIR}; ${WRKSRC}/bin/extract)

.include <bsd.port.mk>
