# Ports collection makefile for:	charva
# Date created:			12 December 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	charva
PORTVERSION=	1.1.4
PORTREVISION=	4
CATEGORIES=	devel java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java Windowing Toolkit for Text Terminals

BUILD_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
RUN_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ANT=	yes
ALL_TARGET=	clean makeDLL dist

.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

PLIST_SUB=	JAVA_HOME=${JAVA_HOME:S/${PREFIX}\///}
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		%%JAVA_HOME%%/jre/lib/${MACHINE_ARCH}/libTerminal.so

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/java/dist/lib/${PORTNAME}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JNI library as ${JAVA_HOME}/jre/lib/${MACHINE_ARCH}/libTerminal.so..."
	@${INSTALL_PROGRAM} ${WRKSRC}/c/lib/libTerminal.so \
		${JAVA_HOME}/jre/lib/${MACHINE_ARCH}/libTerminal.so
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} * \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
