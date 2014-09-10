# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	passage
PORTVERSION=	4
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/hcsoftware/Passage/v${PORTVERSION}
DISTNAME=	Passage_v${PORTVERSION}_UnixSource

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Experimental video game by Jason Rohrer

USE_SDL=	sdl

WRKSRC=		${WRKDIR}/${DISTNAME}/gamma256/gameSource

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|^\(PLATFORM_LINK_FLAGS =\).*|\1 ${PTHREAD_LIBS}|' \
		${WRKSRC}/Makefile.GnuLinux
	@${REINPLACE_CMD} -e 's|"graphics"|"${DATADIR}/graphics"|' \
		${WRKSRC}/common.cpp
	@${REINPLACE_CMD} -e 's|"music"|"${DATADIR}/music"|' \
		${WRKSRC}/musicPlayer.cpp
	@${REINPLACE_CMD} -e 's|"settings"|"${DATADIR}/settings"|' \
		${WRKDIR}/${DISTNAME}/minorGems/util/SettingsManager.cpp

do-configure:
	cd ${WRKSRC} && ${CAT} Makefile.GnuLinux Makefile.all > Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Passage ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "graphics music settings" ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
