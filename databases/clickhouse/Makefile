# Created by: proler@gmail.com
# $FreeBSD$

PORTNAME=	clickhouse
PORTVERSION=	1.1.54362
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	proler@gmail.com
COMMENT=	ClickHouse is an column-oriented database management system

LICENSE=	APACHE20

BROKEN_FreeBSD_10=	Builds but does not work
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
		libcpuid.so:sysutils/libcpuid \
		libunwind.so:devel/libunwind \
		librdkafka.so:net/librdkafka \
		libgtest.so:devel/googletest

USES=		compiler:c++14-lang cmake iconv mysql python ssl readline shebangfix
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DUNBUNDLED=1 \
		-DUSE_STATIC_LIBRARIES=0 \
		-DNO_WERROR=1 \
		-DENABLE_TESTS=0 \
		-DCXX11_ABI= \
		-DCOMPILER_FLAGS="-DLZ4_DISABLE_DEPRECATE_WARNINGS=1"

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

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000
BUILD_DEPENDS+=	clang50:devel/llvm50
CC=		clang50
CXX=		clang++50
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|;s|/var/log/clickhouse-server|/var/log/clickhouse|;s|/etc/clickhouse-server|${PREFIX}/etc/clickhouse-server|' ${WRKSRC}/dbms/src/Server/config.xml

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/clickhouse-compressor
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} ${STAGEDIR}${PREFIX}/bin/corrector_utf8
	@${RM} -r ${STAGEDIR}${PREFIX}/include/gtest
	@${RM} ${STAGEDIR}${PREFIX}/lib/libgtest*

	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/clickhouse-test/external_dictionaries/dictionary_library/lib*.so

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
