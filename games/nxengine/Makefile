PORTNAME=	nxengine
DISTVERSION=	2.6.5-1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES+=	https://www.cavestory.org/downloads/:data
DISTFILES+=	cavestoryen.zip:data

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Engine-rewrite of the classic platformer Cave Story
WWW=		https://github.com/nxengine/nxengine-evo

LICENSE=	GPLv3 FREEWARE
LICENSE_COMB=	multi
LICENSE_NAME_FREEWARE=	Cave Story freeware license
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE
LICENSE_FILE_FREEWARE=	${WRKDIR}/CaveStory/Readme.txt
LICENSE_PERMS_FREEWARE=	dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES_GPLv3=	${DISTFILES:[3]}
LICENSE_DISTFILES_FREEWARE=	${DISTFILES:[2]:S/:data//}

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c++11-lang jpeg sdl
USE_SDL=	image2 mixer2 sdl2

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-evo

DESKTOP_ENTRIES="NXEngine" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;AdventureGame;" ""

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/data)
	(cd ${WRKDIR}/CaveStory; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${DATADIR}; ${STAGEDIR}${PREFIX}/bin/nxextract)

.include <bsd.port.mk>
