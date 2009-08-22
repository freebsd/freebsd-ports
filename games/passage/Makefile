# New ports collection makefile for:	passage
# Date created:		23 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	passage
PORTVERSION=	3
CATEGORIES=	games
MASTER_SITES=	SF/hcsoftware/Passage/v${PORTVERSION}
DISTNAME=	Passage_v${PORTVERSION}_UnixSource

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An experimental video game by Jason Rohrer

USE_SDL=	sdl

WRKSRC=		${WRKDIR}/${DISTNAME}/gamma256/gameSource

post-patch:
	@${REINPLACE_CMD} -e 's|-lSDL||' ${WRKSRC}/Makefile.GnuLinux
	@${REINPLACE_CMD} -e 's|"graphics"|"${DATADIR}/graphics"|' \
		${WRKSRC}/common.cpp
	@${REINPLACE_CMD} -e 's|"music"|"${DATADIR}/music"|' \
		${WRKSRC}/musicPlayer.cpp
	@${REINPLACE_CMD} -e 's|"settings"|"${DATADIR}/settings"|' \
		${WRKDIR}/${DISTNAME}/minorGems/util/SettingsManager.cpp

do-configure:
	cd ${WRKSRC} && ${CAT} Makefile.GnuLinux Makefile.all > Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Passage ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for d in graphics music settings
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR}
.endfor

.include <bsd.port.mk>
