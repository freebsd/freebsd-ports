# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuxfighter
PORTVERSION=	54
PORTREVISION=	9
CATEGORIES=	games python
MASTER_SITES=	SF/pygamebook/TuxFighter/TuxFighter${PORTVERSION}_source/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	TuxFighter${DISTVERSION}.tar.gz \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Little Asteroids-like Shooter game

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL.txt

RUN_DEPENDS=	${PYGAME}

USES=		gnome python:2.7 shebangfix
SHEBANG_FILES=	TuxFighter54.py

PORTDOCS=	readme_TuxFighter54.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME} pkg-message

DESKTOP_ENTRIES="TuxFighter" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR})
.for f in *.py *.pyc *.pyo
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
