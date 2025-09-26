PORTNAME=	fet
DISTVERSION=	7.5.0
CATEGORIES=	deskutils education
MASTER_SITES=	https://lalescu.ro/liviu/fet/download/ \
		https://lalescu.ro/liviu/fet/download/old/ \
		https://timetabling.de/download/ \
		https://timetabling.de/download/old/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Free timetabling software
WWW=		https://lalescu.ro/liviu/fet/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		compiler:c++17-lang gl qmake qt:${FLAVOR:S/qt//} tar:bzip2
USE_GL=		gl
_USE_QT5=	core gui network printsupport widgets buildtools:build
_USE_QT6=	base
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}

CONFLICTS_INSTALL=	${FLAVORS:@fl@fet-${fl}@}

DESKTOP_ENTRIES=	"FET" \
			"Free timetable software" \
			"" \
			"fet" \
			"Education;Qt;" \
			true

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/fet|${DATADIR}|g' \
		${WRKSRC}/src/interface/fet.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fet-cl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/fet*.gz ${STAGEDIR}${PREFIX}/share/man/man1

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	cd ${WRKSRC}/translations && ${INSTALL_DATA} *.qm ${STAGEDIR}${DATADIR}/translations

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/fet-cl --inputfile=${WRKSRC}/examples/official/by-Volker-Dirr/German_subact_constr.fet \
		--randomseeds10=1 --randomseeds11=1 --randomseeds12=1 \
		--randomseeds20=1 --randomseeds21=1 --randomseeds22=1

.include <bsd.port.mk>
