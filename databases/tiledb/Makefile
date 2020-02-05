# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiledb
PORTVERSION=	1.7.5
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	TileDB array data management

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		liblz4.so:archivers/liblz4 \
		libtbb.so:devel/tbb \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	catch>=0:devel/catch \
		clipp>=0:devel/clipp \
		spdlog>=1.4:devel/spdlog

USES=		cmake compiler:c++11-lang localbase:ldflags ssl

CFLAGS+=	-DSPDLOG_FMT_EXTERNAL=1
CMAKE_ARGS=	-DCATCH_INCLUDE_DIR=${LOCALBASE}/include/catch2
CMAKE_OFF=	TILEDB_CMAKE_IDE TILEDB_FORCE_ALL_DEPS TILEDB_HDFS TILEDB_S3 TILEDB_SUPERBUILD TILEDB_TESTS_AWS_S3_CONFIG TILEDB_VERBOSE TILEDB_WERROR
CMAKE_ON=	TILEDB_CPP_API TILEDB_STATIC TILEDB_STATS TILEDB_TBB TILEDB_TBB_SHARED TILEDB_TESTS TILEDB_TOOLS
LDFLAGS+=	-lfmt

GH_ACCOUNT=	TileDB-Inc
GH_PROJECT=	TileDB
USE_GITHUB=	yes

.include <bsd.port.mk>
