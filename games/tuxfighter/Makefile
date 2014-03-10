# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	tuxfighter
PORTVERSION=	54
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	SF/pygamebook/TuxFighter/TuxFighter${PORTVERSION}_source/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	TuxFighter${DISTVERSION}.tar.gz \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Little Asteroids-like Shooter game

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}

USE_PYTHON=	yes

PORTDOCS=	readme_TuxFighter54.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="TuxFighter" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DATADIR}

.for d in  *.py *.pyc *.pyo
	@(cd ${WRKSRC} ; ${INSTALL_SCRIPT} ${d} ${STAGEDIR}${DATADIR})
.endfor

	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})

post-install:
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
