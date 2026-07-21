PORTNAME=	jackson-jaxrs-providers
DISTVERSION=	2.14.2
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/fasterxml/jackson/jaxrs/jackson-jaxrs-base/${DISTVERSION}/:base \
		https://repo1.maven.org/maven2/com/fasterxml/jackson/jaxrs/jackson-jaxrs-json-provider/${DISTVERSION}/:json
DISTFILES=	jackson-jaxrs-base-${DISTVERSION}.jar:base \
		jackson-jaxrs-json-provider-${DISTVERSION}.jar:json
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Jackson JSON provider for the JAX-RS API
WWW=		https://github.com/FasterXML/jackson-jaxrs-providers

LICENSE=	APACHE20

RUN_DEPENDS=	${JAVAJARDIR}/jackson-core.jar:devel/jackson-core \
		${JAVAJARDIR}/jackson-databind.jar:devel/jackson-databind \
		${JAVAJARDIR}/jackson-module-jaxb-annotations.jar:devel/jackson-module-jaxb-annotations \
		${JAVAJARDIR}/javax.ws.rs-api.jar:devel/javax-ws-rs-api

USES=		java:run
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/jackson-jaxrs-base.jar \
		${JAVAJARDIR}/jackson-jaxrs-json-provider.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/jackson-jaxrs-base-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/jackson-jaxrs-base.jar
	${INSTALL_DATA} ${DISTDIR}/jackson-jaxrs-json-provider-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/jackson-jaxrs-json-provider.jar

.include <bsd.port.mk>
