# Ports collection makefile for:	Jakarta Log4J
# Date created:				11 October 2002
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$
#

PORTNAME=	jakarta-log4j
PORTVERSION=	1.2.8
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	log4j/binaries

MAINTAINER=	hq@FreeBSD.org
COMMENT=	A fast and flexible logging library for Java

USE_JAVA=	YES
NO_BUILD=	YES

PLIST_FILES=	%%JAVAJARDIR%%/log4j.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	FAQ.html HISTORY TODO TROUBLESHOOT.html api contactUs.html \
		contributors.html critique.html deepExtension.html \
		documentation.html download.html earlier.html history.html \
		images index.html lf5 manual.html od.gif overview.html \
		plan.html praise.html srtw.html
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/log4j.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/dist/lib/log4j-${PORTVERSION}.jar ${JAVAJARDIR}/log4j.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing examples..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
