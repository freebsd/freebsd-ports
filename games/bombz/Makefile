# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bombz
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/ \
		SF/nemysisfreebsdp/games/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Simple 2D puzzle game with bombs

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/Bombz

USES= 		dos2unix zip
DOS2UNIX_FILES=	*.txt
USE_SDL=	sdl image mixer
INSTALLS_ICONS=	yes
USE_PYTHON=	yes

PORTDOCS=	ChangeLog readme.txt

SUB_FILES=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -i '' '/words = name.split()/,/self.name = name/s/^/#/' \
		${WRKSRC}/bombz/joy.py
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}.py

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in bombz levels pngs sounds FreeSans.ttf
	@(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
.for d in *.py *.pyc *.pyo
	@(cd ${WRKSRC} ; ${INSTALL_SCRIPT} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
