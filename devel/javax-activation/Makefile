PORTNAME=	activation
DISTVERSION=	1.1.1	# Please check compatibility with math/scilab
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/javax/activation/activation/${PORTVERSION}/
PKGNAMEPREFIX=	javax
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java Activation Framework
WWW=		https://mvnrepository.com/artifact/javax.activation

LICENSE=	BSD3CLAUSE

USES=		java:run

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
