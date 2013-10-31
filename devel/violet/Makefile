# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	violet
PORTVERSION=	0.21.1
PORTREVISION=	1
CATEGORIES=	devel editors java
MASTER_SITES=	SF/${PORTNAME}/violetumleditor/${PORTVERSION}
DISTNAME=	com.horstmann.violet-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	graudeejs@gmail.com
COMMENT=	Violet is a easy to learn and use UML editor

USE_JAVA=	yes
JAVA_VERSION=	1.6+

LICENSE=	GPLv2

NO_BUILD=	YES

PLIST_FILES=	%%JAVASHAREDIR%%/${PORTNAME}/com.horstmann.violet.jar bin/${PORTNAME}
PLIST_DIRS=	%%JAVASHAREDIR%%/${PORTNAME}

NO_STAGE=	yes
pre-install:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/violet.sh
	${ECHO} "${PREFIX}/bin/java -jar ${JAVASHAREDIR}/${PORTNAME}/com.horstmann.violet.jar" >> ${WRKDIR}/violet.sh

do-install:
	${MKDIR} ${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/com.horstmann.violet-${PORTVERSION}.jar ${JAVASHAREDIR}/${PORTNAME}/com.horstmann.violet.jar
	${INSTALL_SCRIPT} ${WRKDIR}/violet.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
