# Ports collection makefile for:    Castor
# Date created:         2005/05/12
# Whom:                 Adam VanderHook <acidos@bandwidth-junkies.net>
#
# $FreeBSD$
#

PORTNAME=	castor
PORTVERSION=	0.9.7
CATEGORIES=	java devel
MASTER_SITES=	http://dist.codehaus.org/castor/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	acidos@bandwidth-junkies.net
COMMENT=	Data binding for XML (JAXB) and SQL database (JDO)

USE_JAVA=	yes
JAVA_VERSION=	1.4
USE_ANT=	yes
USE_JIKES=	no

ALL_TARGET=	jar

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src

JAVALIBNAME=	${PORTNAME}-${PORTVERSION}
JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${JAVALIBNAME}.jar ${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
