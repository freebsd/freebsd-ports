PORTNAME=	plantuml
DISTVERSION=	1.2025.7
CATEGORIES=	graphics java textproc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Application for swift and straightforward diagram creation
WWW=		https://plantuml.com/

LICENSE=	GPLv3

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar

pre-install:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/${PORTNAME}
	${ECHO} '${PREFIX}/bin/java -jar ${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar $$*' \
		>> ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${DISTVERSION}.jar \
		${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
