PORTNAME=	protobuf-java
DISTVERSION=	4.32.0
CATEGORIES=	devel java
MASTER_SITES=	https://repo1.maven.org/maven2/com/google/protobuf/protobuf-java/${DISTVERSION}/
EXTRACT_SUFX=	.jar

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Core Protocol Buffers library
WWW=		https://protobuf.dev/ \
		https://github.com/protocolbuffers/protobuf/ \
		https://mvnrepository.com/artifact/com.google.protobuf/protobuf-java/

LICENSE=	BSD3CLAUSE

USES=		java

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
