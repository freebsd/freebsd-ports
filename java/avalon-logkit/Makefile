# Ports collection makefile for:	Avalon LogKit
# Date created:				06 November 2003
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	logkit
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://www.apache.org/dist/avalon/${PORTNAME:S,-,/,}/binaries/
PKGNAMEPREFIX=	avalon-
DISTNAME=	LogKit-${PORTVERSION}-bin

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr
COMMENT=	Java toolkit designed for secure performance oriented logging

USE_JAVA=	1.3+
NO_BUILD=	YES

WRKSRC=			${WRKDIR}/LogKit-${PORTVERSION}
PORT_JARFILE=		${PORTNAME}-${PORTVERSION}.jar
DEST_JARFILE=		${PORTNAME}.jar
JAVA_WRKDOCSDIR=	${WRKSRC}/docs
PLIST_SUB+=		JAVAJARDIR=${JAVAJARDIR:S/^${PREFIX}\///}

.if !defined(NOPORTDOCS)
PORTDOCS=	api changes.html css features.html images index.html whitepaper.html
.endif

do-install:
	@${ECHO_CMD} -n ">> Installing JAR file..."
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORT_JARFILE} ${JAVAJARDIR}/${DEST_JARFILE}
	@${ECHO_CMD} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation..."
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type f -exec ${INSTALL_MAN} ${JAVA_WRKDOCSDIR}/{} ${DOCSDIR}/{} ";"
	@${ECHO_CMD} " [DONE]"
.endif

post-install:
	@${ECHO_CMD} "${PORTNAME}-${PORTVERSION} installed as ${JAVAJARDIR}/${PORT_JARFILE}"

.include <bsd.port.mk>
