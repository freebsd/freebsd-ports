PORTNAME=	jaxb-api
DISTVERSION=	2.3.3
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/jakarta/xml/bind/jakarta.xml.bind-api/${DISTVERSION}/
DISTNAME=	jakarta.xml.bind-api-${DISTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Java API for XML Binding using the javax namespace
WWW=		https://jakarta.ee/specifications/xml-binding/2.3/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${JAVAJARDIR}/javax.activation-api.jar:devel/javax-activation-api

USES=		java:run
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

# 3.x and 4.x move the API from the javax.xml.bind to the jakarta.xml.bind
# namespace, which security/dogtag-pki cannot consume.  Stay on 2.3.x.
PORTSCOUT=	limit:^2\.3\.

PLIST_FILES=	${JAVAJARDIR}/jaxb-api.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${JAVAJARDIR}/jaxb-api.jar

.include <bsd.port.mk>
