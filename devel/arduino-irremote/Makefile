# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	arduino-irremote
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://files.arcfn.com/files/
DISTNAME=	IRremote

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Multi-protocol infrared remote library for the Arduino

LICENSE=	LGPL21

RUN_DEPENDS=	arduino:${PORTSDIR}/devel/arduino

WRKSRC=		${WRKDIR}/IRremote
USES=		zip dos2unix

NO_BUILD=	yes

PLIST_FILES=	arduino/libraries/IRremote/IRremote.cpp \
		arduino/libraries/IRremote/IRremote.h \
		arduino/libraries/IRremote/IRremoteInt.h \
		arduino/libraries/IRremote/keywords.txt
PLIST_DIRS=	arduino/libraries/IRremote
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/arduino/libraries/IRremote
	(cd ${WRKSRC} && ${INSTALL_DATA} IRremote.cpp IRremote.h IRremoteInt.h \
		keywords.txt ${STAGEDIR}${PREFIX}/arduino/libraries/IRremote)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
