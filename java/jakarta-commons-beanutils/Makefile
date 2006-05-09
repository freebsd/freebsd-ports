# New ports collection makefile for:	Jakarta Commons Beanutils
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-beanutils
PORTVERSION=	1.7.0
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/beanutils/source/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	hq@FreeBSD.org
COMMENT=	JavaBeans utility library

BUILD_DEPENDS=	${JAR_DEPENDS}
RUN_DEPENDS=	${JAR_DEPENDS}

JAR_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections

USE_JAVA=	yes
JAVA_VERSION=	1.2+

USE_ANT=	yes
ALL_TARGET=	dist
MAKE_ARGS+=	-Dcommons-collections.api=${COMMONS_COLLECTIONS_API} \
		-Dcommons-logging.api=${COMMONS_LOGGING_API} \
		-Dcommons-collections.jar=${JAVALIBDIR}/commons-collections.jar \
		-Dcommons-logging.jar=${JAVALIBDIR}/commons-logging.jar

JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
.if !defined(NOPORTDOCS)
APIDOCS=	api bean-collections
OTHERDOCS=	LICENSE.txt NOTICE.txt README.txt RELEASE-NOTES.txt
PORTDOCS=	${APIDOCS} ${OTHERDOCS}
.endif

COMMONS_COLLECTIONS_API=${LOCALBASE}/share/doc/commons-collections/apidocs
COMMONS_LOGGING_API=	${LOCALBASE}/share/doc/commons-logging/api

.if !defined(NOPORTDOCS)
do-configure:
	@if [ -d "${COMMONS_COLLECTIONS_API}" ] ; \
	then \
	  ${REINPLACE_CMD} -e 's,http://jakarta.apache.org/commons/collections/api/,${COMMONS_COLLECTIONS_API},' ${WRKSRC}/build.xml ; \
	fi
	@if [ -d "${COMMONS_LOGGING_API}" ] ; \
	then \
	  ${REINPLACE_CMD} -e 's,http://jakarta.apache.org/commons/logging/api/,${COMMONS_LOGGING_API},' ${WRKSRC}/build.xml ; \
	fi
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${JARFILE} ${JAVAJARDIR}/${JARFILE}
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
