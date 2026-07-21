PORTNAME=	jackson-core
DISTVERSION=	2.14.2
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/fasterxml/jackson/core/${PORTNAME}/${DISTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Core streaming JSON processor for Jackson
WWW=		https://github.com/FasterXML/jackson-core

LICENSE=	APACHE20

USES=		java:run
JAVA_VERSION=	8+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/jackson-core.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${JAVAJARDIR}/jackson-core.jar

.include <bsd.port.mk>
