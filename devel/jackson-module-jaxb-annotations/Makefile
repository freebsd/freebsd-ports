PORTNAME=	jackson-module-jaxb-annotations
DISTVERSION=	2.14.2
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/fasterxml/jackson/module/${PORTNAME}/${DISTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Jackson support for legacy JAXB annotations
WWW=		https://github.com/FasterXML/jackson-modules-base

LICENSE=	APACHE20

RUN_DEPENDS=	${JAVAJARDIR}/jackson-annotations.jar:devel/jackson-annotations \
		${JAVAJARDIR}/jackson-core.jar:devel/jackson-core \
		${JAVAJARDIR}/jackson-databind.jar:devel/jackson-databind \
		${JAVAJARDIR}/javax.activation-api.jar:devel/javax-activation-api \
		${JAVAJARDIR}/jaxb-api.jar:devel/jaxb-api

USES=		java:run
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/jackson-module-jaxb-annotations.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}/jackson-module-jaxb-annotations.jar

.include <bsd.port.mk>
