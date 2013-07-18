# Created by: Michael Winking <mwfp@foldl.net>
# $FreeBSD$

PORTNAME=	hsqldb
PORTVERSION=	2.3.0
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_2_3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An embeddable SQL database written in Java

LICENSE=	BSD

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/build
ALL_TARGET=	hsqldb hsqljdbc

.include <bsd.port.options.mk>

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files to ${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/lib/hsqldb.jar \
		${JAVAJARDIR}/hsqldb.jar
	@${INSTALL_DATA} ${WRKSRC}/lib/hsqljdbc.jar \
		${JAVAJARDIR}/hsqljdbc.jar
	@${INSTALL_DATA} ${WRKSRC}/lib/sqltool.jar \
		${JAVAJARDIR}/sqltool.jar
	@${ECHO_MSG} " [DONE]"

.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing DOC files to ${DOCSDIR}..."
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	cd ${WRKSRC}/doc \
		&& ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
