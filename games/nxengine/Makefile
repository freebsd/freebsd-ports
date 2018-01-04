# Created by: Nikolai Lifanov <lifanov@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nxengine
PORTVERSION=	1.0.0.6
CATEGORIES=	games
MASTER_SITES=	http://nxengine.sourceforge.net/dl/ \
		http://www.cavestory.org/downloads/:data \
		SF/lifanov-ports-distfiles/games/${PORTNAME}/:icons
DISTFILES=	nx-src-${DISTVERSION:S/.//g}.tar.bz2 \
		cavestoryen.zip:data \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${DISTFILES:[1..2]:S/:data//}

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Engine-rewrite of the classic platformer Cave Story

LICENSE=	GPLv3 FREEWARE
LICENSE_COMB=	multi
LICENSE_NAME_FREEWARE=	Cave Story freeware license
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE
LICENSE_FILE_FREEWARE=	${WRKDIR}/CaveStory/Readme.txt
LICENSE_PERMS_FREEWARE=	dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES_GPLv3=	${DISTFILES:[1]}
LICENSE_DISTFILES_FREEWARE=	${DISTFILES:[2]:S/:data//}

DESKTOP_ENTRIES="NXEngine" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;AdventureGame;" ""

WRKSRC=		${WRKDIR}/nx
USE_SDL=	sdl ttf
SUB_FILES=	${PORTNAME}

pre-build:
	@${REINPLACE_CMD} -e 's!g++!${CXX}!' ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/nx ${STAGEDIR}${DATADIR}
.for f in sprites.sif smalfont.bmp tilekey.dat font.ttf
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/nxengine ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKDIR}/CaveStory; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
