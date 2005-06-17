# Ports collection makefile for:	GNU Trove4J
# Date created:				14 November 2002
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$

PORTNAME=	trove4j
PORTVERSION=	1.1b4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	trove4j
DISTNAME=	trove-${PORTVERSION}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	High performance collections API for Java

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	javadocs AUTHORS ChangeLog LICENSE.txt README-license.txt README.txt
.endif
JARFILE=	trove.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC} && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC} && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
