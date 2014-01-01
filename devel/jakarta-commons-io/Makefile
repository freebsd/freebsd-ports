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
COMMENT=	A collection of I/O utilities for Java

LICENSE=	APACHE20

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	dist
JAVA_VERSION=	1.6+
MAKE_ARGS=	-cp ${JAVALIBDIR}/junit.jar
USE_ANT=	yes
USE_JAVA=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt apidocs

JAR_VERSION=	${PORTNAME}-2.2-SNAPSHOT

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	${INSTALL_DATA} ${WRKSRC}/target/${JAR_VERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation..."
	cd ${WRKSRC}/target/ && ${COPYTREE_SHARE} apidocs ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} LICENSE.txt NOTICE.txt RELEASE-NOTES.txt ${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
