# Created by: arved
# $FreeBSD$

PORTNAME=	qnetwalk
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://qt.osdn.org.ua/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Qt-version of the NetWalk game

USE_QT4=	corelib gui qmake_build moc_build rcc_build
MAKE_JOBS_SAFE=	yes

MAN6=		qnetwalk.6

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qnetwalk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qnetwalk.6 ${MAN6PREFIX}/man/man6
	${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/sounds/*.wav ${DATADIR}/sounds
	${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${DATADIR}/translations
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/menu/qnetwalk.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/menu/qnetwalk.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
