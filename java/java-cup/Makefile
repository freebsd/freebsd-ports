# New ports collection makefile for:	cup
# Date created:		10 May 1998
# Whom:			nordwick@xcf.berkeley.edu
#
# $FreeBSD$
#

PORTNAME=	java_cup
PORTVERSION=	10.k
CATEGORIES=	java
MASTER_SITES=	http://www.cs.princeton.edu/~appel/modern/java/CUP/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S|.||}

MAINTAINER=	nordwick@xcf.berkeley.edu
COMMENT=	An LALR parser generator in Java

USE_JAVA=	1.1+
NEED_JAVAC=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB=	JAVAJARDIR=${JAVAJARDIR:S|^${PREFIX}/||} PORTNAME=${PORTNAME}

do-build:
	${SETENV} CLASSPATH=${WRKSRC} ${JAVAC} ${WRKSRC}/java_cup/*.java \
		${WRKSRC}/java_cup/runtime/*.java
	cd ${WRKSRC} && \
		${JAR} cf ${PORTNAME}.jar java_cup/*.class \
		java_cup/runtime/*.class

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.jar ${JAVAJARDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cup_logo.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${ECHO_MSG} "Documentation installed in ${DOCSDIR}"
	@${ECHO_MSG} "   manual.html --  How to build a grammar."
	@${ECHO_MSG} "   README -- How to get it working."
	@${ECHO_MSG} "   LICENSE -- How not to get sued."
.endif

.include <bsd.port.mk>
