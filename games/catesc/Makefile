# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	catesc
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Escape of the cat - hardcode oldschool platformer

RUN_DEPENDS=	instead:${PORTSDIR}/games/instead

USE_GITHUB=	yes
GH_ACCOUNT=	gl00my
GH_TAGNAME=	d84d277
GH_COMMIT=	d84d277

NO_BUILD=	yes

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
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
