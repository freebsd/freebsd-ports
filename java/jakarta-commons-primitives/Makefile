# Ports collection makefile for:	Jakarta Commons Primitives
# Date created:				06 November 2003
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	commons-primitives
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/primitives/binaries
PKGNAMEPREFIX=	jakarta-

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr
COMMENT=	A library supporting Java primitive types

USE_JAVA=	1.3+
NO_BUILD=	YES

PORT_JARFILE=		${PORTNAME}-${PORTVERSION}.jar
DEST_JARFILE=		${PORTNAME}.jar
JAVA_WRKDOCSDIR=	${WRKSRC}/docs
PLIST_SUB+=		JAVAJARDIR=${JAVAJARDIR:S/^${PREFIX}\///}

.if !defined(NOPORTDOCS)
PORTDOCS=	apidocs
.endif

do-install:
	@${ECHO_CMD} -n ">> Installing JAR file..."
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORT_JARFILE} ${JAVAJARDIR}/${DEST_JARFILE}
	@${ECHO_CMD} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation..."
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type d -mindepth 1 -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type f -exec ${INSTALL_MAN} ${JAVA_WRKDOCSDIR}/{} ${DOCSDIR}/{} ";"
	@${ECHO_CMD} " [DONE]"
.endif

post-install:
	@${ECHO_CMD} "${PORTNAME}-${PORTVERSION} installed as ${JAVAJARDIR}/${PORT_JARFILE}"

.include <bsd.port.mk>
