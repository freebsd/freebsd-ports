# New ports collection makefile for:	tipp10
# Date created:		2007-11-26
# Whom:			Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	tipp10
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	german
MASTER_SITES=	http://www.tipp10.de/download/
DISTNAME=	tipp10_source_v2-0-1

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A 10 finger touch typing learning program

RUN_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlite2.so:${PORTSDIR}/databases/qt4-sqlite-plugin \
		${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlite.so:${PORTSDIR}/databases/qt4-sqlite3-plugin

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui sql corelib network script qtestlib \
		qmake_build rcc_build uic_build moc_build
WRKSRC=		${WRKDIR}/source

do-configure:
	@cd ${WRKSRC} \
	&&  ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

do-install:
	${INSTALL_DATA} -d ${DATADIR}/help/img
	${INSTALL_DATA} -d ${DATADIR}/help/content
	${INSTALL_PROGRAM} ${WRKSRC}/tipp10 ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tipp10v2.template ${WRKSRC}/license.txt ${WRKSRC}/wrong.wav ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/help/content/* ${DATADIR}/help/content
	${INSTALL_DATA} ${WRKSRC}/help/img/* ${DATADIR}/help/img
	${INSTALL_DATA} ${WRKSRC}/help/index.html ${DATADIR}/help
	${INSTALL_DATA} ${WRKSRC}/help/Thumbs.db ${DATADIR}/help
	${LN} -s ${DATADIR}/tipp10 ${PREFIX}/bin

.include <bsd.port.mk>
