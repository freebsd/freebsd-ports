# New ports collection Makefile for:	qnetwalk
# Date created:				2004-11-12
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	qnetwalk
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://qt.osdn.org.ua/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-version of the NetWalk game

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
QMAKE?=		qmake
USE_REINPLACE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}"

do-configure:
	${REINPLACE_CMD} -e "s,/usr/local/share/games/qnetwalk,${DATADIR}," ${WRKSRC}/qnetwalk.pro
	${REINPLACE_CMD} -e "s,share/games/,share/," ${WRKSRC}/main.cpp ${WRKSRC}/mainwindow.cpp
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} ${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qnetwalk ${PREFIX}/bin
	${MKDIR} ${DATADIR}/sounds
	cd ${WRKSRC}; ${INSTALL_DATA} qnetwalk_ru.qm ${DATADIR}
	cd ${WRKSRC}; ${INSTALL_DATA} sounds/click.wav \
		sounds/connect.wav sounds/start.wav sounds/turn.wav \
		sounds/win.wav ${DATADIR}/sounds

.include <bsd.port.mk>
