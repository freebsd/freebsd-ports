# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	tuxfighter
PORTVERSION=	54
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	SF/pygamebook/TuxFighter/TuxFighter${PORTVERSION}_source/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	TuxFighter${DISTVERSION}.tar.gz \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Little Asteroids-like Shooter game

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}

FETCH_ARGS?=	-Fpr
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	readme_TuxFighter54.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="TuxFighter" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR}

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
