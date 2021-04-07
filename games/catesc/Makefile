PORTNAME=	catesc
PORTVERSION=	0.6
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Escape of the cat - hardcore oldschool platformer

LICENSE=	CC-BY-SA-3.0 CC-BY-SA-4.0
LICENSE_COMB=	multi

RUN_DEPENDS=	instead:games/instead

USE_GITHUB=	yes
GH_ACCOUNT=	gl00my

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/instead/games/${PORTNAME}

PLIST_FILES=	share/pixmaps/${PORTNAME}.png
PORTDATA=	*

DESKTOP_ENTRIES="Escape of the cat" \
		"Hardcore oldschool platformer" \
		"${PORTNAME}" \
		"${LOCALBASE}/bin/instead ${DATADIR}" \
		"Game;ArcadeGame;" \
		""

do-install:
	${INSTALL_DATA} ${WRKSRC}/pic/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
