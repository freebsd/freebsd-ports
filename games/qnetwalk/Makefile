# New ports collection Makefile for:	qnetwalk
# Date created:				2004-11-12
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	qnetwalk
PORTVERSION=	1.3
CATEGORIES=	games
MASTER_SITES=	http://qt.osdn.org.ua/ \
		http://www.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Qt-version of the NetWalk game

USE_QT_VER=	4
QT_COMPONENTS=	qmake corelib gui moc rcc

MAN6=		qnetwalk.6

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} ${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qnetwalk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qnetwalk.6 ${MANPREFIX}/man/man6
	${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/sounds/*.wav ${DATADIR}/sounds
	${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${DATADIR}/translations
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/menu/qnetwalk.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/menu/qnetwalk.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
