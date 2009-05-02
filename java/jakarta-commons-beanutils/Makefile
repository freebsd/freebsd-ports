# New ports collection makefile for:	Jakarta Commons Beanutils
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-beanutils
PORTVERSION=	1.8.0
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_COMMONS_SOURCE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,commons-,,}
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaBeans utility library

BUILD_DEPENDS=	${JAR_DEPENDS}
RUN_DEPENDS=	${JAR_DEPENDS}

JAR_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections

USE_JAVA=	yes
JAVA_VERSION=	1.3+

USE_ANT=	yes
ALL_TARGET=	dist
MAKE_ARGS+=	-Dcommons-collections.jar=${JAVALIBDIR}/commons-collections.jar \
		-Dcommons-logging.jar=${JAVALIBDIR}/commons-logging.jar

JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
.if !defined(NOPORTDOCS)
APIDOCS=	api
OTHERDOCS=	LICENSE.txt NOTICE.txt README.txt RELEASE-NOTES.txt
PORTDOCS=	${APIDOCS} ${OTHERDOCS}
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/dist/docs \
	  && ${FIND} ${APIDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${APIDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
