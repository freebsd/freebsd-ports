# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	pyspacewar
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://mg.pov.lt/${PORTNAME}/\
		LOCAL/beech
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Two ships duel in a gravity field

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
NO_BUILD=	yes

PORTDOCS=	NEWS.txt README.txt TODO.txt performance-notes.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 22x22 32x32 48x48

DESKTOP_ENTRIES="PySpaceWar" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
.for s in 16 22 32 48
	@cd ${WRKSRC}/src/pyspacewar/icons && \
		${MV} ${PORTNAME}${s}.png ${PORTNAME}_${s}x${s}.png
.endfor

post-install:
.for s in ${ICON_SIZES}
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/src/pyspacewar/icons/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	@${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
