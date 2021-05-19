# Created by: Mahdi Mokhtari <mokhi64@gmail.com>

PORTNAME=	mari0
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://stabyourself.net/dl.php?file=${PORTNAME}-${PORTVERSION:C/\./00/}/
DISTNAME=	${PORTNAME}-source
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Nintendo\'s Super Mario Bros and Valve\'s Portal at same time

LICENSE=	CC-BY-NC-SA-3.0

RUN_DEPENDS=	love08:devel/love08

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.gif
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Mari0" \
                "" \
                "${PREFIX}/share/pixmaps/${PORTNAME}.gif" \
                "${PORTNAME}" \
                "Game;ArcadeGame;" \
                ""

OPTIONS_DEFINE=	DOCS

post-extract:
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${PORTNAME}_${PORTVERSION}.love >/dev/null 2>&1

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${PORTVERSION}.love \
		${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/graphics/icon.gif \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.gif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
