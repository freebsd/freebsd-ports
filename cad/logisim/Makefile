PORTNAME=	logisim
PORTVERSION=	2.7.1
CATEGORIES=	cad education java
MASTER_SITES=	SF/circuit/2.7.x/2.7.1/
DISTNAME=	${PORTNAME}-generic-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	javad.kouhi@gmail.com
COMMENT=	Educational tool for designing and simulating logic circuits

LICENSE=	GPLv2

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_RUN=	yes

PLIST_FILES=	${DATADIR_REL}/${PORTNAME}-generic-${PORTVERSION}${EXTRACT_SUFX} \
		bin/${PORTNAME}

DESKTOP_ENTRIES="Logisim" "${COMMENT}" "" "${PORTNAME}" "" false

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}
	${ECHO_CMD} -e "#!/bin/sh\nexec ${JAVA} -jar ${DATADIR}/${DISTNAME}${EXTRACT_SUFX}" > ${WRKSRC}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
