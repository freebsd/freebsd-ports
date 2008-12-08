# Ports collection makefile for:	Jakarta Commons DbUtils
# Date created:			14 Feb 2006
# Whom:				Michael Winking <mwfp@foldl.net>
#
# $FreeBSD$
#

PORTNAME=	commons-dbutils
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JDBC helper library

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ANT=	yes

ALL_TARGET=	dist
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE.txt api
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|' ${WRKSRC}/build.xml

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/commons-dbutils-1.1.jar \
		${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/dist/LICENSE.txt \
		${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
