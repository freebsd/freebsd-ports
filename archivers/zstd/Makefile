PORTNAME=	zstd
PORTVERSION=	1.5.7
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/facebook/zstd/releases/download/v${PORTVERSION}/

# update manpages to v1.5.7, were missed in the release,
# see https://github.com/facebook/zstd/releases/tag/v1.5.7
PATCH_SITES=	https://github.com/facebook/zstd/commit/
PATCHFILES=	6af3842118ea5325480b403213b2a9fbed3d3d74.diff:-p1 # v1.5.7 manpages

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast real-time compression algorithm
WWW=		https://facebook.github.io/zstd/ \
		https://github.com/facebook/zstd

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USES=		cpe gmake localbase:ldflags tar:zst

ALL_TARGET=	default
BINARY_ALIAS=	gmd5sum=md5sum
CFLAGS+=	-fPIC
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		V=1
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	BUILD_TYPE=${BUILD_TYPE:tl} PORTVERSION=${PORTVERSION}
SUB_FILES=	zstdConfigVersion.cmake zstdTargets-BUILD_TYPE.cmake
SUB_LIST=	BUILD_TYPE_CAPS=${BUILD_TYPE:tu} BUILD_TYPE_MIXED=${BUILD_TYPE} PORTVERSION=${PORTVERSION}

CPE_VENDOR=	facebook
CPE_PRODUCT=	zstandard

BUILD_TYPE=	${defined(WITH_DEBUG) :?Debug:Release}

OPTIONS_DEFINE=	LZ4 OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=LZ4

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_MAKE_ARGS=		HAVE_LZ4=1
LZ4_MAKE_ARGS_OFF=	HAVE_LZ4=0
OPTIMIZED_CFLAGS_VARS=	CFLAGS+=-O3

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cmake/zstd
	${INSTALL_DATA} ${FILESDIR}/zstdConfig.cmake ${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdConfig.cmake
	${INSTALL_DATA} ${WRKDIR}/zstdConfigVersion.cmake ${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdConfigVersion.cmake
	${INSTALL_DATA} ${WRKDIR}/zstdTargets-BUILD_TYPE.cmake ${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdTargets-${BUILD_TYPE:tl}.cmake
	${INSTALL_DATA} ${FILESDIR}/zstdTargets.cmake ${STAGEDIR}${PREFIX}/lib/cmake/zstd/zstdTargets.cmake
	${LN} -s zstd.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/zstdmt.1.gz

.include <bsd.port.mk>
