# Ports collection makefile for:	Jakarta Commons IO
# Date created:			14 Feb 2006
# Whom:				Michael Winking <mwfp@foldl.net>
#
# $FreeBSD$
#

PORTNAME=	commons-io
PORTVERSION=	2.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of I/O utilities for Java

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

LICENSE=	ASL

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes

MAKE_ARGS=	-cp ${JAVALIBDIR}/junit.jar
ALL_TARGET=	dist
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt apidocs
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@cd ${WRKSRC}/target/ \
	  && ${FIND} apidocs -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} apidocs -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/NOTICE.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES.txt ${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
