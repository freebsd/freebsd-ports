PORTNAME=	tiledb
PORTVERSION=	2.18.3
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TileDB array data management
WWW=		https://tiledb.com/ \
		https://github.com/TileDB-Inc/TileDB

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libcapnp.so:devel/capnproto1 \
		libcurl.so:ftp/curl \
		libfmt.so:devel/libfmt \
		liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	capnproto1>=1.0.1:devel/capnproto1 \
		catch2>=3.1:devel/catch2 \
		clipp>=1.2.3_1:devel/clipp \
		curl>=7.74.0:ftp/curl \
		liblz4>=1.9.3,1:archivers/liblz4 \
		spdlog>=1.11.0:devel/spdlog \
		zstd>=1.4.8:archivers/zstd

USES=		cmake compiler:c++17-lang localbase:ldflags pkgconfig ssl

CFLAGS+=	-DSPDLOG_FMT_EXTERNAL=1
CFLAGS_armv6+=	-Wno-c++11-narrowing
CFLAGS_armv7+=	-Wno-c++11-narrowing
CFLAGS_i386+=	-Wno-c++11-narrowing
CMAKE_ARGS=	-DCATCH_INCLUDE_DIR=${LOCALBASE}/include/catch2 \
		-DFREEBSD_OPENSSLBASE=${OPENSSLBASE} \
		-Dlibmagic_DICTIONARY=/usr/share/misc/magic.mgc
CMAKE_OFF=	TILEDB_ABSEIL \
		TILEDB_ALLOW_REGEX_CHAR_PATH \
		TILEDB_ARROW_TESTS \
		TILEDB_ASSERTIONS \
		TILEDB_AZURE \
		TILEDB_CMAKE_IDE \
		TILEDB_CRC32 \
		TILEDB_EXPERIMENTAL_FEATURES \
		TILEDB_FORCE_ALL_DEPS \
		TILEDB_GCS \
		TILEDB_HDFS \
		TILEDB_INSTALL_STATIC_DEPS \
		TILEDB_S3 \
		TILEDB_SKIP_S3AWSSDK_DIR_LENGTH_CHECK \
		TILEDB_SUPERBUILD \
		TILEDB_TESTS \
		TILEDB_VCPKG \
		TILEDB_VERBOSE \
		TILEDB_WEBP \
		TILEDB_WERROR
CMAKE_ON=	CMAKE_EXPORT_COMPILE_COMMANDS \
		TILEDB_CCACHE \
		TILEDB_CPP_API \
		TILEDB_LOG_OUTPUT_ON_FAILURE \
		TILEDB_SERIALIZATION \
		TILEDB_STATIC \
		TILEDB_STATS \
		TILEDB_TOOLS
LDFLAGS+=	-lfmt

GH_ACCOUNT=	TileDB-Inc
GH_PROJECT=	TileDB
USE_GITHUB=	yes

OPTIONS_DEFINE=	AVX2
OPTIONS_DEFAULT=AVX2
AVX2_DESC=	AVX2 instructions support

AVX2_CMAKE_BOOL=	COMPILER_SUPPORTS_AVX2

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libbz2.so ${STAGEDIR}${PREFIX}/lib/liblz4.so ${STAGEDIR}${PREFIX}/lib/libzstd.so

.include <bsd.port.mk>
