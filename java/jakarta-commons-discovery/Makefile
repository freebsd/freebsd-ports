# New ports collection makefile for:	jakarta-commons-discovery
# Date created:		2004-04-13
# Whom:			Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	commons-discovery
PORTVERSION=	0.2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/binaries
PKGNAMEPREFIX=	jakarta-

MAINTAINER=	hq@FreeBSD.org
COMMENT=	A Java library for locating resources (including classes)

USE_JAVA=	YES
JAVA_VERSION=	1.3+
JAVA_RUN=	JDK
NO_BUILD=	YES

.if !defined(NOPORTDOCS)
PORTDOCS=	api LICENSE
.endif
JARFILE=	${PORTNAME}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}

post-extract:
	@${MV} ${WRKSRC}/LICENSE ${WRKSRC}/docs/

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
