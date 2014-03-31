# Created by: Michael Winking <mwfp@foldl.net>
# $FreeBSD$

PORTNAME=	commons-io
PORTVERSION=	2.4
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of I/O utilities for Java

LICENSE=	APACHE20

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

ALL_TARGET=	dist
JAVA_VERSION=	1.6+
MAKE_ARGS=	-cp ${JAVALIBDIR}/junit.jar
USE_ANT=	yes
USE_JAVA=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt apidocs

JAR_VERSION=	${PORTNAME}-2.2-SNAPSHOT

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/${JAR_VERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.if ${PORT_OPTIONS:MDOCS}
	(cd ${WRKSRC}/target && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} LICENSE.txt NOTICE.txt \
		RELEASE-NOTES.txt ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
