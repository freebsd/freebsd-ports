PORTNAME=		clickhouse-cpp
DISTVERSIONPREFIX=	v
DISTVERSION=		2.6.0
CATEGORIES=		databases devel

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	C++ client for ClickHouse
WWW=		https://clickhouse.com/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	only supported on aarch64 and amd64

LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd

USES=		cmake 
USE_GITHUB=	yes
GH_ACCOUNT=	clickhouse

CMAKE_ON=	WITH_OPENSSL \
		WITH_SYSTEM_ABSEIL \
		WITH_SYSTEM_LZ4 \
		WITH_SYSTEM_ZSTD

OPTIONS_DEFINE=		TEST
OPTIONS_SUB=		yes

TEST_RUN_DEPENDS=	expect>0:lang/expect
TEST_CMAKE_BOOL=	ENABLE_TESTS

.include <bsd.port.mk>
