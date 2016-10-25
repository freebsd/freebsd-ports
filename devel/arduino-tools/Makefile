# $FreeBSD$

PORTNAME=	arduino-tools
PORTVERSION=	1.6.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# Mostly metaport - installs files, no build
DISTFILES=	#
EXTRACT_ONLY=	#

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Brings together all of the tool dependencies used for Arduino 1.6

LICENSE=	NONE

RUN_DEPENDS=	avrdude:devel/avrdude \
		bossac:devel/bossa \
		avr-as:devel/avr-binutils \
		avr-gcc:devel/avr-gcc \
		${LOCALBASE}/avr/include/avr/io.h:devel/avr-libc \
		arm-none-eabi-gcc:devel/arm-none-eabi-gcc \
		${LOCALBASE}/arduino/tools-builder/ctags/${CTAGS_VERS}/ctags:devel/arduino-ctags \
		arm-none-eabi-newlib>=0:devel/arm-none-eabi-newlib \
		arduino-core>=0:devel/arduino-core

NO_BUILD=	yes
NO_ARCH=	yes

ARMGCC_VERS=	4.9.2
AVRDUDE_VERS=	6.3.0-arduino6
AVRGCC_VERS=	4.9.2-atmel3.5.3-arduino2
BOSSAC_VERS=	1.7.0
CMSIS_VERS=	${PORTVERSION}
CTAGS_VERS=	5.8-arduino10

PLIST_SUB+=	ARMGCC_VERS=${ARMGCC_VERS} \
		AVRDUDE_VERS=${AVRDUDE_VERS} \
		AVRGCC_VERS=${AVRGCC_VERS} \
		BOSSAC_VERS=${BOSSAC_VERS} \
		CMSIS_VERS=${CMSIS_VERS}

_STD_TOOLS_=	arm-none-eabi-gcc:${ARMGCC_VERS} \
		avr-gcc:${AVRGCC_VERS} \
		avrdude:${AVRDUDE_VERS} \
		bossac:${BOSSAC_VERS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/arduino/tools-builder/CMSIS/${CMSIS_VERS}
	${LN} -s ../../../hardware/arduino/sam/system/CMSIS/CMSIS ${STAGEDIR}${PREFIX}/arduino/tools-builder/CMSIS/${CMSIS_VERS}/CMSIS
	${LN} -s ../../../hardware/arduino/sam/system/CMSIS/Device ${STAGEDIR}${PREFIX}/arduino/tools-builder/CMSIS/${CMSIS_VERS}/Device
.for _tool in ${_STD_TOOLS_}
	${MKDIR} ${STAGEDIR}${PREFIX}/arduino/tools-builder/${_tool:C/:.*//}/${_tool:C/.*://}
	${LN} -s ../../../../bin ${STAGEDIR}${PREFIX}/arduino/tools-builder/${_tool:C/:.*//}/${_tool:C/.*://}/bin
	${LN} -s ../../../../etc ${STAGEDIR}${PREFIX}/arduino/tools-builder/${_tool:C/:.*//}/${_tool:C/.*://}/etc
.endfor

.include <bsd.port.mk>
