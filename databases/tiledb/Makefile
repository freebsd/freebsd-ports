# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	tiledb
PORTVERSION=	2.10.1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TileDB array data management

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libcapnp.so:devel/capnproto080 \
		libcurl.so:ftp/curl \
		libfmt.so:devel/libfmt \
		liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	capnproto080>=0.8.0:devel/capnproto080 \
		catch>=2.13.8:devel/catch \
		clipp>=1.2.3:devel/clipp \
		curl>=7.74.0:ftp/curl \
		liblz4>=1.9.3,1:archivers/liblz4 \
		spdlog>=1.9.0:devel/spdlog \
		zstd>=1.4.8:archivers/zstd

USES=		cmake compiler:c++17-lang localbase:ldflags pkgconfig ssl

CFLAGS+=	-DSPDLOG_FMT_EXTERNAL=1
CMAKE_ARGS=	-DCATCH_INCLUDE_DIR=${LOCALBASE}/include/catch2 -Dlibmagic_DICTIONARY=/usr/share/misc/magic.mgc
CMAKE_OFF=	TILEDB_ALLOW_REGEX_CHAR_PATH TILEDB_ARROW_TESTS TILEDB_AZURE TILEDB_CMAKE_IDE TILEDB_FORCE_ALL_DEPS TILEDB_GCS TILEDB_HDFS TILEDB_INSTALL_STATIC_DEPS TILEDB_S3 TILEDB_SKIP_S3AWSSDK_DIR_LENGTH_CHECK TILEDB_SUPERBUILD TILEDB_TESTS_AWS_S3_CONFIG TILEDB_TESTS_ENABLE_REST TILEDB_VERBOSE TILEDB_WERROR
CMAKE_ON=	TILEDB_CCACHE TILEDB_CPP_API TILEDB_LOG_OUTPUT_ON_FAILURE TILEDB_SERIALIZATION TILEDB_STATIC TILEDB_STATS TILEDB_TESTS TILEDB_TOOLS
LDFLAGS+=	-lfmt

GH_ACCOUNT=	TileDB-Inc
GH_PROJECT=	TileDB
USE_GITHUB=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libbz2.so ${STAGEDIR}${PREFIX}/lib/liblz4.so ${STAGEDIR}${PREFIX}/lib/libzstd.so

.include <bsd.port.mk>
