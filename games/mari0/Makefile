# Created by: Mahdi Mokhtari <mokhi64@gmail.com>

PORTNAME=	mari0
PORTVERSION=	1.6.2
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Nintendo\'s Super Mario Bros and Valve\'s Portal at same time

LICENSE=	CC-BY-NC-SA-3.0

RUN_DEPENDS=	love:devel/love

USE_GITHUB=	yes
GH_ACCOUNT=	Stabyourself
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.png
PORTDATA=	*

DESKTOP_ENTRIES="Mari0" \
                "" \
                "mari0" \
                "${PORTNAME}" \
                "Game;ArcadeGame;" \
                ""

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ \
		'-not -name README.md -not -name \.*'
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/graphics/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
