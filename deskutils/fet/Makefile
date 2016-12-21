# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD$

PORTNAME=	fet
PORTVERSION=	5.30.7
CATEGORIES=	deskutils kde
MASTER_SITES=	http://lalescu.ro/liviu/fet/download/ \
		http://lalescu.ro/liviu/fet/download/old/ \
		http://timetabling.de/download/ \
		http://timetabling.de/download/old/

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Free timetabling software

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake tar:bzip2

PORTEXAMPLES=	*

DESKTOP_ENTRIES="FET" \
		"Free timetable software" \
		"" \
		"fet" \
		"Education;Qt;" \
		true

OPTIONS_DEFINE=	EXAMPLES NLS ONLYCL
OPTIONS_SINGLE=	QTVER
OPTIONS_SINGLE_QTVER=	QT4 QT5
OPTIONS_DEFAULT=	EXAMPLES NLS QT4
ONLYCL_DESC=	Build only command line version (without Qt GUI)

OPTIONS_SUB=	yes

QT4_USE=	QT4=corelib,moc_build,rcc_build,uic_build,xml
QT5_USE=	QT5=buildtools_build,core,xml GL=gl

.include <bsd.port.options.mk>

INSTALL_TARGET=	${WRKSRC}/fet-cl
.if ${PORT_OPTIONS:MONLYCL}
QMAKE_SOURCE_PATH=	${WRKSRC}/src/src-cl.pro
.else
INSTALL_TARGET+=	${WRKSRC}/fet
.if ${PORT_OPTIONS:MQT4}
USE_QT4+=gui network
.else
USE_QT5+=gui network printsupport widgets
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/fet|${DATADIR}|g' \
		${WRKSRC}/src/interface/fet.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_TARGET} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fet-cl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/fet*.gz ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	cd ${WRKSRC}/translations && ${INSTALL_DATA} *.qm ${STAGEDIR}${DATADIR}/translations

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
