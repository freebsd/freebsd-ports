# Ports collection makefile for:	Jakarta Log4J
# Date created:				11 October 2002
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	jakarta-log4j
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://jakarta.apache.org/log4j/
DIST_SUBDIR=	jakarta

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr

USE_JAVA=	1.1+
NO_BUILD=	YES

PORT_JARFILE=		log4j-${PORTVERSION}.jar
JAVA_WRKLIBDIR=		${WRKSRC}/dist/lib
JAVA_WRKDOCSDIR=	${WRKSRC}/docs
JAVA_WRKEXAMPLESDIR=	${WRKSRC}/examples
JAVA_LIBDIR=		${PREFIX}/share/java/classes
JAVA_EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

INSTALL_JAR=		${INSTALL_DATA}

do-install:
	@${ECHO_CMD} -n ">> Installing JAR file..."
	@${MKDIR} ${JAVA_LIBDIR}
	@cd ${JAVA_WRKLIBDIR} && ${INSTALL_JAR} ${PORT_JARFILE} ${JAVA_LIBDIR}/${PORTNAME}.jar
	@${ECHO_CMD} " [DONE]"

.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation..."
	@cd ${JAVA_WRKDOCSDIR}     && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${JAVA_WRKDOCSDIR}     && ${FIND} . -type f -exec ${INSTALL_MAN} ${JAVA_WRKDOCSDIR}/{} ${DOCSDIR}/{} ";"
	@${ECHO_CMD} " [DONE]"

	@${ECHO_CMD} -n ">> Installing examples..."
	@cd ${JAVA_WRKEXAMPLESDIR} && ${FIND} . -type d -exec ${MKDIR} ${JAVA_EXAMPLESDIR}/{} ";"
	@cd ${JAVA_WRKEXAMPLESDIR} && ${FIND} . -type f -exec ${INSTALL_DATA} ${JAVA_WRKEXAMPLESDIR}/{} ${JAVA_EXAMPLESDIR}/{} ";"
	@${ECHO_CMD} " [DONE]"
.endif

post-install:
	@${ECHO_CMD} "${PORTNAME}-${PORTVERSION} installed as ${JAVA_LIBDIR}/${PORT_JARFILE}"

.include <bsd.port.mk>
