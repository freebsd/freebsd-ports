# New ports collection makefile for:	jsap
# Date created:				2005-01-16
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jsap
DISTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:U}-${DISTVERSION}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java package to parse command-line arguments

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	ch01.html ch01s02.html ch02.html ch03.html ch03s02.html \
		ch03s03.html ch03s04.html ch03s05.html ch03s06.html \
		ch03s07.html ch03s08.html ch03s09.html ch04.html ch04s02.html \
		ch04s03.html ch04s04.html ch04s05.html ch05.html ch06.html \
		ch07.html ch08.html ch09.html ch10.html ch11.html ch12.html \
		ch13.html ch14.html ch15.html ch16.html index.html javadoc \
		manual.css pr01.html
.endif
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${DISTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/doc/ \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
