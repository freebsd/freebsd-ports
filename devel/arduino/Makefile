# New ports collection makefile for:	arduino
# Date created:				10 Feb 2010
# Whom:					Warren Block <wblock@wonkity.com>
# $FreeBSD$

PORTNAME=	arduino
PORTVERSION=	0019
CATEGORIES=	devel java lang
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	wblock@wonkity.com
COMMENT=	Open-source electronics prototyping platform

RUN_DEPENDS=	${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar:${PORTSDIR}/comms/rxtx \
		${LOCALBASE}/bin/avrdude:${PORTSDIR}/devel/avrdude \
		${LOCALBASE}/avr/include/avr/io.h:${PORTSDIR}/devel/avr-libc

USE_JAVA=	1.6+
NO_BUILD=	yes

SUB_FILES=	arduino pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

DESKTOP_ENTRIES=	"Arduino" "Arduino IDE" "computer" "arduino" "Development;IDE;" "true"

.if !defined(NOPORTDOCS)
OPTIONS+=	REFDOCS "Install the reference documents" on
.endif
.if !defined(NOPORTEXAMPLES)
OPTIONS+=	EXAMPLES "Install the example code" on
.endif

.include <bsd.port.options.mk>

.if defined(WITHOUT_REFDOCS) || defined(NOPORTDOCS)
WITHOUT_REFDOCS=	true
.undef WITH_REFDOCS
PLIST_SUB+=	REFDOCS="@comment "
.else
PLIST_SUB+=	REFDOCS=""
.endif

.if defined(WITHOUT_EXAMPLES) || defined(NOPORTEXAMPLES)
WITHOUT_EXAMPLES=	true
.undef WITH_EXAMPLES
PLIST_SUB+=	EXAMPLES="@comment "
.else
PLIST_SUB+=	EXAMPLES=""
.endif

post-extract:
	@${RM} ${WRKSRC}/hardware/tools/avrdude
	@${RM} ${WRKSRC}/hardware/tools/avrdude.conf
	@${MKDIR} ${WRKSRC}/hardware/tools/avr
	@${LN} -s ${PREFIX}/bin ${WRKSRC}/hardware/tools/avr/bin
	@${LN} -s ${PREFIX}/etc ${WRKSRC}/hardware/tools/avr/etc

	@${RM} ${WRKSRC}/lib/RXTXcomm.jar
	@${LN} -s ${JAVA_HOME}/lib/ext/RXTXcomm.jar ${WRKSRC}/lib/RXTXcomm.jar

	@${RM} ${WRKSRC}/lib/librxtxSerial.so
	@${LN} -s ${JAVA_HOME}/lib/${ARCH}/librxtxSerial.so ${WRKSRC}/lib/

	@${REINPLACE_CMD} 's|stk500|arduino|g' ${WRKSRC}/hardware/arduino/boards.txt
	@${RM} ${WRKSRC}/hardware/arduino/boards.txt.bak

post-patch:
.if defined(WITHOUT_REFDOCS)
	@${RM} -rf ${WRKSRC}/reference
.endif
.if defined(WITHOUT_EXAMPLES)
	@${RM} -rf ${WRKSRC}/examples
	@${RM} -rf ${WRKSRC}/libraries/*/examples
.endif

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -Rp ${WRKSRC}/* ${PREFIX}/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKDIR}/arduino ${PREFIX}/bin/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
