# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	ditaa
DISTVERSION=	0_9
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Convert ASCII art diagrams into proper bitmap graphics

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

LICENSE=	GPLv2

NO_BUILD=	YES

PLIST_FILES=	%%JAVASHAREDIR%%/${PORTNAME}/${PORTNAME}.jar bin/${PORTNAME}
PLIST_DIRS=	%%JAVASHAREDIR%%/${PORTNAME}

NO_STAGE=	yes
pre-install:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/${PORTNAME}.sh
	${ECHO} "${PREFIX}/bin/java -jar ${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar \$$*" >> ${WRKDIR}/${PORTNAME}.sh

do-install:
	${MKDIR} ${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}${DISTVERSION}.jar ${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
