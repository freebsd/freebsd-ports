# Created by: Craig Leres <leres@ee.lbl.gov>
# $FreeBSD$

PORTNAME=	arduino-mk
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://mjo.tc/atelier/2009/02/acli/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	leres@ee.lbl.gov
COMMENT=	Build Arduino sketches from the command line

LICENSE=	LGPL21

# gmake is needed to use the port, not to build it
RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		arduino:${PORTSDIR}/devel/arduino
PATCH_DEPENDS=	${LOCALBASE}/arduino/lib/version.txt:${PORTSDIR}/devel/arduino

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

OPTIONS_DEFINE+=	DOCS EXAMPLES

NO_STAGE=	yes
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

ARDUINO_CMD=	${SH} ${FILESDIR}/version.sh ${PREFIX}/arduino/lib/version.txt
OLD_BOARDS_TXT=	/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/boards.txt
NEW_BOARDS_TXT=	${PREFIX}/arduino/hardware/arduino/boards.txt

INSLIST=	AnalogInOutSerial Blink BlinkWithoutDelay Fade HelloWorld \
		WebServer master_reader toneMelody
post-patch:
	@ARDUINO="`$(ARDUINO_CMD)`" && \
	    ${REINPLACE_CMD} -e "s|%%ARDUINO%%|$${ARDUINO}|g" \
	    ${WRKSRC}/arduino-mk/Arduino.mk
	@${REINPLACE_CMD} -e "s|'${OLD_BOARDS_TXT}'|'${NEW_BOARDS_TXT}'|g" \
	    ${WRKSRC}/bin/ard-parse-boards

do-install:
	${MKDIR} ${PREFIX}/${PORTNAME}/bin
	${INSTALL_DATA} ${WRKSRC}/arduino-mk/Arduino.mk ${PREFIX}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ard-parse-boards ${PREFIX}/${PORTNAME}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ard-reset-arduino ${PREFIX}/${PORTNAME}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "${INSLIST}" ${EXAMPLESDIR})
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}
.endif

.include <bsd.port.mk>
