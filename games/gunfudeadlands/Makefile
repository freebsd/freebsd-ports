PORTNAME=	gunfudeadlands
PORTVERSION=	1.01
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/GunFu%20Deadlands%20${PORTVERSION}/
DISTNAME=	GunFuDeadlands_${PORTVERSION:C/\.//}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Far West themed 2D shooter featuring bullet time

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/gpl.txt

RUN_DEPENDS=	love07:devel/love07

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.png
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="GunFu Deadlands" \
                "" \
                "${PREFIX}/share/pixmaps/${PORTNAME}.png" \
                "${PORTNAME}" \
                "Game;ArcadeGame;" \
                ""

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${DATADIR}/GunFuDeadlands.zip
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/images/guy.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
