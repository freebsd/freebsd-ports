# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	barbie_seahorse_adventures
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	http://www.imitationpickles.org/barbie/files/
DISTNAME=	barbie-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	You are a seahorse and you want to go to the moon!

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/barbie-${DISTVERSION}

USES=		dos2unix python:2.7 shebangfix tar:tgz
SHEBANG_FILES=	run_game.py create-upload.py
DOS2UNIX_GLOB=	*.py
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	CHANGES.txt LEVELS.txt NOTES.txt README.txt
OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 64x64 128x128

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Barbie Seahorse Adventures" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-extract:
	@cd ${WRKSRC} && ${RM} data/REMOVE_ME.txt data/sample.txt \
		lib/pgu/LICENSE.txt

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/leveledit.py ${WRKSRC}/tileedit.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete
.for s in 32 64 128
	@cd ${WRKSRC} && \
		${MV} icon${s}.png ${PORTNAME}_${s}x${s}.png
.endfor

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data lib" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
