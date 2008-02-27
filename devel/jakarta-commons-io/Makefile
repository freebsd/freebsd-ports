# Ports collection makefile for:	Jakarta Commons IO
# Date created:			14 Feb 2006
# Whom:				Michael Winking <mwfp@foldl.net>
#
# $FreeBSD$
#

PORTNAME=	commons-io
PORTVERSION=	1.3.2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	nemoliu@FreeBSD.org
COMMENT=	A collection of I/O utilities for Java

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ANT=	yes

MAKE_ARGS=	-cp ${JAVALIBDIR}/junit.jar
ALL_TARGET=	dist
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt docs
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}-${PORTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@cd ${WRKSRC}/build/dist-build/${PORTNAME}-${PORTVERSION} \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/NOTICE.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES.txt ${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
