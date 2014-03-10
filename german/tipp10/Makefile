# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	tipp10
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	german
MASTER_SITES=	http://www.tipp10.com/en/download/
DISTNAME=	tipp10_source_v2-1-0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	10-finger touch typing learning program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license_en.txt

USES=		qmake dos2unix zip
DOS2UNIX_GLOB=	*.pro *.cpp
USE_QT4=	gui sql corelib network script qtestlib \
		rcc_build uic_build moc_build \
		sql-sqlite2_run sql-sqlite3_run
QMAKE_ARGS+=	DATADIR="${DATADIR}"
WRKSRC=		${WRKDIR}/tipp10_source_v2-1-0

pre-configure:
	@cd ${WRKSRC} \
	&& for i in `grep -lR 'QCoreApplication::applicationDirPath()' *`; do ${REINPLACE_CMD} -e 's/QCoreApplication::applicationDirPath()/QString(DATADIR)/g' $$i ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tipp10 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} -d ${STAGEDIR}${DATADIR}/help/de/img
	${INSTALL_DATA} -d ${STAGEDIR}${DATADIR}/help/de/content
	${INSTALL_DATA} -d ${STAGEDIR}${DATADIR}/help/en/img
	${INSTALL_DATA} -d ${STAGEDIR}${DATADIR}/help/en/content
	${INSTALL_DATA} ${WRKSRC}/release/tipp10v2.template ${WRKSRC}/metronome.wav ${WRKSRC}/error.wav ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/release/help/de/index.html ${STAGEDIR}${DATADIR}/help/de
	${INSTALL_DATA} ${WRKSRC}/release/help/de/content/* ${STAGEDIR}${DATADIR}/help/de/content
	${INSTALL_DATA} ${WRKSRC}/release/help/de/img/* ${STAGEDIR}${DATADIR}/help/de/img
	${INSTALL_DATA} ${WRKSRC}/release/help/en/index.html ${STAGEDIR}${DATADIR}/help/en
	${INSTALL_DATA} ${WRKSRC}/release/help/en/content/* ${STAGEDIR}${DATADIR}/help/en/content
	${INSTALL_DATA} ${WRKSRC}/release/help/en/img/* ${STAGEDIR}${DATADIR}/help/en/img
.include <bsd.port.mk>
