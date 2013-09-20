# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	tipp10
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	german
MASTER_SITES=	http://www.tipp10.com/en/download/
DISTNAME=	tipp10_source_v2-1-0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 10 finger touch typing learning program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license_en.txt

RUN_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlite2.so:${PORTSDIR}/databases/qt4-sqlite-plugin \
		${LOCALBASE}/lib/qt4/plugins/sqldrivers/libqsqlite.so:${PORTSDIR}/databases/qt4-sqlite3-plugin

USE_ZIP=	yes
USE_QT4=	gui sql corelib network script qtestlib \
		qmake_build rcc_build uic_build moc_build
WRKSRC=		${WRKDIR}/tipp10_source_v2-1-0

NO_STAGE=	yes
pre-configure:
	@cd ${WRKSRC} \
	&& for i in `grep -lR 'QCoreApplication::applicationDirPath()' *`; do ${REINPLACE_CMD} -e 's/QCoreApplication::applicationDirPath()/QString(DATADIR)/g' $$i ; done

do-configure:
	cd ${WRKSRC} \
	&&  ${SETENV} ${MAKE_ENV} DATADIR="${DATADIR}" ${QMAKE} -spec ${QMAKESPEC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tipp10 ${PREFIX}/bin
	${INSTALL_DATA} -d ${DATADIR}/help/de/img
	${INSTALL_DATA} -d ${DATADIR}/help/de/content
	${INSTALL_DATA} -d ${DATADIR}/help/en/img
	${INSTALL_DATA} -d ${DATADIR}/help/en/content
	${INSTALL_DATA} ${WRKSRC}/release/tipp10v2.template ${WRKSRC}/metronome.wav ${WRKSRC}/error.wav ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/release/help/de/index.html ${DATADIR}/help/de
	${INSTALL_DATA} ${WRKSRC}/release/help/de/content/* ${DATADIR}/help/de/content
	${INSTALL_DATA} ${WRKSRC}/release/help/de/img/* ${DATADIR}/help/de/img
	${INSTALL_DATA} ${WRKSRC}/release/help/en/index.html ${DATADIR}/help/en
	${INSTALL_DATA} ${WRKSRC}/release/help/en/content/* ${DATADIR}/help/en/content
	${INSTALL_DATA} ${WRKSRC}/release/help/en/img/* ${DATADIR}/help/en/img
.include <bsd.port.mk>
