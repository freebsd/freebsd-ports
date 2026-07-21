PORTNAME=	activation-api
DISTVERSION=	2.1.4
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/jakarta/activation/jakarta.activation-api/${DISTVERSION}/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	jakarta.activation-api-${DISTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Jakarta API for handling MIME-typed data
WWW=		https://jakartaee.github.io/jaf-api/

LICENSE=	BSD3CLAUSE

USES=		java:run
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/jakarta.activation-api.jar

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${JAVAJARDIR}/jakarta.activation-api.jar

.include <bsd.port.mk>
