# New ports collection makefile for:	jlex
# Date created:		1 June 1999
# Whom:			jake@checker.org
#
# $FreeBSD$
#

PORTNAME=	jlex
PORTVERSION=	1.2.3
CATEGORIES=	java
MASTER_SITES=	http://www.cs.princeton.edu/~appel/modern/java/JLex/Archive/1.2.3/
DISTNAME=	Main
EXTRACT_SUFX=	.java
EXTRACT_ONLY=	#

MAINTAINER=	jake@checker.org

BUILD_DEPENDS=	${LOCALBASE}/${JAVADIR}/bin/java:${PORTSDIR}/java/jdk11

JAVADIR=	jdk1.1.8
JAVAC=		${LOCALBASE}/${JAVADIR}/bin/javac

NO_WRKSUBDIR=	yes

PLIST_SUB=	JAVADIR=${JAVADIR}

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/Main.java ${WRKDIR}

do-build:
	@${JAVAC} ${WRKDIR}/Main.java

do-install:
	@${MKDIR} ${PREFIX}/${JAVADIR}/jlex
	@${INSTALL_SCRIPT} ${WRKDIR}/*.class ${PREFIX}/${JAVADIR}/jlex

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e s:/usr/local:${PREFIX}: -e s:jdk1.1.8:${JAVADIR}:

.include <bsd.port.mk>
