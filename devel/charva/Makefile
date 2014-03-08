# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	charva
PORTVERSION=	1.1.4
PORTREVISION=	5
CATEGORIES=	devel java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java Windowing Toolkit for Text Terminals

BUILD_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
RUN_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging

OPTIONS_DEFINE=	DOCS

USES=		dos2unix zip
DOS2UNIX_FILES=	c/src/Makefile.freebsd.txt
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	clean makeDLL dist

PLIST_SUB=	JAVA_HOME=${JAVA_HOME:S/${PREFIX}\///}
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		%%JAVA_HOME%%/jre/lib/${MACHINE_ARCH}/libTerminal.so
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/java/dist/lib/${PORTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JNI library as ${JAVA_HOME}/jre/lib/${MACHINE_ARCH}/libTerminal.so..."
	-@${MKDIR} ${STAGEDIR}${JAVA_HOME}/jre/lib/${MACHINE_ARCH}
	@${INSTALL_PROGRAM} ${WRKSRC}/c/lib/libTerminal.so \
		${STAGEDIR}${JAVA_HOME}/jre/lib/${MACHINE_ARCH}/libTerminal.so
	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} * \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
