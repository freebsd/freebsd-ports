# New ports collection makefile for:	avalon-framework
# Date created:		2004-03-31
# Whom:			Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	avalon-framework
PORTVERSION=	4.1.5
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	avalon/avalon-framework/binaries/

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Apache Avalon core framework for component programming

USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
PORTDOCS=	api basics.html changelog-report.html cop cvs-usage.html \
		dependencies.html developer-activity-report.html \
		file-activity-report.html images index.html \
		issue-tracking.html license.html mail-lists.html \
		maven-reports.html principals project-info.html style \
		team-list.html
.endif
JARFILE=	${DISTNAME}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	${JAVAJARDIR:S,^${PREFIX}/,,}/${DESTJARFILE}

do-install:
	@${ECHO_CMD} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${CP} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_CMD} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@${CP} -r ${WRKSRC}/docs/${DOCFILE} ${DOCSDIR}/
	@${ECHO_CMD} -n " ${DOCFILE}"
.endfor
	@${ECHO_CMD} " [ DONE ]"
.endif

.include <bsd.port.mk>
