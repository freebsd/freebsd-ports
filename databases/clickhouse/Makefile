# Created by: proler@gmail.com
# $FreeBSD$

PORTNAME=	clickhouse
PORTVERSION=	19.11.5.28
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	6
CATEGORIES=	databases

MAINTAINER=	proler@gmail.com
COMMENT=	ClickHouse is a column-oriented database management system

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

BUILD_DEPENDS=	bash:shells/bash \
		sparsehash>=0:devel/sparsehash \
		cctz>=0:devel/cctz \
		rapidjson>=0:devel/rapidjson \
		double-conversion>=0:devel/double-conversion
LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools \
		libodbc.so:databases/unixODBC \
		libltdl.so:devel/libltdl \
		libicudata.so:devel/icu \
		libboost_program_options.so:devel/boost-libs \
		libzookeeper_mt.so:devel/libzookeeper \
		libre2.so:devel/re2 \
		libzstd.so:archivers/zstd \
		liblz4.so:archivers/liblz4 \
		libPocoNet.so:devel/poco \
		libunwind.so:devel/libunwind \
		libcpuid.so:sysutils/libcpuid \
		libbrotlicommon.so:archivers/brotli \
		libsnappy.so:archivers/snappy \
		libprotobuf.so:devel/protobuf \
		libhs.so:devel/hyperscan \
		libgtest.so:devel/googletest \
		libdouble-conversion.so:devel/double-conversion
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		curl:ftp/curl \
		bash:shells/bash \
		expect:lang/expect \
		sudo:security/sudo

USES=		compiler:c++17-lang cmake:insource iconv mysql perl5 python ssl \
		readline shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	dbms/tests/performance/create_benchmark_page.py \
		dbms/tests/clickhouse-test

CMAKE_ARGS=	-DUNBUNDLED=1 \
		-DUSE_STATIC_LIBRARIES=0 \
		-DENABLE_EMBEDDED_COMPILER=0 \
		-DNO_WERROR=1

USERS=		clickhouse
GROUPS=		clickhouse

# The version stamp of libclickhouse.so doesn't always match ${PORTVERSION}
SOVERSION=	${PORTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=		TEST

TEST_CMAKE_BOOL=	ENABLE_TESTS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

# Building with tests fails on 13.0-CURRENT@r346346 amd64
# Clang segfaults with an assertion error - see PR #237619
.if ${PORT_OPTIONS:MTEST} && ${OPSYS} == FreeBSD && ${OSVERSION} >= 1300014
BROKEN=	fails to compile with Clang 8: Assertion error in getZExtValue()
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|;s|/var/log/clickhouse-server|/var/log/clickhouse|;s|/etc/clickhouse-server|${PREFIX}/etc/clickhouse-server|' ${WRKSRC}/dbms/programs/server/config.xml

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/clickhouse-compressor
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} ${STAGEDIR}${PREFIX}/bin/corrector_utf8
	@${RM} -r ${STAGEDIR}${PREFIX}/include/gtest
	@${RM} ${STAGEDIR}${PREFIX}/lib/libgtest*

	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample

	@${MKDIR} ${STAGEDIR}/var/db/clickhouse
	@${MKDIR} ${STAGEDIR}/var/log/clickhouse
	@${MKDIR} ${STAGEDIR}/var/run/clickhouse

do-test-TEST-on:
	cd ${WRKSRC} && ctest -j4 -V

.include <bsd.port.post.mk>
