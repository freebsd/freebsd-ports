PORTNAME=	tiledb
PORTVERSION=	2.28.1
PORTREVISION=	1
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
		libpng.so:graphics/png \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	capnproto1>=1.0.1:devel/capnproto1 \
		clipp>=1.2.3_1:devel/clipp \
		curl>=7.74.0:ftp/curl \
		liblz4>=1.9.3,1:archivers/liblz4 \
		spdlog>=1.11.0:devel/spdlog \
		zstd>=1.4.8:archivers/zstd

USES=		cmake compiler:c++17-lang localbase:ldflags pkgconfig ssl

CFLAGS_armv6=	-Wno-c++11-narrowing
CFLAGS_armv7=	-Wno-c++11-narrowing
CFLAGS_i386=	-Wno-c++11-narrowing
CFLAGS_powerpc=	-Wno-c++11-narrowing
CMAKE_ARGS=	-DTILEDB_CCACHE=${${CCACHE_ENABLED} == yes :?ON :OFF} \
		-Dlibmagic_DICTIONARY=/usr/share/misc/magic.mgc
CMAKE_OFF=	TILEDB_ALLOW_REGEX_CHAR_PATH \
		TILEDB_ARROW_TESTS \
		TILEDB_ASSERTIONS \
		TILEDB_AZURE \
		TILEDB_EXPERIMENTAL_FEATURES \
		TILEDB_GCS \
		TILEDB_HDFS \
		TILEDB_REMOVE_DEPRECATIONS \
		TILEDB_S3 \
		TILEDB_SANITIZER \
		TILEDB_TESTS \
		TILEDB_TESTS_AWS_S3_CONFIG \
		TILEDB_VCPKG_BASE_TRIPLET \
		TILEDB_VERBOSE \
		TILEDB_WEBP \
		TILEDB_WERROR
CMAKE_ON=	BUILD_SHARED_LIBS \
		CMAKE_DISABLE_FIND_PACKAGE_Doxygen \
		CMAKE_EXPORT_COMPILE_COMMANDS \
		TILEDB_CPP_API \
		TILEDB_DISABLE_AUTO_VCPKG \
		TILEDB_SERIALIZATION \
		TILEDB_STATS \
		TILEDB_TOOLS
LDFLAGS+=	-lfmt

GH_ACCOUNT=	TileDB-Inc
GH_PROJECT=	TileDB
USE_GITHUB=	yes

OPTIONS_DEFINE_amd64=	AVX2
OPTIONS_DEFINE_i386=	AVX2
AVX2_DESC=	AVX2 instructions support

AVX2_CMAKE_BOOL=	COMPILER_SUPPORTS_AVX2

.include <bsd.port.mk>
