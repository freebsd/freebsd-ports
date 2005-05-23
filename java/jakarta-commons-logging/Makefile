# New ports collection makefile for:	Jakarta Commons Logging
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-logging
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Generic logging wrapper library

OPTIONS=	LOG4J "Enable Jakarta Log4j log factory" on \
		LOGKIT "Enable Avalon LogKit log factory" off \
		JDK14LOG "Enable JDK 1.4 log factory" off

USE_JAVA=	yes
USE_ANT=	yes
MAKE_ENV+=	ANT_INCLUDE_SHARED_JARS=YES

.include <bsd.port.pre.mk>

.if defined(WITH_JDK14LOG)
JAVA_VERSION=	1.4+
.else
JAVA_VERSION=	1.2+
.endif

.if defined(WITH_LOG4J)
BUILD_DEPENDS+=	${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j
.endif

.if defined(WITH_LOGKIT)
BUILD_DEPENDS+=	${JAVALIBDIR}/logkit.jar:${PORTSDIR}/java/avalon-logkit
.endif

ALL_TARGET=	compile
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
OTHERDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt
PORTDOCS=	api ${OTHERDOCS}
.endif
JARFILE=	${PORTNAME}.jar ${PORTNAME}-api.jar
PLIST_FILES=	${JARFILE:S|^|%%JAVAJARDIR%%/|}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JARFILE:S|^|${JAVAJARDIR}/|}..."
	@${INSTALL_DATA} ${JARFILE:S|^|${WRKSRC}/target/|} ${JAVAJARDIR}
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/dist/docs \
	  && ${FIND} api -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} api -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} " ${PORTDOCS} [ DONE ]"
.endif

.include <bsd.port.post.mk>
