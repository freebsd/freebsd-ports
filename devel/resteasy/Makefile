PORTNAME=	resteasy
DISTVERSION=	3.0.26
DISTVERSIONSUFFIX=	.Final
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/org/jboss/resteasy/resteasy-jaxrs/${DISTVERSIONFULL}/:jaxrs
MASTER_SITES+=	https://repo1.maven.org/maven2/org/jboss/resteasy/resteasy-jackson2-provider/${DISTVERSIONFULL}/:jackson2
MASTER_SITES+=	https://repo1.maven.org/maven2/org/jboss/resteasy/resteasy-servlet-initializer/${DISTVERSIONFULL}/:servlet
DISTFILES=	resteasy-jaxrs-${DISTVERSIONFULL}.jar:jaxrs
DISTFILES+=	resteasy-jackson2-provider-${DISTVERSIONFULL}.jar:jackson2
DISTFILES+=	resteasy-servlet-initializer-${DISTVERSIONFULL}.jar:servlet
EXTRACT_ONLY=	

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	RESTEasy JAX-RS implementation and Jackson provider
WWW=	https://resteasy.dev/

LICENSE=	APACHE20

RUN_DEPENDS=	${JAVAJARDIR}/javax.ws.rs-api.jar:devel/javax-ws-rs-api
RUN_DEPENDS+=	${JAVAJARDIR}/javax.activation-api.jar:devel/javax-activation-api
RUN_DEPENDS+=	${JAVAJARDIR}/jboss-logging.jar:devel/jboss-logging
RUN_DEPENDS+=	${JAVAJARDIR}/commons-io.jar:devel/apache-commons-io
RUN_DEPENDS+=	${JAVAJARDIR}/httpclient.jar:www/httpclient
RUN_DEPENDS+=	${JAVAJARDIR}/jackson-annotations.jar:devel/jackson-annotations
RUN_DEPENDS+=	${JAVAJARDIR}/jackson-core.jar:devel/jackson-core
RUN_DEPENDS+=	${JAVAJARDIR}/jackson-databind.jar:devel/jackson-databind
RUN_DEPENDS+=	${JAVAJARDIR}/jackson-jaxrs-json-provider.jar:devel/jackson-jaxrs-providers

USES=	java:run
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/resteasy-jaxrs.jar
PLIST_FILES+=	${JAVAJARDIR}/resteasy-jackson2-provider.jar
PLIST_FILES+=	${JAVAJARDIR}/resteasy-servlet-initializer.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/resteasy-jaxrs-${DISTVERSIONFULL}.jar ${STAGEDIR}${JAVAJARDIR}/resteasy-jaxrs.jar
	${INSTALL_DATA} ${DISTDIR}/resteasy-jackson2-provider-${DISTVERSIONFULL}.jar ${STAGEDIR}${JAVAJARDIR}/resteasy-jackson2-provider.jar
	${INSTALL_DATA} ${DISTDIR}/resteasy-servlet-initializer-${DISTVERSIONFULL}.jar ${STAGEDIR}${JAVAJARDIR}/resteasy-servlet-initializer.jar

.include <bsd.port.mk>
