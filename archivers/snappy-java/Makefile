# Created by: Radim Kolar <hsn@filez.com>
# $FreeBSD$

# Note to committers:
# With each version update, a new maven repository must be created and distributed
# so build is repeatable and cluster-safe.

PORTNAME=	snappy
PORTVERSION=	1.0.4.1
DISTVERSIONPREFIX=	snappy-java-
PORTREVISION=	2
CATEGORIES=	archivers java
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/snappy/snappy-1.0.4.tar.gz/b69151652e82168bc5c643bcd6f07162/:source2 \
		SF/bsdsrc/${.CURDIR:T}:source3
PKGNAMESUFFIX=	java
DISTFILES+=	snappy-${PORTVERSION:R}.tar.gz:source2 \
		FreeBSD-snappy-${PORTVERSION}-maven-repository.tar.gz:source3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		FreeBSD-snappy-${PORTVERSION}-maven-repository.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast compressor/decompressor library

LICENSE=	APACHE20

BROKEN_armv6=		fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_armv7=		fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_powerpc64=	fails to build: failed to execute goal org.apache.maven.plugins:maven-surefire-plugin:2.14.1:test

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:devel/maven3

USE_GITHUB=	yes
GH_ACCOUNT=	xerial
GH_PROJECT=	snappy-java

USES=		gmake
USE_JAVA=	yes
USE_LDCONFIG=	yes
MAKE_ARGS+=	Default_CXX=${CXX}

PLIST_FILES=	%%JAVAJARDIR%%/snappy-java.jar lib/libsnappyjava.so

post-patch:
	@${REINPLACE_CMD} -e 's|curl.*||g ; \
		s|MVN:=mvn|MVN:=${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/repository --offline|g' \
		${WRKSRC}/Makefile

do-build:
	@${MKDIR} ${WRKSRC}/target
	@${CP} ${DISTDIR}/snappy-${PORTVERSION:R}.tar.gz ${WRKSRC}/target/
	cd ${WRKSRC} && ${SETENV} JAVA_HOME=${JAVA_HOME} \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} && ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/repository --offline test

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/snappy-java-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/snappy-java.jar
	${INSTALL_LIB} ${WRKSRC}/target/snappy-${PORTVERSION:R}-Default/libsnappyjava.so \
		${STAGEDIR}${LOCALBASE}/lib

.include <bsd.port.mk>
