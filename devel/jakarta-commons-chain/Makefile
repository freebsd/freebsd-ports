# New ports collection makefile for:	Jakarta Commons Chain
# Date created:				October 3, 2005
# Whom:					Adam VanderHook <acidos@bandwidth-junkies.net>
#
# $FreeBSD$
#

PORTNAME=	commons-chain
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	acidos@bandwidth-junkies.net
COMMENT=	API implementing Chain of Responsiblity design pattern

BUILD_DEPENDS=	${JAR_DEPENDS}
RUN_DEPENDS=	${JAR_DEPENDS}

JAR_DEPENDS=	${JAVALIBDIR}/commons-beanutils.jar:${PORTSDIR}/java/jakarta-commons-beanutils \
		${JAVALIBDIR}/commons-digester.jar:${PORTSDIR}/textproc/jakarta-commons-digester \
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/myfaces.jar:${PORTSDIR}/www/myfaces \
		${JAVALIBDIR}/portlet-api.jar:${PORTSDIR}/devel/portlet-api \
		${JAVALIBDIR}/servlet-api.jar:${PORTSDIR}/www/servlet-api

USE_JAVA=	yes
USE_ANT=	yes
MAKE_ENV=	CLASSPATH=${MAKE_CLASSPATH}
MAKE_ARGS=	-Dnoget=yes

.include <bsd.port.pre.mk>

MAKE_CLASSPATH!=	${ECHO_CMD} ${JAR_DEPENDS:C|:.*$||} | ${SED} 's| |:|g'

ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
OTHERDOCS=	LICENSE.txt NOTICE.txt
PORTDOCS=	api ${OTHERDOCS}
.endif
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
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
