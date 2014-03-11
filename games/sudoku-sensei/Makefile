# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sudoku-sensei
PORTVERSION=	02.00
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-for-linux/Source%20and%20exe%20files%20for%20linux%2C%20ver.%202.00/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-src-${DISTVERSION:S/./-/}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-src-${DISTVERSION:S/./-/}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Enjoy playing with Sudoku boards designed by yourself

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/SudokuSenseiSources

USES=		qmake
USE_QT4=	moc_build uic_build corelib gui iconengines_run imageformats_run

SUB_FILES=	${PORTNAME} pkg-deinstall pkg-message

DESKTOP_ENTRIES="Sudoku Sensei" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" ""

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in board doc images language saves system
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/SudokuSensei ${STAGEDIR}${DATADIR}

.for d in SudokuSensei.rc license.txt
	@(cd ${WRKSRC} && ${CP} -a ${d} ${STAGEDIR}${DATADIR})
.endfor
# Fix Permission that user can write in saves and system directories
	@(cd ${STAGEDIR}${DATADIR} && ${CHMOD} -R 775 saves system)

	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
