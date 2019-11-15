# $FreeBSD$

PORTNAME=	arduino-tools
PORTVERSION=	1.8.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	# Mostly metaport - installs files, no build
DISTFILES=	#
EXTRACT_ONLY=	#

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Brings together all of the tool dependencies used for Arduino 1.6+

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	arduino-avrdude:devel/arduino-avrdude \
		bossac:devel/bossa \
		avr-as:devel/binutils@avr \
		avr-gcc:devel/avr-gcc \
		${LOCALBASE}/avr/include/avr/io.h:devel/avr-libc \
		gcc-arm-embedded>0:devel/gcc-arm-embedded \
		${LOCALBASE}/arduino/tools-builder/ctags/${CTAGS_VERS}/ctags:devel/arduino-ctags \
		arduino-core>=0:devel/arduino-core \
		arduinoOTA:devel/arduinoOTA \
		openocd:devel/openocd

NO_BUILD=	yes
NO_ARCH=	yes

ARMGCC_VERS=	4.9.2
AVRDUDE_VERS=	6.3.0-arduino9
AVRGCC_VERS=	4.9.2-atmel3.5.4-arduino2
BOSSAC_VERS=	1.7.0
CMSIS_VERS=	${PORTVERSION}
CTAGS_VERS=	5.8-arduino11
OCD_VERS=	0.9.0-arduino5-static
OTA_VERS=	1.1.1

PLIST_SUB+=	ARMGCC_VERS=${ARMGCC_VERS} \
		AVRDUDE_VERS=${AVRDUDE_VERS} \
		AVRGCC_VERS=${AVRGCC_VERS} \
		BOSSAC_VERS=${BOSSAC_VERS} \
		CMSIS_VERS=${CMSIS_VERS} \
		OCD_VERS=${OCD_VERS} \
		OTA_VERS=${OTA_VERS}

_STD_TOOLS_=	arduinoOTA:${OTA_VERS} \
		avr-gcc:${AVRGCC_VERS} \
		avrdude:${AVRDUDE_VERS} \
		bossac:${BOSSAC_VERS} \
		openocd:${OCD_VERS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/arduino/tools-builder/CMSIS/${CMSIS_VERS}
	${MKDIR} ${STAGEDIR}${PREFIX}/arduino/tools-builder/arm-none-eabi-gcc/${ARMGCC_VERS}
	${LN} -s ../../../hardware/arduino/sam/system/CMSIS/CMSIS ${STAGEDIR}${PREFIX}/arduino/tools-builder/CMSIS/${CMSIS_VERS}/CMSIS
	${LN} -s ../../../hardware/arduino/sam/system/CMSIS/Device ${STAGEDIR}${PREFIX}/arduino/tools-builder/CMSIS/${CMSIS_VERS}/Device
	${LN} -s ../../../../gcc-arm-embedded/bin ${STAGEDIR}${PREFIX}/arduino/tools-builder/arm-none-eabi-gcc/${ARMGCC_VERS}/bin
	${LN} -s ../../../../etc ${STAGEDIR}${PREFIX}/arduino/tools-builder/arm-none-eabi-gcc/${ARMGCC_VERS}/etc
.for _tool in ${_STD_TOOLS_}
	${MKDIR} ${STAGEDIR}${PREFIX}/arduino/tools-builder/${_tool:C/:.*//}/${_tool:C/.*://}
	${LN} -s ../../../../bin ${STAGEDIR}${PREFIX}/arduino/tools-builder/${_tool:C/:.*//}/${_tool:C/.*://}/bin
	${LN} -s ../../../../etc ${STAGEDIR}${PREFIX}/arduino/tools-builder/${_tool:C/:.*//}/${_tool:C/.*://}/etc
.endfor

.include <bsd.port.mk>
