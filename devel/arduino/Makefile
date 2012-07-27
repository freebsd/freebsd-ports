# New ports collection makefile for:	arduino
# Date created:				10 Feb 2010
# Whom:					Warren Block <wblock@wonkity.com>
# $FreeBSD$

PORTNAME=	arduino
PORTVERSION=	1.0.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel java lang
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	wblock@freebsd.org
COMMENT=	Open-source electronics prototyping platform

RUN_DEPENDS=	${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar:${PORTSDIR}/comms/rxtx \
		${LOCALBASE}/bin/avrdude:${PORTSDIR}/devel/avrdude \
		${LOCALBASE}/avr/include/avr/io.h:${PORTSDIR}/devel/avr-libc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_JAVA=	1.6+
NO_BUILD=	yes
USE_LDCONFIG=	${PREFIX}/arduino/lib

SUB_FILES=	arduino pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

REINPLACE_ARGS=	-i ""

DESKTOP_ENTRIES=	"Arduino" "Arduino IDE" \
			${PREFIX}/${PORTNAME}/logo.png \
			"arduino" "Development;IDE;" "false"

OPTIONS_DEFINE+=	DOCS EXAMPLES
DOCS_DESC=	 	Install the reference documents

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
PLIST_SUB+=	REFDOCS="@comment "
.else
PLIST_SUB+=	REFDOCS=""
.endif

.if empty(PORT_OPTIONS:MEXAMPLES)
PLIST_SUB+=	EXAMPLES="@comment "
.else
PLIST_SUB+=	EXAMPLES=""
.endif

post-patch:
	@${RM} ${WRKSRC}/hardware/arduino/bootloaders/atmega8/ATmegaBOOT.c.orig
	@${RM} -rf ${WRKSRC}/hardware/tools/
	@${MKDIR} ${WRKSRC}/hardware/tools/avr/
	@${LN} -s ${PREFIX}/bin ${WRKSRC}/hardware/tools/avr/bin
	@${LN} -s ${PREFIX}/etc ${WRKSRC}/hardware/tools/avr/etc

	@${RM} ${WRKSRC}/lib/RXTXcomm.jar
	@${LN} -s ${JAVA_HOME}/lib/ext/RXTXcomm.jar ${WRKSRC}/lib/RXTXcomm.jar

	@${MV} ${WRKSRC}/reference/img/logo.png ${WRKSRC}/
	@${RM} -rf ${WRKSRC}/reference/img/

.if empty(PORT_OPTIONS:MDOCS)
	@${RM} -rf ${WRKSRC}/reference
.endif
.if empty(PORT_OPTIONS:MEXAMPLES)
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
