# Ports collection makefile for:	Jakarta Commons IO
# Date created:			14 Feb 2006
# Whom:				Michael Winking <mwfp@foldl.net
#
# $FreeBSD$
#

PORTNAME=	commons-io
PORTVERSION=	1.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/io/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	mwfp@foldl.net
COMMENT=	A collection of I/O utilities for Java

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ANT=	yes

MAKE_ARGS=	-cp ${JAVAJARDIR}/junit.jar
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
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/build/dist-build/${PORTNAME}-${PORTVERSION} && ${FIND} docs \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt \
		${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/NOTICE.txt \
		${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES.txt \
		${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
