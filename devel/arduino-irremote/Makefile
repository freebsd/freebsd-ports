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
USE_ZIP=	yes
USE_DOS2UNIX=	yes

NO_BUILD=	yes

PLIST_FILES=	arduino/libraries/IRremote/IRremote.cpp \
		arduino/libraries/IRremote/IRremote.h \
		arduino/libraries/IRremote/IRremoteInt.h \
		arduino/libraries/IRremote/keywords.txt
PLIST_DIRS=	arduino/libraries/IRremote

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_FILES+=	${EXAMPLESDIR_REL}/IRrecord/IRrecord.pde \
		${EXAMPLESDIR_REL}/IRrecvDemo/IRrecvDemo.pde \
		${EXAMPLESDIR_REL}/IRrecvDump/IRrecvDump.pde \
		${EXAMPLESDIR_REL}/IRrelay/IRrelay.pde \
		${EXAMPLESDIR_REL}/IRsendDemo/IRsendDemo.pde \
		${EXAMPLESDIR_REL}/IRtest/IRtest.pde
PLIST_DIRS+=	${EXAMPLESDIR_REL}/IRrecord \
		${EXAMPLESDIR_REL}/IRrecvDemo \
		${EXAMPLESDIR_REL}/IRrecvDump \
		${EXAMPLESDIR_REL}/IRrelay \
		${EXAMPLESDIR_REL}/IRsendDemo \
		${EXAMPLESDIR_REL}/IRtest \
		${EXAMPLESDIR_REL}
.endif

do-install:
	${MKDIR} ${PREFIX}/arduino/libraries/IRremote
	${INSTALL_DATA} ${WRKSRC}/IRremote.cpp ${PREFIX}/arduino/libraries/IRremote
	${INSTALL_DATA} ${WRKSRC}/IRremote.h ${PREFIX}/arduino/libraries/IRremote
	${INSTALL_DATA} ${WRKSRC}/IRremoteInt.h ${PREFIX}/arduino/libraries/IRremote
	${INSTALL_DATA} ${WRKSRC}/keywords.txt ${PREFIX}/arduino/libraries/IRremote
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
