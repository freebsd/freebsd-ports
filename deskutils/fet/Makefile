# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD$

PORTNAME=	fet
DISTVERSION=	5.40.3
CATEGORIES=	deskutils
MASTER_SITES=	http://lalescu.ro/liviu/fet/download/ \
		http://lalescu.ro/liviu/fet/download/old/ \
		http://timetabling.de/download/ \
		http://timetabling.de/download/old/

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Free timetabling software

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++14-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build core printsupport widgets xml
USE_CXXSTD=	c++14

PORTEXAMPLES=	*

DESKTOP_ENTRIES="FET" \
		"Free timetable software" \
		"" \
		"fet" \
		"Education;Qt;" \
		true

OPTIONS_DEFINE=	EXAMPLES NLS ONLYCL
ONLYCL_DESC=	Build only command line version (without Qt GUI)

OPTIONS_SUB=	yes

INSTALL_TARGET=	${WRKSRC}/fet-cl
ONLYCL_VARS=	QMAKE_SOURCE_PATH=${WRKSRC}/src/src-cl.pro
ONLYCL_VARS_OFF=	INSTALL_TARGET+=${WRKSRC}/fet USE_QT+="gui network"

.include <bsd.port.options.mk>

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
