# New ports collection makefile for:	jlex
# Date created:		1 June 1999
# Whom:			jake@checker.org
#
# $FreeBSD$
#

PORTNAME=	jlex
PORTVERSION=	1.2.6
CATEGORIES=	java
MASTER_SITES=	http://www.cs.princeton.edu/~appel/modern/java/JLex/Archive/1.2.6/
DISTNAME=	Main
EXTRACT_SUFX=	.java
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lexical analyzer generator, written for Java, in Java

PLIST_FILES=	%%JAVAJARDIR%%/jlex.jar
USE_JAVA=	1.1+
NEED_JAVAC=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB=	JAVAJARDIR=${JAVAJARDIR:S|^${PREFIX}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/Main.java ${WRKDIR}

do-build:
	@cd ${WRKDIR} && \
		${JAVAC} -d . Main.java && \
		${JAR} cf ${PORTNAME}.jar JLex/*.class

do-install:
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.jar ${JAVAJARDIR}
	@${SED} s:%%JAVAJARDIR%%:${JAVAJARDIR}: < ${PKGDIR}/pkg-message \
		> ${PKGMESSAGE}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
