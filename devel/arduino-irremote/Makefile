# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	arduino-irremote
PORTVERSION=	2.1.0
CATEGORIES=	devel

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Multi-protocol infrared remote library for the Arduino

LICENSE=	LGPL21

RUN_DEPENDS=	arduino:devel/arduino

USES=		dos2unix
USE_GITHUB=	yes
GH_ACCOUNT=	z3t0
GH_PROJECT=	Arduino-IRremote

NO_BUILD=	yes

FILES=		IRremote.cpp IRremote.h IRremoteInt.h irPronto.cpp \
		irRecv.cpp irSend.cpp ir_Aiwa.cpp ir_Denon.cpp \
		ir_Dish.cpp ir_JVC.cpp ir_LG.cpp ir_Mitsubishi.cpp \
		ir_NEC.cpp ir_Panasonic.cpp ir_RC5_RC6.cpp \
		ir_Samsung.cpp ir_Sanyo.cpp ir_Sharp.cpp ir_Sony.cpp \
		ir_Template.cpp ir_Whynter.cpp keywords.txt \

PLIST_FILES=	${FILES:S,^,arduino/libraries/IRremote/,}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/arduino/libraries/IRremote
	(cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} \
		${STAGEDIR}${PREFIX}/arduino/libraries/IRremote)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
