PORTNAME=	zstd
DISTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/facebook/zstd/releases/download/v${DISTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast real-time compression algorithm
WWW=		https://facebook.github.io/zstd/ \
		https://github.com/facebook/zstd

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		gmake localbase:ldflags tar:zst
USE_LDCONFIG=	yes

ALL_TARGET=	default
TEST_TARGET=	shortest
BINARY_ALIAS=	gmd5sum=md5sum
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		V=1

.if defined(WITH_DEBUG)
BUILD_TYPE=     Debug
.else
BUILD_TYPE=     Release
.endif

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		BUILD_TYPE=${BUILD_TYPE:tl}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_VARS=	CFLAGS+=-O3

post-build:
	cd ${BUILD_WRKSRC}/programs && ${DO_MAKE_BUILD} zstd-frugal

post-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/programs/zstd-frugal ${STAGEDIR}${PREFIX}/bin/zstd-frugal
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/zstd
	${INSTALL_DATA} ${PATCHDIR}/zstdConfig.cmake.in \
		${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdConfig.cmake
	${INSTALL_DATA} ${PATCHDIR}/zstdConfigVersion.cmake.in \
		${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdConfigVersion.cmake
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
		${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdConfigVersion.cmake
	${INSTALL_DATA} ${PATCHDIR}/zstdTargets-BUILD_TYPE.cmake.in \
		${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdTargets-${BUILD_TYPE:tl}.cmake
	@${REINPLACE_CMD} -e 's|%%BUILD_TYPE_CAPS%%|${BUILD_TYPE:tu}|g' \
		${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdTargets-${BUILD_TYPE:tl}.cmake
	@${REINPLACE_CMD} -e 's|%%BUILD_TYPE_MIXED%%|${BUILD_TYPE}|g' \
		${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdTargets-${BUILD_TYPE:tl}.cmake
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
		${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdTargets-${BUILD_TYPE:tl}.cmake
	${INSTALL_DATA} ${PATCHDIR}/zstdTargets.cmake.in \
		${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdTargets.cmake
	${RM} ${STAGEDIR}${PREFIX}/lib/cmake/zstd/*.bak
	${RLN} zstd.1.gz ${STAGEDIR}${PREFIX}/man/man1/zstdmt.1.gz

.include <bsd.port.mk>
