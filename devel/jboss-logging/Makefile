PORTNAME=	jboss-logging
DISTVERSION=	3.6.3
DISTVERSIONSUFFIX=	.Final
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/org/jboss/logging/${PORTNAME}/${DISTVERSIONFULL}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Logging facade for various Java log managers
WWW=		https://github.com/jboss-logging/jboss-logging

LICENSE=	APACHE20

USES=		java:run
JAVA_VERSION=	11+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
