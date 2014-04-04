# Created by: Radim Kolar <hsn@filez.com>
# $FreeBSD$

# Note to committers:
# With each version update, a new maven repository must be created and distributed
# so build is repeatable and cluster-safe.

PORTNAME=	snappy
PORTVERSION=	1.0.4.1
PORTREVISION=	1
CATEGORIES=	archivers java
MASTER_SITES=	GITHUB:source1 \
		http://snappy.googlecode.com/files/:source2 \
		LOCAL/jgh/archivers/${PORTNAME}/:source3
PKGNAMESUFFIX=	java
DISTFILES+=	snappy-${PORTVERSION}.tar.gz:source1 \
		snappy-${PORTVERSION:R}.tar.gz:source2 \
		FreeBSD-snappy-${PORTVERSION}-maven-repository.tar.gz:source3
EXTRACT_ONLY=	snappy-${PORTVERSION}.tar.gz \
		FreeBSD-snappy-${PORTVERSION}-maven-repository.tar.gz

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Fast compressor/decompressor library

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:${PORTSDIR}/devel/maven3

GH_ACCOUNT=	xerial
GH_PROJECT=	snappy-java
GH_TAGNAME=	snappy-java-${PORTVERSION}
GH_COMMIT=	487f82d
USE_GITHUB=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.7
USES=		gmake
USE_LDCONFIG=	yes
MAKE_ARGS+=	Default_CXX=${CXX}

PLIST_FILES=	%%JAVAJARDIR%%/snappy-java.jar lib/libsnappyjava.so

post-patch:
	@${REINPLACE_CMD} -e 's|curl.*||g ; \
		s|MVN:=mvn|MVN:=mvn -Dmaven.repo.local=${WRKDIR}/repository --offline|g' \
		${WRKSRC}/Makefile

do-build:
	@${MKDIR} ${WRKSRC}/target
	@${CP} ${DISTDIR}/snappy-${PORTVERSION:R}.tar.gz ${WRKSRC}/target/
	cd ${WRKSRC} && ${SETENV} JAVA_HOME=${JAVA_HOME} \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} && ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/repository --offline test

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/snappy-java-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/snappy-java.jar
	${INSTALL_LIB} ${WRKSRC}/target/snappy-${PORTVERSION:R}-Default/libsnappyjava.so \
		${STAGEDIR}${LOCALBASE}/lib

.include <bsd.port.mk>
