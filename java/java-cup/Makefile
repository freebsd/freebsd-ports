# New ports collection makefile for:	cup
# Date created:		10 May 1998
# Whom:			nordwick@xcf.berkeley.edu
#
# $FreeBSD$
#

PORTNAME=	java_cup
PORTVERSION=	10.g
CATEGORIES=	java
MASTER_SITES=	http://www.cs.princeton.edu/~appel/modern/java/CUP/
DISTNAME=	java_cup_v10g

MAINTAINER=	nordwick@xcf.berkeley.edu

BUILD_DEPENDS=	${JAVADIR}/bin/javac:${PORTSDIR}/java/jdk11
RUN_DEPENDS=	${JAVADIR}/bin/java:${PORTSDIR}/java/jdk11

JAVASUBDIR=	jdk1.1.8
JAVADIR=	${PREFIX}/${JAVASUBDIR}
JAVALIBDIR=	${JAVADIR}/lib

NO_WRKSUBDIR=	yes

PLIST_SUB=	JAVASUBDIR=${JAVASUBDIR}

do-build:
	for JSRC in ${WRKSRC}/java_cup/*.java ${WRKSRC}/java_cup/runtime/*.java; \
	do CLASSPATH=${WRKSRC} ${PREFIX}/${JAVASUBDIR}/bin/javac $$JSRC; done

do-install:
	${MKDIR} ${JAVALIBDIR}/java_cup
	${MKDIR} ${JAVALIBDIR}/java_cup/runtime
	${CP} ${WRKSRC}/java_cup/*.class ${JAVALIBDIR}/java_cup
	${CP} ${WRKSRC}/java_cup/runtime/*.class ${JAVALIBDIR}/java_cup/runtime

post-install:
	${MKDIR} ${JAVADIR}/cup
	${INSTALL_MAN} ${WRKSRC}/manual.html ${JAVADIR}/cup
	${INSTALL_MAN} ${WRKSRC}/README ${JAVADIR}/cup
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${JAVADIR}/cup
	@${ECHO_MSG} "Documentation installed in ${JAVADIR}/cup"
	@${ECHO_MSG} "   manual.html --  How to build a grammer."
	@${ECHO_MSG} "   README -- How to get it working."
	@${ECHO_MSG} "   LICENSE -- How not to get sued."

.include <bsd.port.mk>
