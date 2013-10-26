# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	barbie_seahorse_adventures
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	http://www.imitationpickles.org/barbie/files/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	barbie-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
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

DESKTOP_ENTRIES="Barbie Seahorse Adventures" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/leveledit.py ${WRKSRC}/tileedit.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data lib" ${DATADIR})

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

.include <bsd.port.mk>
