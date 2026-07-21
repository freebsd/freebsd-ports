PORTNAME=	annotation-api
DISTVERSION=	3.0.0
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/jakarta/annotation/jakarta.annotation-api/${DISTVERSION}/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	jakarta.annotation-api-${DISTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Jakarta API for common semantic annotations
WWW=		https://jakarta.ee/specifications/annotations/

LICENSE=	EPL20 GPLv2wCE
LICENSE_COMB=	dual
LICENSE_NAME_EPL20=	Eclipse Public License version 2.0
LICENSE_NAME_GPLv2wCE=	GNU GPL version 2 with Classpath Exception
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS_EPL20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_GPLv2wCE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		java:run
JAVA_VERSION=	11+

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}/jakarta.annotation-api.jar

.include <bsd.port.mk>
