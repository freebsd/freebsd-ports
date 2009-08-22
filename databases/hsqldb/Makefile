# New ports collection makefile for:   hsqldb
# Date created:        14 Feb 2006
# Whom:                Michael Winking <mwfp@foldl.net>
#
# $FreeBSD$
#

PORTNAME=	hsqldb
PORTVERSION=	1.8.0.10
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_1_8_0
DISTNAME=	hsqldb_${PORTVERSION:S/./_/g}
#EXTRACT_SUFX=	.zip

MAINTAINER=	wenheping@gmail.com
COMMENT=	An embeddable SQL database written in Java

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/build
ALL_TARGET=	hsqldb hsqljdbc

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files to ${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/lib/hsqldb.jar \
		${JAVAJARDIR}/hsqldb.jar
	@${INSTALL_DATA} ${WRKSRC}/lib/hsqljdbc.jar \
		${JAVAJARDIR}/hsqljdbc.jar
	@${ECHO_MSG} " [DONE]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing DOC files to ${DOCSDIR}..."
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	cd ${WRKSRC}/doc \
		&& ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
