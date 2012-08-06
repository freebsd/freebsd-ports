# New ports collection makefile for:	arduino-mk
# Date created:		27 Feb 2011
# Whom:			Craig Leres <leres@ee.lbl.gov>
#
# $FreeBSD$
#

PORTNAME=	arduino-mk
PORTVERSION=	0.8
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

PLIST_FILES=	arduino/lib/Arduino.mk \
		arduino/tools/ard-parse-boards

.if !defined(NOPORTEXAMPLES)
PLIST_FILES+=	${EXAMPLESDIR_REL}/Makefile \
		${EXAMPLESDIR_REL}/blink2.pde
PLIST_DIRS+=	${EXAMPLESDIR_REL}
.endif

.include <bsd.port.pre.mk>

ARDUINO_CMD=	${FILESDIR}/version.sh ${PREFIX}/arduino/lib/version.txt
OLD_BOARDS_TXT=	/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/boards.txt
NEW_BOARDS_TXT=	${PREFIX}/arduino/hardware/arduino/boards.txt

post-patch:
	@ARDUINO="`$(ARDUINO_CMD)`" && \
	    ${REINPLACE_CMD} -e "s|%%ARDUINO%%|$${ARDUINO}|g" \
	    ${WRKSRC}/Arduino.mk
	@${REINPLACE_CMD} -e "s|'${OLD_BOARDS_TXT}'|'${NEW_BOARDS_TXT}'|g" \
	    ${WRKSRC}/ard-parse-boards

do-install:
	${INSTALL_DATA} ${WRKSRC}/Arduino.mk ${PREFIX}/arduino/lib
	${INSTALL_SCRIPT} ${WRKSRC}/ard-parse-boards ${PREFIX}/arduino/tools
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/Makefile ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/blink2.pde ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
