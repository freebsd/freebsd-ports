# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iceicepenguin
PORTVERSION=	1.5.1
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/Default/Ice%20Ice%20Penguin/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	iip.${DISTVERSION}-final${EXTRACT_SUFX} \
		${PORTNAME}_icons_1${EXTRACT_SUFX}:icons
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remake of an old SEGA Dreamcast game called Chu Chu Rocket

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/"ice ice penguin"

USES=		python:run zip
NO_BUILD=	yes

PORTDOCS=	CHANGELOG.txt readme.txt
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Ice Ice Penguin" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in fonts gfx lvls menu sfx
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
