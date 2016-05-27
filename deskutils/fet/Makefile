# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD$

PORTNAME=	fet
PORTVERSION=	5.29.3
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
USE_QT4=	xml \
		moc_build rcc_build uic_build

PORTEXAMPLES=	*

DESKTOP_ENTRIES="FET" \
		"Free timetable software" \
		"" \
		"fet" \
		"Education;Qt;" \
		true

OPTIONS_DEFINE=	EXAMPLES NLS ONLYCL
ONLYCL_DESC=	Build only command line version (without Qt4 GUI)

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MONLYCL}
INSTALL_TARGET=	${WRKSRC}/fet-cl
QMAKE_SOURCE_PATH=	${WRKSRC}/src/src-cl.pro
.else
USE_QT4+=	gui network
INSTALL_TARGET=	${WRKSRC}/fet
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/fet|${DATADIR}|g' \
		${WRKSRC}/src/interface/fet.cpp

do-install:
	${INSTALL_PROGRAM} ${INSTALL_TARGET} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fet-cl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/fet*.gz ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	cd ${WRKSRC}/translations && ${INSTALL_DATA} *.qm ${STAGEDIR}${DATADIR}/translations

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \. ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
