# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	tipp10
DISTVERSION=	2-1-0
PORTREVISION=	3
CATEGORIES=	german
MASTER_SITES=	http://www.tipp10.com/en/download/
DISTNAME=	tipp10_source_v${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	10-finger touch typing learning program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license_en.txt

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake dos2unix qt:4 zip
DOS2UNIX_GLOB=	*.pro *.cpp
USE_QT=		corelib gui network sql rcc_build uic_build moc_build \
		sql-sqlite3_run

pre-configure:
	cd ${WRKSRC} \
	&& for i in `grep -lR 'QCoreApplication::applicationDirPath()' *`; do \
		${REINPLACE_CMD} -e 's,QCoreApplication::applicationDirPath(),QString("${DATADIR}"),g' $$i ; done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tipp10 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/help/de/img
	${MKDIR} ${STAGEDIR}${DATADIR}/help/de/content
	${MKDIR} ${STAGEDIR}${DATADIR}/help/en/img
	${MKDIR} ${STAGEDIR}${DATADIR}/help/en/content
	${INSTALL_DATA} ${WRKSRC}/release/tipp10v2.template ${WRKSRC}/metronome.wav ${WRKSRC}/error.wav ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/release/help/de/index.html ${STAGEDIR}${DATADIR}/help/de
	${INSTALL_DATA} ${WRKSRC}/release/help/de/content/* ${STAGEDIR}${DATADIR}/help/de/content
	${INSTALL_DATA} ${WRKSRC}/release/help/de/img/* ${STAGEDIR}${DATADIR}/help/de/img
	${INSTALL_DATA} ${WRKSRC}/release/help/en/index.html ${STAGEDIR}${DATADIR}/help/en
	${INSTALL_DATA} ${WRKSRC}/release/help/en/content/* ${STAGEDIR}${DATADIR}/help/en/content
	${INSTALL_DATA} ${WRKSRC}/release/help/en/img/* ${STAGEDIR}${DATADIR}/help/en/img
.include <bsd.port.mk>
