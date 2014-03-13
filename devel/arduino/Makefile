# Created by: Warren Block <wblock@wonkity.com>
# $FreeBSD$

PORTNAME=	arduino
PORTVERSION=	1.0.5
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel java lang
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux32
EXTRACT_SUFX=	.tgz

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Open-source electronics prototyping platform

RUN_DEPENDS=	${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar:${PORTSDIR}/comms/rxtx \
		${LOCALBASE}/bin/avrdude:${PORTSDIR}/devel/avrdude \
		${LOCALBASE}/avr/include/avr/io.h:${PORTSDIR}/devel/avr-libc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		dos2unix
DOS2UNIX_REGEX=	.*\(\.\(c|cpp|h|hex|html|ino|lst|txt\)|Makefile\)

USE_JAVA=	1.6+
NO_BUILD=	yes
USE_LDCONFIG=	${PREFIX}/arduino/lib

SUB_FILES=	arduino pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} LINUXBASE=${LINUXBASE}

REINPLACE_ARGS=	-i ""

DESKTOP_ENTRIES=	"Arduino" "Arduino IDE" \
			${PREFIX}/${PORTNAME}/logo.png \
			"arduino" "Development;IDE;" "false"

OPTIONS_DEFINE=		ATMEGA644P DOCS EXAMPLES
ATMEGA644P_DESC=	ATmega644p patches
DOCS_DESC=		Install the reference documents

INSLIST=	arduino hardware lib libraries logo.png revisions.txt tools

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATMEGA644P}
EXTRA_PATCHES+=	\
	${FILESDIR}/extrapatch-hardware-arduino-boards.txt \
	${FILESDIR}/extrapatch-hardware-arduino-cores-arduino-WInterrupts.c \
	${FILESDIR}/extrapatch-hardware-arduino-variants-atmega644p-pins_arduino.h
.endif

.if empty(PORT_OPTIONS:MDOCS)
PLIST_SUB+=	REFDOCS="@comment "
.else
PLIST_SUB+=	REFDOCS=""
INSLIST+=	reference
.endif

FIND_EXCLUDES=	! -name *.orig

.if empty(PORT_OPTIONS:MEXAMPLES)
PLIST_SUB+=	EXAMPLES="@comment "
FIND_EXCLUDES+=	! -path */examples ! -path */examples/*
.else
PLIST_SUB+=	EXAMPLES=""
INSLIST+=	examples
.endif

FIND_EXPR=	"${FIND_EXCLUDES} -prune"

.if ${PORT_OPTIONS:MATMEGA644P}
PLIST_SUB+=	ATMEGA644P=""
.else
PLIST_SUB+=	ATMEGA644P="@comment "
.endif

.if ${PORT_OPTIONS:MATMEGA644P}
pre-patch:
	@${MKDIR} ${WRKSRC}/hardware/arduino/variants/atmega644p
.endif

post-patch:
	@${RM} -rf ${WRKSRC}/hardware/tools/
	@${MKDIR} ${WRKSRC}/hardware/tools/avr/
	@${LN} -s ${PREFIX}/bin ${WRKSRC}/hardware/tools/avr/bin
	@${LN} -s ${PREFIX}/etc ${WRKSRC}/hardware/tools/avr/etc

	@${RM} ${WRKSRC}/lib/RXTXcomm.jar
	@${LN} -s ${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar ${WRKSRC}/lib/RXTXcomm.jar

	@${MV} ${WRKSRC}/reference/img/logo.png ${WRKSRC}/
	@${RM} -rf ${WRKSRC}/reference/img/

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "${INSLIST}" ${STAGEDIR}${PREFIX}/${PORTNAME} ${FIND_EXPR})
	${CHMOD} +x ${STAGEDIR}${PREFIX}/${PORTNAME}/arduino
	${INSTALL_SCRIPT} ${WRKDIR}/arduino ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
