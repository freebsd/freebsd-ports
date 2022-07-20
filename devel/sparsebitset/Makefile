PORTNAME=	SparseBitSet
PORTVERSION=	1.2
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/zaxxer/${PORTNAME}/${PORTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Efficient sparse bitset implementation for Java

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	8+

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES}	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
