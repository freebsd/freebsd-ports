PORTNAME=	commons-beanutils
PORTVERSION=	1.11.0
CATEGORIES=	java devel
MASTER_SITES=	APACHE_COMMONS_SOURCE
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	JavaBeans utility library
WWW=		https://commons.apache.org/proper/commons-beanutils/

LICENSE=	APACHE20

BUILD_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVALIBDIR}/commons-collections.jar:java/apache-commons-collections
RUN_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVALIBDIR}/commons-collections.jar:java/apache-commons-collections

USES=		dos2unix java:ant,run
DOS2UNIX_FILES=	build.xml

MAKE_ARGS+=	-Dcommons-collections.jar=${JAVALIBDIR}/commons-collections.jar \
		-Dcommons-logging.jar=${JAVALIBDIR}/commons-logging.jar
ALL_TARGET=	dist

NO_ARCH=	yes

JARFILE=	${PORTNAME}.jar
PLIST_FILES=	${JAVAJARDIR}/${JARFILE}

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
