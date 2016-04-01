# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-beanutils
PORTVERSION=	1.9.2
CATEGORIES=	java devel
MASTER_SITES=	APACHE_COMMONS_SOURCE
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	JavaBeans utility library

LICENSE=	APACHE20

BUILD_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/jakarta-commons-logging \
		${JAVALIBDIR}/commons-collections.jar:java/jakarta-commons-collections
RUN_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/jakarta-commons-logging \
		${JAVALIBDIR}/commons-collections.jar:java/jakarta-commons-collections

USES=		dos2unix
USE_JAVA=	yes
USE_ANT=	yes
DOS2UNIX_FILES=	build.xml
JAVA_VERSION=	1.6+
ALL_TARGET=	dist
MAKE_ARGS+=	-Dcommons-collections.jar=${JAVALIBDIR}/commons-collections.jar \
		-Dcommons-logging.jar=${JAVALIBDIR}/commons-logging.jar

JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
APIDOCS=	api
OTHERDOCS=	LICENSE.txt NOTICE.txt RELEASE-NOTES.txt
PORTDOCS=	${APIDOCS} ${OTHERDOCS}
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVALIBDIR}/${JARFILE}
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/dist/docs \
	  && ${FIND} ${APIDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} ${APIDOCS} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
