# Note to committers:
# With each version update, a new maven repository must be created
# and distributed so build is repeatable and cluster-safe.

PORTNAME=	snappy
PORTVERSION=	1.1.7.5
CATEGORIES=	archivers java
MASTER_SITES=	LOCAL/pi:repo
PKGNAMESUFFIX=	java
DISTFILES+=	${PORTNAME}-${PKGNAMESUFFIX}-repository-${PORTVERSION}${EXTRACT_SUFX}:repo
EXTRACT_ONLY=	${DISTFILE_DEFAULT} \
		${PORTNAME}-${PKGNAMESUFFIX}-repository-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	language.devel@gmail.com
COMMENT=	Fast compressor/decompressor library

LICENSE=	APACHE20

BROKEN_armv6=		fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_armv7=		fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes

BUILD_DEPENDS=	cmake:devel/cmake \
		sbt:devel/sbt

USES=		gmake
USE_JAVA=	yes
USE_LDCONFIG=	yes
MAKE_ARGS+=	CXX="${CXX}"
TEST_TARGET=	test
BITSHUFFLE_V=	0.3.2

USE_GITHUB=	yes
GH_ACCOUNT=	xerial \
		google:google \
		kiyo-masui:masui
GH_PROJECT=	snappy-java \
		snappy:google \
		bitshuffle:masui
GH_TAGNAME=	${PORTVERSION} \
		${PORTVERSION:R}:google \
		${BITSHUFFLE_V}:masui

PLIST_FILES=	${JAVAJARDIR}/snappy-java.jar lib/libsnappyjava.so

post-extract:
	@${MKDIR} ${WRKSRC}/target
	@${RM} ${WRKSRC}/sbt
	@${CP} ${DISTDIR}/${DISTFILE_google} ${WRKSRC}/target/snappy-${PORTVERSION:R}${EXTRACT_SUFX}
	@${CP} ${DISTDIR}/${DISTFILE_masui} ${WRKSRC}/target/bitshuffle-${BITSHUFFLE_V}${EXTRACT_SUFX}

do-build:
	cd ${WRKSRC} && ${SETENV} JAVA_HOME=${JAVA_HOME} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} SBT_IVY_HOME=${WRKDIR}/repository SBT_BOOT_DIR=${WRKDIR}/sbt_boot SBT_GLOBAL_DIR=${WRKDIR}/sbt_global

do-test:
	cd ${WRKSRC} && ${SETENV} JAVA_HOME=${JAVA_HOME} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} SBT_IVY_HOME=${WRKDIR}/repository SBT_BOOT_DIR=${WRKDIR}/sbt_boot SBT_GLOBAL_DIR=${WRKDIR}/sbt_global test

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
.	if ${ARCH} == amd64
PLATFORM_DIR_SUFFIX=	FreeBSD-x86_64
.	elif ${ARCH} == i386
PLATFORM_DIR_SUFFIX=	FreeBSD-x86
.	elif ${ARCH} == aarch64
PLATFORM_DIR_SUFFIX=	FreeBSD-aarch64
.	elif ${ARCH} == powerpc64
PLATFORM_DIR_SUFFIX=	FreeBSD-ppc64
.	elif ${ARCH} == powerpc64le
PLATFORM_DIR_SUFFIX=	FreeBSD-ppc64le
.	else
PLATFORM_DIR_SUFFIX=	Default
.	endif
.else
PLATFORM_DIR_SUFFIX=	Default
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/target/snappy-java-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/snappy-java.jar
	${INSTALL_LIB} ${WRKSRC}/target/snappy-${PORTVERSION:R}-${PLATFORM_DIR_SUFFIX}/libsnappyjava.so \
		${STAGEDIR}${LOCALBASE}/lib

.include <bsd.port.post.mk>
