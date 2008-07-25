# New ports collection makefile for:	abcl
# Date created:				22 April 2006
# Whom:					Frank Fischer
#
# $FreeBSD$
#

PORTNAME=	abcl
DISTVERSION=	0.0.10
PORTREVISION=	3
CATEGORIES=	lang lisp java
MASTER_SITES=	http://armedbear.org/

MAINTAINER=	fischer.frank@gmail.com
COMMENT=	An implementation of ANSI Common Lisp in Java

SUB_FILES=	abcl
SUB_LIST=	JAVA=${JAVA} ABCL_JAR=${JAVAJARDIR}/abcl.jar

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_LDCONFIG=	yes

do-build: ${WRKSRC}/abcl-src.jar ${WRKSRC}/libabcl.so

do-install:
	@${INSTALL_SCRIPT} -v ${WRKDIR}/abcl ${PREFIX}/bin
	@${INSTALL_DATA} -v ${WRKSRC}/abcl.jar ${JAVAJARDIR}
	@${INSTALL_DATA} -v ${WRKSRC}/abcl-src.jar ${JAVAJARDIR}
	@${INSTALL_DATA} -v ${WRKSRC}/libabcl.so ${LOCALBASE}/lib

.include <bsd.port.pre.mk>

${WRKSRC}/libabcl.so:
	cd ${WRKSRC}/src && \
	${JAVAH} -o org/armedbear/lisp/native.h org.armedbear.lisp.Native && \
	${CC} -shared -o ../libabcl.so -O -D_REENTRANT -fpic -I${JAVA_HOME}/include \-I${JAVA_HOME}/include/freebsd org/armedbear/lisp/native.c
${WRKSRC}/abcl-src.jar: ${WRKSRC}/abcl.jar
	cd ${WRKSRC}/src && \
	${JAR} cmf manifest-abcl ../abcl-src.jar org/armedbear/lisp/*.java && \
	${JAR} uf ../abcl-src.jar org/armedbear/lisp/java/awt/*.java && \
	${JAR} uf ../abcl-src.jar org/armedbear/lisp/LICENSE && \
	${JAR} uf ../abcl-src.jar org/armedbear/lisp/*.lisp

${WRKSRC}/abcl.jar: ${WRKSRC}/src/org/armedbear/lisp/describe-1.cls
	cd ${WRKSRC}/src && \
	${JAR} cmf manifest-abcl ../abcl.jar org/armedbear/lisp/*.class && \
	${JAR} uf ../abcl.jar org/armedbear/lisp/java/awt/*.class && \
	${JAR} uf ../abcl.jar org/armedbear/lisp/LICENSE && \
	${JAR} uf ../abcl.jar org/armedbear/lisp/*.lisp && \
	${JAR} uf ../abcl.jar org/armedbear/lisp/*.abcl && \
	${FIND} . -name '*.cls' | ${XARGS} ${JAR} uf ../abcl.jar

${WRKSRC}/src/org/armedbear/lisp/describe-1.cls: ${WRKSRC}/src/org/armedbear/lisp/Main.class
	cd ${WRKSRC} && \
	${JAVA} -classpath ./src org.armedbear.lisp.Main --eval "(compile-system :zip nil :quit t)"

${WRKSRC}/src/org/armedbear/lisp/Main.class:
	cd ${WRKSRC} && \
	${JAVAC} -verbose -classpath ./src ${WRKSRC}/src/org/armedbear/lisp/*.java && \
	${JAVAC} -verbose -classpath ./src ${WRKSRC}/src/org/armedbear/lisp/java/awt/*.java

delete-build-artifacts:
	${FIND} ${WRKSRC} -name "*.class" -delete
	${FIND} ${WRKSRC} -name "*.abcl" -delete
	${FIND} ${WRKSRC} -name "*.cls" -delete
	${FIND} ${WRKSRC} -name "native.h" -delete
	${FIND} ${WRKSRC} -name "libabcl.so" -delete
	${FIND} ${WRKSRC} -name "build" -delete
list-build-artifacts:
	${FIND} ${WRKSRC} -name "*.class" -print
	${FIND} ${WRKSRC} -name "*.abcl" -print
	${FIND} ${WRKSRC} -name "*.cls" -print
	${FIND} ${WRKSRC} -name "native.h" -print
	${FIND} ${WRKSRC} -name "libabcl.so" -print
	${FIND} ${WRKSRC} -name "build" -print

.include <bsd.port.post.mk>
