# New ports collection makefile for:	djgame2
# Date created:		4 May 2007
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	djgame2
PORTVERSION=	3.1.2
CATEGORIES=	games
MASTER_SITES=	http://www.bluedj.com/download/src/
DISTNAME=	source-${PORTVERSION}
#EXTRACT_SUFX=	.zip

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	bluedj contains many popular online games

NO_BUILD=	yes
USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake gui moc qt3support uic rcc

QMAKE?=		qmake-qt4
QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++
MAKE_ENV=	QMAKESPEC="{QMAKESPEC}"

WRKSRC=		${WRKDIR}/${DISTNAME}
DATADIR=	${PREFIX}/share/djgame2

post-patch:
	${RM} -f ${WRKSRC}/Hall/HallRes/platform/x11/install
	@${SED} -e 's|%%DATADIR%%|${DATADIR}|' \
		< ${FILESDIR}/djgame2.desktop.in > ${WRKDIR}/djgame2.desktop
	@${SED} -e 's|%%DATADIR%%|${DATADIR}|' \
		< ${FILESDIR}/startdjg.in > ${WRKDIR}/startdjg
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|g' \
		${WRKSRC}/Base/src/PlayWave.cpp
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/makelinux
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE}|' \
		${WRKSRC}/makelinux
	@${ECHO_CMD} "INCLUDEPATH += ${X11BASE}/include" \
		>> ${WRKSRC}/Base/Base.pro
	@${ECHO_CMD} "INCLUDEPATH += ${X11BASE}/include" \
		>> ${WRKSRC}/Hall/Hall.pro
	@${CHMOD} a+x ${WRKSRC}/makelinux

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./makelinux

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/Hall/release; ${TAR} -cf - *) | \
	${TAR}  -xf - -C ${DATADIR}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/djgame2.desktop ${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${WRKDIR}/startdjg ${PREFIX}/bin

.include <bsd.port.mk>
