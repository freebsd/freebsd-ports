PORTNAME=	passage
PORTVERSION=	4
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/hcsoftware/Passage/v${PORTVERSION}
DISTNAME=	Passage_v${PORTVERSION}_UnixSource

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Experimental video game by Jason Rohrer

USES=		sdl
USE_SDL=	sdl

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/gamma256/gameSource

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|"graphics"|"${DATADIR}/graphics"|' \
		${WRKSRC}/gamma256/gameSource/common.cpp
	@${REINPLACE_CMD} -e 's|"music"|"${DATADIR}/music"|' \
		${WRKSRC}/gamma256/gameSource/musicPlayer.cpp
	@${REINPLACE_CMD} -e 's|"settings"|"${DATADIR}/settings"|' \
		${WRKSRC}/minorGems/util/SettingsManager.cpp

do-configure:
	cd ${BUILD_WRKSRC} && ${CAT} Makefile.GnuLinux Makefile.all > Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Passage ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC} && ${COPYTREE_SHARE} "graphics music settings" ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
