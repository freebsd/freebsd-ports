PORTNAME=	gson
DISTVERSION=	2.14.0	# Check the compatibility with math/scilab
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/google/code/gson/gson/${PORTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Java library to convert Java Objects into JSON and back
WWW=		https://github.com/google/gson

LICENSE=	APACHE20

USES=		java:run

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
