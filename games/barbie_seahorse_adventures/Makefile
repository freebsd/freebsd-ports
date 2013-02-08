# Created by:	nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	barbie_seahorse_adventures
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://www.imitationpickles.org/barbie/files/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	barbie-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	barbie-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	You are a seahorse and you want to go to the moon!

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/barbie-${DISTVERSION}

USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	 *
PORTDOCS=	CHANGES.txt LEVELS.txt NOTES.txt README.txt TODO.txt

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Barbie Seahorse Adventures" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/leveledit.py ${WRKSRC}/tileedit.py
	@(cd ${WRKSRC} && ${RM} *.py.bak)

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data lib" ${DATADIR})
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
