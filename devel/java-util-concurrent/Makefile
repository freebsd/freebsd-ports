# New ports collection makefile for:	java-util-concurrent
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	util-concurrent
PORTVERSION=	1.3.4
CATEGORIES=	devel java
MASTER_SITES=	http://gee.cs.oswego.edu/dl/classes/EDU/oswego/cs/dl/current/
PKGNAMEPREFIX=	java-
DISTNAME=	concurrent

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Utility classes for concurrent Java programming

USE_JAVA=	yes
JAVA_VERSION=	1.2+

USE_ANT=	yes
ALL_TARGET=	dist
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
PORTDOCS=	apidocs index.html
.endif

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/${DISTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/docs \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/apidocs/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/apidocs/{} \;
	@${INSTALL_DATA} ${WRKSRC}/intro.html ${DOCSDIR}/index.html
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
