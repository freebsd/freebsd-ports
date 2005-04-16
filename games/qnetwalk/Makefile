# New ports collection Makefile for:	qnetwalk
# Date created:				2004-11-12
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	qnetwalk
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://qt.osdn.org.ua/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt-version of the NetWalk game

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
USE_REINPLACE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}"

MAN6=		qnetwalk.6

QMAKE?=		qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

post-patch:
	@${REINPLACE_CMD} -e \
		"s|/usr/local|${PREFIX}|g" ${WRKSRC}/${PORTNAME}.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} ${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qnetwalk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qnetwalk.6 ${MANPREFIX}/man/man6
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/sounds/*.wav ${DATADIR}/sounds
	@${MKDIR} ${DATADIR}/translations
	${INSTALL_DATA} ${WRKSRC}/translations/*.qm ${DATADIR}/translations

.include <bsd.port.mk>
