# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD$

PORTNAME=	fet
PORTVERSION=	5.20.1
CATEGORIES=	deskutils kde
MASTER_SITES=	http://lalescu.ro/liviu/fet/download/ \
		http://lalescu.ro/liviu/fet/download/old/ \
		http://timetabling.de/download/ \
		http://timetabling.de/download/old/

MAINTAINER=	salfrancl@yahoo.es
COMMENT=	Free timetabling software

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_BZIP2=	yes
USE_QT4=	gui network xml \
		moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes

PORTEXAMPLES=	*

DESKTOP_ENTRIES="FET" \
		"Free timetable software" \
		"" \
		"fet" \
		"Education;Qt;" \
		true

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/fet|${DATADIR}|g' \
		${WRKSRC}/src/interface/fet.cpp

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fet-cl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/fet.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \. ${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${STAGEDIR}${DATADIR}/translations
	cd ${WRKSRC}/translations && ${INSTALL_DATA} *.qm ${STAGEDIR}${DATADIR}/translations
.endif

.include <bsd.port.mk>
