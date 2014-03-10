# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	barbie_seahorse_adventures
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games python
MASTER_SITES=	http://www.imitationpickles.org/barbie/files/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	barbie-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org

COMMENT=	You are a seahorse and you want to go to the moon!

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/barbie-${DISTVERSION}

USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGES.txt LEVELS.txt NOTES.txt README.txt TODO.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Barbie Seahorse Adventures" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/leveledit.py ${WRKSRC}/tileedit.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data lib" ${STAGEDIR}${DATADIR})

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
