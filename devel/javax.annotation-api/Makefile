PORTNAME=	javax.annotation-api
DISTVERSION=	1.3.2	# Check the compatibily with math/scilab
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/javax/annotation/javax.annotation-api/${PORTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Common Annotations for the Java Platform
WWW=		https://jcp.org/en/jsr/detail?id=250

LICENSE=	GPLv2

USES=		java:run

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
