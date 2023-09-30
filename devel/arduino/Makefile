PORTNAME=	arduino
PORTVERSION=	1.0.6
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	devel java lang
MASTER_SITES=	https://arduino.cc/download.php?f=/
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux32

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Open-source electronics prototyping platform
WWW=		https://www.arduino.cc/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

# Confirmed for ARCHS below. Arm and PowerPC untested. (Feedback welcome)
ONLY_FOR_ARCHS=	amd64 i386

RUN_DEPENDS=	${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar:comms/rxtx \
		${LOCALBASE}/bin/avrdude:devel/avrdude \
		${LOCALBASE}/avr/include/avr/io.h:devel/avr-libc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		dos2unix tar:tgz kmod
DOS2UNIX_REGEX=	.*(\.(c|cpp|h|hex|txt)|Makefile|makefile)

USE_JAVA=	yes
JAVA_OS=	native
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

CONFLICTS_INSTALL=	arduino18

NO_BUILD=	yes
USE_LDCONFIG=	${PREFIX}/arduino/lib

PLIST_SUB=	ARCH=${ARCH:S|i386||:S|amd64|64|}

SUB_FILES=	arduino pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} LINUXBASE=${PREFIX}

REINPLACE_ARGS=	-i ""

DESKTOP_ENTRIES=	"Arduino" "Arduino IDE" \
			${PREFIX}/${PORTNAME}/logo.png \
			"arduino" "Development;IDE;" false

OPTIONS_DEFINE=		ATMEGA644P DOCS EXAMPLES UARDUNO
OPTIONS_SUB=
ATMEGA644P_DESC=	ATmega644p patches
DOCS_DESC=		Install the reference documents
UARDUNO_DESC=		Kernel module for Arduino Uno USB interface

INSLIST=	arduino hardware lib libraries logo.png revisions.txt tools

# Add serial drivers for those who are new to this.
UARDUNO_RUN_DEPENDS+=	${KMODDIR}/uarduno.ko:comms/uarduno

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATMEGA644P}
EXTRA_PATCHES+=	\
	${FILESDIR}/extrapatch-hardware-arduino-boards.txt \
	${FILESDIR}/extrapatch-hardware-arduino-cores-arduino-WInterrupts.c \
	${FILESDIR}/extrapatch-hardware-arduino-variants-atmega644p-pins_arduino.h
.endif

.if ! empty(PORT_OPTIONS:MDOCS)
INSLIST+=	reference
.endif

FIND_EXCLUDES=	! -name *.orig

.if empty(PORT_OPTIONS:MEXAMPLES)
FIND_EXCLUDES+=	! -path */examples ! -path */examples/*
.else
INSLIST+=	examples
.endif

FIND_EXPR=	"${FIND_EXCLUDES} -prune"

.if ${PORT_OPTIONS:MATMEGA644P}
pre-patch:
	@${MKDIR} ${WRKSRC}/hardware/arduino/variants/atmega644p
.endif

post-patch:
	@${RM} -r ${WRKSRC}/hardware/tools/
	@${MKDIR} ${WRKSRC}/hardware/tools/avr/
	@${LN} -s ${PREFIX}/bin ${WRKSRC}/hardware/tools/avr/bin
	@${LN} -s ${PREFIX}/etc ${WRKSRC}/hardware/tools/avr/etc

	# Remove broken jar, and Linux C6 based libraries.
	@${RM} ${WRKSRC}/lib/RXTXcomm.jar

	# This port relys on comms/RXTX working without Linux C6 compatibility.
	@${RM} ${WRKSRC}/lib/librxtxSerial.so
	@${RM} ${WRKSRC}/lib/librxtxSerial64.so

	# Map the RXTX port for our use
	@${LN} -s ${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar ${WRKSRC}/lib/RXTXcomm.jar

# Add in links to the libraries compiled in RXTX for the above jar to use based on architecture.
.if ${ARCH} == i386
	@${LN} -s ${JAVA_HOME}/jre/lib/i386/librxtxSerial.so ${WRKSRC}/lib/librxtxSerial.so
.endif

.if ${ARCH} == amd64
	@${LN} -s ${JAVA_HOME}/jre/lib/amd64/librxtxSerial.so ${WRKSRC}/lib/librxtxSerial64.so
.endif

	@${MV} ${WRKSRC}/reference/img/logo.png ${WRKSRC}/
	@${RM} -r ${WRKSRC}/reference/img/

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "${INSLIST}" ${STAGEDIR}${PREFIX}/${PORTNAME} ${FIND_EXPR})
	${INSTALL_SCRIPT} ${WRKDIR}/arduino ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
