# Note to committers:
# With each version update, a new maven repository must be created
# and distributed so build is repeatable and cluster-safe.

PORTNAME=	snappy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.10.5
CATEGORIES=	archivers java
MASTER_SITES=	LOCAL/otis:repo
PKGNAMESUFFIX=	java
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${PKGNAMESUFFIX}-repository-${PORTVERSION}${EXTRACT_SUFX}:repo
EXTRACT_ONLY=	${DISTFILE_DEFAULT} \
		${PORTNAME}-${PKGNAMESUFFIX}-repository-${PORTVERSION}${EXTRACT_SUFX} \
		${DISTFILE_google_benchmark} \
		${DISTFILE_google_googletest}

MAINTAINER=	language.devel@gmail.com
COMMENT=	Fast compressor/decompressor library
WWW=		https://github.com/xerial/snappy-java

LICENSE=	APACHE20

BROKEN_armv6=	fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_armv7=	fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes

BUILD_DEPENDS=	cmake:devel/cmake-core \
		sbt:devel/sbt

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	xerial
GH_PROJECT=	snappy-java
GH_TAGNAME=	${DISTVERSIONFULL}
GH_TUPLE=	google:snappy:${DISTVERSION:R}:google \
		google:benchmark:d572f47:google_benchmark/google_benchmark \
		google:googletest:b796f7d:google_googletest/google_googletest \
		kiyo-masui:bitshuffle:${BITSHUFFLE_V}:masui

USE_JAVA=	yes
JAVA_BUILD=	jre # prevent JAVA_RUN via bsd.java.mk
USE_LDCONFIG=	yes
MAKE_ARGS+=	CXX="${CXX}"
TEST_TARGET=	test
BITSHUFFLE_V=	0.3.4

PLIST_FILES=	${JAVAJARDIR}/snappy-java.jar \
		lib/libsnappyjava.so

.include <bsd.port.pre.mk>

post-extract:
	${MKDIR} ${WRKSRC}/target
	${RM} ${WRKSRC}/sbt
	${CP} ${DISTDIR}/${DISTFILE_google} ${WRKSRC}/target/snappy-${PORTVERSION:R}${EXTRACT_SUFX}
	${CP} ${DISTDIR}/${DISTFILE_masui} ${WRKSRC}/target/bitshuffle-${BITSHUFFLE_V}${EXTRACT_SUFX}
	(cd ${WRKSRC}/google_benchmark && \
		${COPYTREE_SHARE} . ${WRKSRC}/target/snappy-${PORTVERSION:R}/third_party/benchmark)
	(cd ${WRKSRC}/google_googletest && \
		${COPYTREE_SHARE} . ${WRKSRC}/target/snappy-${PORTVERSION:R}/third_party/googletest)

do-build:
	cd ${WRKSRC} && ${SETENV} JAVA_HOME=${JAVA_HOME} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} SBT_IVY_HOME=${WRKDIR}/repository SBT_BOOT_DIR=${WRKDIR}/sbt_boot SBT_GLOBAL_DIR=${WRKDIR}/sbt_global

do-test:
	cd ${WRKSRC} && ${SETENV} JAVA_HOME=${JAVA_HOME} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} SBT_IVY_HOME=${WRKDIR}/repository SBT_BOOT_DIR=${WRKDIR}/sbt_boot SBT_GLOBAL_DIR=${WRKDIR}/sbt_global test

.if ${OPSYS} == FreeBSD
. if ${ARCH} == amd64
PLATFORM_DIR_SUFFIX=	FreeBSD-x86_64
. elif ${ARCH} == i386
PLATFORM_DIR_SUFFIX=	FreeBSD-x86
. elif ${ARCH} == aarch64
PLATFORM_DIR_SUFFIX=	FreeBSD-aarch64
. elif ${ARCH} == powerpc64
PLATFORM_DIR_SUFFIX=	FreeBSD-ppc64
. elif ${ARCH} == powerpc64le
PLATFORM_DIR_SUFFIX=	FreeBSD-ppc64le
.	else
PLATFORM_DIR_SUFFIX=	Default
. endif
.else
PLATFORM_DIR_SUFFIX=	Default
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/snappy-java-*.jar \
		${STAGEDIR}${JAVAJARDIR}/snappy-java.jar
	${INSTALL_LIB} ${WRKSRC}/target/snappy-${PORTVERSION:R}-${PLATFORM_DIR_SUFFIX}/libsnappyjava.so \
		${STAGEDIR}${LOCALBASE}/lib

.include <bsd.port.post.mk>
