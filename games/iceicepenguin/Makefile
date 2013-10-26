# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	iceicepenguin
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/Default/Ice%20Ice%20Penguin/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	iip.${DISTVERSION}-final${EXTRACT_SUFX} \
		${PORTNAME}_icons_1${EXTRACT_SUFX}:icons
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Remake of an old SEGA Dreamcast game called Chu Chu Rocket

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/"ice ice penguin"

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGELOG.txt readme.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Ice Ice Penguin" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.for d in fonts gfx lvls menu sfx
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
