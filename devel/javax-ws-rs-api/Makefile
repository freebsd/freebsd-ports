PORTNAME=	javax-ws-rs-api
DISTVERSION=	2.1.1
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/javax/ws/rs/javax.ws.rs-api/${DISTVERSION}/
DISTNAME=	javax.ws.rs-api-${DISTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Java API for RESTful Web Services
WWW=		https://github.com/jakartaee/rest

LICENSE=	EPL20 GPLv2wCE
LICENSE_COMB=	dual
LICENSE_NAME_EPL20=	Eclipse Public License version 2.0
LICENSE_NAME_GPLv2wCE=	GNU GPL version 2 with Classpath Exception
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS_EPL20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_GPLv2wCE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		java:run
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/javax.ws.rs-api.jar

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}/javax.ws.rs-api.jar

.include <bsd.port.mk>
