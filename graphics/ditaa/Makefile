PORTNAME=	ditaa
DISTVERSION=	0.11.0
CATEGORIES=	graphics java
MASTER_SITES=	https://github.com/stathissideris/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-standalone.jar
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert ASCII art diagrams into proper bitmap graphics
WWW=		https://github.com/stathissideris/ditaa

LICENSE=	LGPL3

USES=		zip
USE_JAVA=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/${PORTNAME}-${DISTVERSION}-standalone.jar \
		${DATADIR}/${PORTNAME}.jar \
		bin/${PORTNAME}
pre-install:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/${PORTNAME}
	${ECHO} "exec ${PREFIX}/bin/java -jar ${DATADIR}/${PORTNAME}.jar \"\$$@\"" >> ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${DISTVERSION}-standalone.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}-${DISTVERSION}-standalone.jar
	${LN} -sf ${PORTNAME}-${DISTVERSION}-standalone.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
