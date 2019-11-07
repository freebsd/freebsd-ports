# Created by: Craig Leres <leres@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arduino-mk
PORTVERSION=	0.10
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.mjoldfield.com/atelier/2009/02/acli/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Build Arduino sketches from the command line

LICENSE=	LGPL21

# gmake is needed to use the port, not to build it
RUN_DEPENDS=	gmake:devel/gmake \
		p5-Device-SerialPort>=0:comms/p5-Device-SerialPort \
		p5-YAML>=0:textproc/p5-YAML \
		arduino:devel/arduino
PATCH_DEPENDS=	${LOCALBASE}/arduino/lib/version.txt:devel/arduino

USES=		shebangfix
SHEBANG_FILES=	bin/ard-parse-boards bin/ard-reset-arduino
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

OPTIONS_DEFINE+=	DOCS EXAMPLES

ARDUINO_CMD=	${SH} ${FILESDIR}/version.sh ${PREFIX}/arduino/lib/version.txt
OLD_BOARDS_TXT=	/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/boards.txt
NEW_BOARDS_TXT=	${PREFIX}/arduino/hardware/arduino/boards.txt

INSLIST=	AnalogInOutSerial Blink BlinkWithoutDelay Fade HelloWorld \
		WebServer master_reader toneMelody
post-patch:
	@ARDUINO="`${ARDUINO_CMD}`" && \
	    ${REINPLACE_CMD} -e "s|%%ARDUINO%%|$${ARDUINO}|g" \
	    ${WRKSRC}/arduino-mk/Arduino.mk
	@${REINPLACE_CMD} -e "s|'${OLD_BOARDS_TXT}'|'${NEW_BOARDS_TXT}'|g" \
	    ${WRKSRC}/bin/ard-parse-boards

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
	${INSTALL_DATA} ${WRKSRC}/arduino-mk/Arduino.mk ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ard-parse-boards ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ard-reset-arduino ${STAGEDIR}${PREFIX}/${PORTNAME}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "${INSLIST}" ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
