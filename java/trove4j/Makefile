# Ports collection makefile for:	GNU Trove4J
# Date created:				14 November 2002
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$

PORTNAME=	trove4j
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	trove4j
DISTNAME=	trove-${PORTVERSION}
COMMENT=	GNU Trove: High performance collections for Java

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr

USE_JAVA=	1.3+
NO_BUILD=	YES

PORT_JARFILE=		trove.jar
JAVA_WRKLIBDIR=		${WRKSRC}/lib
JAVA_WRKDOCSDIR=	${WRKSRC}/javadocs
PLIST_SUB+=		JAVAJARDIR=${JAVAJARDIR:S/^${PREFIX}\///}

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog LICENSE.txt README-license.txt README.txt javadocs
.endif

do-install:
	@${ECHO_CMD} -n ">> Installing JAR file..."
	@${MKDIR} ${JAVAJARDIR}
	@cd ${JAVA_WRKLIBDIR} && ${INSTALL_DATA} ${PORT_JARFILE} ${JAVAJARDIR}
	@${ECHO_CMD} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation..."
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/javadocs/{} ";"
	@cd ${JAVA_WRKDOCSDIR} && ${FIND} . -type f -exec ${INSTALL_MAN} ${JAVA_WRKDOCSDIR}/{} ${DOCSDIR}/javadocs/{} ";"
	@${INSTALL_MAN} ${WRKSRC}/AUTHORS ${DOCSDIR}/AUTHORS
	@${INSTALL_MAN} ${WRKSRC}/ChangeLog ${DOCSDIR}/ChangeLog
	@${INSTALL_MAN} ${WRKSRC}/LICENSE.txt ${DOCSDIR}/LICENSE.txt
	@${INSTALL_MAN} ${WRKSRC}/README-license.txt ${DOCSDIR}/README-license.txt
	@${INSTALL_MAN} ${WRKSRC}/README.txt ${DOCSDIR}/README.txt
	@${ECHO_CMD} " [DONE]"
.endif

post-install:
	@${ECHO_CMD} "${PORTNAME}-${PORTVERSION} installed as ${JAVAJARDIR}/${PORT_JARFILE}"

.include <bsd.port.mk>
