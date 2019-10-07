# Created by: Dave Glowacki <dglo@ssec.wisc.edu>
# $FreeBSD$

PORTNAME=	jakarta-oro
PORTVERSION=	2.0.8
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	http://archive.apache.org/dist/jakarta/oro/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl/awk/sh regular expressions for Java

LICENSE=	APACHE20

USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	1.6+
ALL_TARGET=	jar javadocs

JAVALIBNAME=	${PORTNAME}-${PORTVERSION}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/api && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
