# New ports collection makefile for:	avalon-framework
# Date created:		2004-03-31
# Whom:			Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	avalon-framework
PORTVERSION=	4.2.0
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	avalon/${PORTNAME}/binaries/

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Apache Avalon core framework for component programming

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	api basics.html cop cvs-usage.html dependencies.html images \
		index.html issue-tracking.html license.html linkcheck.html \
		mail-lists.html maven-reports.html principals \
		project-info.html style team-list.html
.endif

JARFILES=	${PORTNAME}.jar ${PORTNAME}-api.jar ${PORTNAME}-impl.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${JAVAJARDIR}/..."
.for jarfile in ${JARFILES}
	@${ECHO_MSG} -n " ${jarfile}"
	@${INSTALL_DATA} ${WRKSRC}/jars/${jarfile:S,.jar$,-${PORTVERSION}.jar,} ${JAVAJARDIR}/${jarfile}
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/docs \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
