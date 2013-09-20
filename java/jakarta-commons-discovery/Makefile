# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	commons-discovery
PORTVERSION=	0.5
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_BINARIES}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A Java library for locating resources (including classes)

USE_JAVA=	YES
JAVA_VERSION=	1.6+
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
JARFILE=	${PORTNAME}.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@cd ${WRKSRC}/apidocs && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/apidocs && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
