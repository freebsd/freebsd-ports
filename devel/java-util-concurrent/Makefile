# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	util-concurrent
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://gee.cs.oswego.edu/dl/classes/EDU/oswego/cs/dl/current/
PKGNAMEPREFIX=	java-
DISTNAME=	concurrent

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility classes for concurrent Java programming

USE_JAVA=	yes
JAVA_VERSION=	1.6+

USE_ANT=	yes
ALL_TARGET=	dist

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	apidocs index.html

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apidocs
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/apidocs)
	${INSTALL_DATA} ${WRKSRC}/intro.html ${STAGEDIR}${DOCSDIR}/index.html
.endif

.include <bsd.port.mk>
