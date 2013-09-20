# Created by: loader <loader@freebsdmall.com>
# $FreeBSD$

PORTNAME=	jutils
PORTVERSION=	20070610.r26
CATEGORIES=	games java
MASTER_SITES=	LOCAL/loader

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common utilities for Java Game Technology Group projects

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_VENDOR=	openjdk
USE_ANT=	YES

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}/${PORTNAME}.jar
PLIST_DIRS=	%%JAVAJARDIR%%/${PORTNAME}

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Install JAR files in ${JAVAJARDIR}/${PORTNAME}/ ..."
	@${MKDIR} ${JAVAJARDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/bin/${PORTNAME}.jar \
		${JAVAJARDIR}/${PORTNAME}/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
