# New ports collection makefile for:	Jakarta Commons Logging
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-logging
PORTVERSION=	1.0.3
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/logging/source/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Generic logging wrapper library

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

OPTIONS=	LOG4J "Enable Jakarta Log4j log factory" on \
		LOGKIT "Enable Avalon LogKit log factory" off \
		JDK14LOG "Enable JDK 1.4 log factory" off

USE_JAVA=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_JDK14LOG)
JAVA_VERSION=	1.4+
.else
JAVA_VERSION=	1.2+
.endif

.if defined(WITH_LOG4J)
BUILD_DEPENDS+=	${JAVAJARDIR}/log4j.jar:${PORTSDIR}/java/jakarta-log4j
.endif

.if defined(WITH_LOGKIT)
BUILD_DEPENDS+=	${JAVAJARDIR}/logkit.jar:${PORTSDIR}/java/avalon-logkit
.endif

ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET=	compile
.if !defined(NOPORTDOCS)
ANT_TARGET+=	javadoc
PORTDOCS=	api LICENSE
.endif
JARFILE=	${PORTNAME}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES=	${JAVAJARDIR:S,^${PREFIX}/,,}/${DESTJARFILE}

post-extract:
	@${CP} ${PORTSDIR}/java/jakarta-commons-beanutils/files/LICENSE ${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/

do-build:
	@cd ${WRKSRC} && ${SETENV} ANT_INCLUDE_SHARED_JARS=YES ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO_CMD} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${CP} ${WRKSRC}/target/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_CMD} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/dist/docs/api ${DOCSDIR}/
	@${CP} ${WRKSRC}/LICENSE ${DOCSDIR}/
	@${ECHO_CMD} " ${PORTDOCS} [ DONE ]"
.endif

.include <bsd.port.post.mk>
