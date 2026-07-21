PORTNAME=	xml-bind-api
DISTVERSION=	4.0.5
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/jakarta/xml/bind/jakarta.xml.bind-api/${DISTVERSION}/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	jakarta.xml.bind-api-${DISTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Jakarta API for mapping Java objects to XML
WWW=		https://jakarta.ee/specifications/xml-binding/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${JAVAJARDIR}/jakarta.activation-api.jar:devel/jakarta-activation-api

USES=		java:run
JAVA_VERSION=	11+
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}/jakarta.xml.bind-api.jar

.include <bsd.port.mk>
