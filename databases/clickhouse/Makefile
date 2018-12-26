# Created by: proler@gmail.com
# $FreeBSD$

PORTNAME=	clickhouse
PORTVERSION=	18.14.18
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	proler@gmail.com
COMMENT=	ClickHouse is a column-oriented database management system

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

BUILD_DEPENDS=	bash:shells/bash \
		sparsehash>=0:devel/sparsehash \
		cctz>=0:devel/cctz \
		libdouble-conversion>=0:devel/libdouble-conversion
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
		librdkafka.so:net/librdkafka \
		libcpuid.so:sysutils/libcpuid \
		libgtest.so:devel/googletest

USES=		compiler:c++14-lang cmake:insource iconv mysql ssl readline shebangfix
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DUNBUNDLED=1 \
		-DUSE_STATIC_LIBRARIES=0 \
		-DNO_WERROR=1 \
		-DENABLE_TESTS=0

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	dbms/tests/performance/create_benchmark_page.py \
		dbms/tests/external_dictionaries/generate_and_test.py \
		dbms/tests/external_dictionaries/http_server.py \
		dbms/tests/clickhouse-test

USERS=		clickhouse
GROUPS=		clickhouse

SOVERSION=	${PORTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=		TEST
OPTIONS_DEFAULT=	TEST
OPTIONS_SUB=	yes
TEST_DESC=	Install script clickhouse-test and test queries data
TEST_USES=	python perl5
TEST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		curl:ftp/curl \
		bash:shells/bash \
		expect:lang/expect \
		sudo:security/sudo

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
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

	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/clickhouse-test/external_dictionaries/dictionary_library/*.so

	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample

	@${MKDIR} ${STAGEDIR}/var/db/clickhouse
	@${MKDIR} ${STAGEDIR}/var/log/clickhouse
	@${MKDIR} ${STAGEDIR}/var/run/clickhouse

.include <bsd.port.post.mk>
