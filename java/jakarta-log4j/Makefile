# Ports collection makefile for:	Jakarta Log4J
# Date created:				11 October 2002
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	jakarta-log4j
PORTVERSION=	1.2.8
CATEGORIES=	java
MASTER_SITES=	http://jakarta.apache.org/log4j/

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr
COMMENT=	Log4J, a fast and flexible logging library for Java

USE_JAVA=	1.1+
NO_BUILD=	YES

PORT_JARFILE=		log4j-${PORTVERSION}.jar
DEST_JARFILE=		log4j.jar
JAVA_WRKJARDIR=		${WRKSRC}/dist/lib
JAVA_WRKDOCSDIR=	${WRKSRC}/docs
JAVA_WRKEXAMPLESDIR=	${WRKSRC}/examples

PLIST_SUB+=		JAVAJARDIR=${JAVAJARDIR:S/^${PREFIX}\///}

.if !defined(NOPORTDOCS)
PORTDOCS=	FAQ.html HISTORY TODO TROUBLESHOOT.html api contactUs.html \
		contributors.html critique.html deepExtension.html \
		documentation.html download.html earlier.html history.html \
		images index.html lf5 manual.html od.gif overview.html \
		plan.html praise.html srtw.html
.endif

do-install:
	@${ECHO_CMD} -n ">> Installing JAR file..."
	@${MKDIR} ${JAVAJARDIR}
	@cd ${JAVA_WRKJARDIR} && ${INSTALL_DATA} ${PORT_JARFILE} ${JAVAJARDIR}/${DEST_JARFILE}
	@${ECHO_CMD} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation..."
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type f -exec ${INSTALL_MAN} ${JAVA_WRKDOCSDIR}/{} ${DOCSDIR}/{} ";"
	@${ECHO_CMD} " [DONE]"

	@${ECHO_CMD} -n ">> Installing examples..."
	@cd ${JAVA_WRKEXAMPLESDIR} && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} ";"
	@cd ${JAVA_WRKEXAMPLESDIR} && ${FIND} . -type f -exec ${INSTALL_DATA} ${JAVA_WRKEXAMPLESDIR}/{} ${EXAMPLESDIR}/{} ";"
	@${ECHO_CMD} " [DONE]"
.endif

post-install:
	@${ECHO_CMD} "${PORTNAME}-${PORTVERSION} installed as ${JAVAJARDIR}/${DEST_JARFILE}"

.include <bsd.port.mk>
