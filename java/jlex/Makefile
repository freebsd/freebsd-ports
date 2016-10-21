# Created by: jake@checker.org
# $FreeBSD$

PORTNAME=	jlex
PORTVERSION=	1.2.6
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	http://www.cs.princeton.edu/~appel/modern/java/JLex/Archive/1.2.6/
DISTNAME=	Main
EXTRACT_SUFX=	.java
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lexical analyzer generator, written for Java, in Java

PLIST_FILES=	%%JAVAJARDIR%%/jlex.jar bin/jlex
USE_JAVA=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	jlex.sh pkg-message
SUB_LIST=	JAVAJARDIR=${JAVAJARDIR}

do-extract:
	@${RM} -r ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/Main.java ${WRKDIR}

do-build:
	@cd ${WRKDIR} && \
		${JAVAC} -d . Main.java && \
		${JAR} cf ${PORTNAME}.jar JLex/*.class

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jlex.sh ${STAGEDIR}${PREFIX}/bin/jlex

.include <bsd.port.mk>
