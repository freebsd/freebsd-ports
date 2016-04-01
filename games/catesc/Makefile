# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	catesc
PORTVERSION=	0.6
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Escape of the cat - hardcode oldschool platformer

LICENSE=	CCbySA30 CCbySA40
LICENSE_COMB=		multi
LICENSE_NAME_CCbySA30=	Creative Commons Attribution-ShareAlike 3.0 Unported license
LICENSE_NAME_CCbySA40=	Creative Commons Attribution-ShareAlike 4.0 International Public License
LICENSE_TEXT_CCbySA30=	https://creativecommons.org/licenses/by-sa/3.0/legalcode
LICENSE_TEXT_CCbySA40=	https://creativecommons.org/licenses/by-sa/4.0/legalcode
LICENSE_PERMS_CCbySA30=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_CCbySA40=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

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
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
