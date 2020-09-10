# Created by: proler@gmail.com
# $FreeBSD$

PORTNAME=	clickhouse
PORTVERSION=	20.7.2.30
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	olevole@olevole.ru
COMMENT=	Fast open-source OLAP database management system

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

BUILD_DEPENDS=	bash:shells/bash \
		clang++90:devel/llvm90
LIB_DEPENDS=	libprotobuf.so:devel/protobuf
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:insource python localbase shebangfix
CXX=		clang++90

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
GH_TUPLE=	\
		CopernicaMarketingSoftware:AMQP-CPP:1c08399:CopernicaMarketingSoftware_AMQP_CPP/contrib/AMQP-CPP \
		apache:arrow:3cbcb7b:apache_arrow/contrib/arrow \
		ClickHouse-Extras:avro:92caca2:ClickHouse_Extras_avro/contrib/avro \
		ClickHouse-Extras:aws-sdk-cpp:17e10c0:ClickHouse_Extras_aws_sdk_cpp/contrib/aws \
		ClickHouse-Extras:aws-c-common:736a82d:ClickHouse_Extras_aws_c_common/contrib/aws-c-common \
		ClickHouse-Extras:aws-c-event-stream:3bc3366:ClickHouse_Extras_aws_c_event_stream/contrib/aws-c-event-stream \
		ClickHouse-Extras:aws-checksums:519d6d9:ClickHouse_Extras_aws_checksums/contrib/aws-checksums \
		ClickHouse-Extras:Turbo-Base64:af9b331:ClickHouse_Extras_Turbo_Base64/contrib/base64 \
		ClickHouse-Extras:boost:a04e72c:ClickHouse_Extras_boost/contrib/boost \
		google:brotli:5805f99:google_brotli/contrib/brotli \
		capnproto:capnproto:a00ccd9:capnproto_capnproto/contrib/capnproto \
		ClickHouse-Extras:cpp-driver:a49b4e0:ClickHouse_Extras_cpp_driver/contrib/cassandra \
		ClickHouse-Extras:cctz:7a2db4e:ClickHouse_Extras_cctz/contrib/cctz \
		mfontanini:cppkafka:b06e64e:mfontanini_cppkafka/contrib/cppkafka \
		curl:curl:3b8bbbb:curl_curl/contrib/curl \
		google:double-conversion:cf2f0f3:google_double_conversion/contrib/double-conversion \
		ClickHouse-Extras:fastops:88752a5:ClickHouse_Extras_fastops/contrib/fastops \
		google:flatbuffers:6df40a2:google_flatbuffers/contrib/flatbuffers \
		fmtlib:fmt:c108ee1:fmtlib_fmt/contrib/fmtlib \
		kthohr:gcem:8d4f1b5:kthohr_gcem/contrib/gcem \
		google:googletest:356f2d2:google_googletest/contrib/googletest \
		ClickHouse-Extras:grpc:8aea4e1:ClickHouse_Extras_grpc/contrib/grpc \
		uber:h3:6cfd649:uber_h3/contrib/h3 \
		ClickHouse-Extras:hyperscan:3907fd0:ClickHouse_Extras_hyperscan/contrib/hyperscan \
		unicode-org:icu:faa2f9f:unicode_org_icu/contrib/icu \
		ClickHouse-Extras:icudata:f020820:ClickHouse_Extras_icudata/contrib/icudata \
		jemalloc:jemalloc:ea6b3e9:jemalloc_jemalloc/contrib/jemalloc \
		ClickHouse-Extras:libc-headers:92c74f9:ClickHouse_Extras_libc_headers/contrib/libc-headers \
		ClickHouse-Extras:libcpuid:8db3b8d:ClickHouse_Extras_libcpuid/contrib/libcpuid \
		ClickHouse-Extras:libcxx:9f71e12:ClickHouse_Extras_libcxx/contrib/libcxx \
		ClickHouse-Extras:libcxxabi:1ebc83a:ClickHouse_Extras_libcxxabi/contrib/libcxxabi \
		ClickHouse-Extras:libgsasl:140fb58:ClickHouse_Extras_libgsasl/contrib/libgsasl \
		ClickHouse-Extras:libhdfs3:1b66657:ClickHouse_Extras_libhdfs3/contrib/libhdfs3 \
		ClickHouse-Extras:librdkafka:2090cbf:ClickHouse_Extras_librdkafka/contrib/librdkafka \
		ClickHouse-Extras:libunwind:27026ef:ClickHouse_Extras_libunwind/contrib/libunwind \
		ClickHouse-Extras:libuv:8443830:ClickHouse_Extras_libuv/contrib/libuv \
		GNOME:libxml2:18890f4:GNOME_libxml2/contrib/libxml2 \
		ClickHouse-Extras:llvm:3d6c7e9:ClickHouse_Extras_llvm/contrib/llvm \
		lz4:lz4:f39b79f:lz4_lz4/contrib/lz4 \
		ClickHouse-Extras:mariadb-connector-c:3f512fe:ClickHouse_Extras_mariadb_connector_c/contrib/mariadb-connector-c \
		msgpack:msgpack-c:4668426:msgpack_msgpack_c/contrib/msgpack-c \
		openldap:openldap:34b9ba9:openldap_openldap/contrib/openldap \
		ClickHouse-Extras:openssl:07e9623:ClickHouse_Extras_openssl/contrib/openssl \
		apache:orc:5981208:apache_orc/contrib/orc \
		ClickHouse-Extras:poco:74c9344:ClickHouse_Extras_poco/contrib/poco \
		ClickHouse-Extras:protobuf:d6a10dd:ClickHouse_Extras_protobuf/contrib/protobuf \
		ClickHouse-Extras:rapidjson:c4ef90c:ClickHouse_Extras_rapidjson/contrib/rapidjson \
		google:re2:7cf8b88:google_re2/contrib/re2 \
		ClickHouse-Extras:replxx:94b1f56:ClickHouse_Extras_replxx/contrib/replxx \
		ClickHouse-Extras:ryu:5b4a853:ClickHouse_Extras_ryu/contrib/ryu \
		ClickHouse-Extras:sentry-native:94644e9:ClickHouse_Extras_sentry_native/contrib/sentry-native \
		ClickHouse-Extras:simdjson:3190d66:ClickHouse_Extras_simdjson/contrib/simdjson \
		google:snappy:3f194ac:google_snappy/contrib/snappy \
		sparsehash:sparsehash-c11:cf0bffa:sparsehash_sparsehash_c11/contrib/sparsehash-c11 \
		kthohr:stats:b6dd459:kthohr_stats/contrib/stats \
		apache:thrift:010ccf0:apache_thrift/contrib/thrift \
		ClickHouse-Extras:UnixODBC:b0ad30f:ClickHouse_Extras_UnixODBC/contrib/unixodbc \
		ClickHouse-Extras:zlib-ng:bba56a7:ClickHouse_Extras_zlib_ng/contrib/zlib-ng \
		facebook:zstd:10f0e69:facebook_zstd/contrib/zstd \
		apache:parquet-testing:46c9e97:apache_parquet_testing/contrib/arrow/cpp/submodules/parquet-testing \
		apache:arrow-testing:3772a1b:apache_arrow_testing/contrib/arrow/testing \
		hillbig:esaxx:ca7cb33:hillbig_esaxx/contrib/brotli/research/esaxx \
		y-256:libdivsufsort:5f60d6f:y_256_libdivsufsort/contrib/brotli/research/libdivsufsort \
		catchorg:Catch2:d2d8455:catchorg_Catch2/contrib/cppkafka/third_party/Catch2 \
		c-ares:c-ares:e982924:c_ares_c_ares/contrib/grpc/third_party/cares/cares \
		boostorg:predef:560ff52:boostorg_predef/contrib/msgpack-c/external/boost/predef \
		boostorg:preprocessor:56090c5:boostorg_preprocessor/contrib/msgpack-c/external/boost/preprocessor \
		google:googletest:ba96d0b:google_googletest/contrib/rapidjson/thirdparty/gtest \
		jarro2783:cxxopts:794c975:jarro2783_cxxopts/contrib/simdjson/dependencies/cxxopts

SHEBANG_LANG=		expect
expect_OLD_CMD=		/usr/bin/expect
expect_CMD=		${LOCALBASE}/bin/expect

USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	src/Storages/System/StorageSystemLicenses.sh \
		tests/clickhouse-test \
		tests/queries/0_stateless/00921_datetime64_compatibility.python \
		tests/queries/0_stateless/00960_live_view_watch_events_live.py \
		tests/queries/0_stateless/00962_temporary_live_view_watch_live.py \
		tests/queries/0_stateless/00963_temporary_live_view_watch_live_timeout.py.disabled \
		tests/queries/0_stateless/00964_live_view_watch_events_heartbeat.py \
		tests/queries/0_stateless/00965_live_view_watch_heartbeat.py \
		tests/queries/0_stateless/00966_live_view_watch_events_http.py \
		tests/queries/0_stateless/00967_live_view_watch_http.py \
		tests/queries/0_stateless/00970_live_view_watch_events_http_heartbeat.py \
		tests/queries/0_stateless/00971_live_view_watch_http_heartbeat.py \
		tests/queries/0_stateless/00979_live_view_watch_continuous_aggregates.py \
		tests/queries/0_stateless/00979_live_view_watch_live_moving_avg.py \
		tests/queries/0_stateless/00979_live_view_watch_live_with_subquery.py \
		tests/queries/0_stateless/00979_live_view_watch_live.py \
		tests/queries/0_stateless/00990_hasToken.python \
		tests/queries/0_stateless/00991_live_view_watch_http.python \
		tests/queries/0_stateless/01246_insert_into_watch_live_view.py \
		tests/queries/0_stateless/01293_client_interactive_vertical_multiline.sh \
		tests/queries/0_stateless/01293_client_interactive_vertical_singleline.sh \
		tests/queries/0_stateless/01300_client_save_history_when_terminated.sh \
		tests/queries/0_stateless/01370_client_autocomplete_word_break_characters.sh \
		utils/build/build_debian_shared.sh \
		utils/build/build_debian_unbundled_split.sh \
		utils/build/build_debian_unbundled.sh \
		utils/build/build_minimal.sh \
		utils/clickhouse-docker \
		utils/generate-ya-make/generate-ya-make.sh \
		utils/list-licenses/list-licenses.sh \
		utils/list-versions/list-versions.sh \
		utils/simple-backport/backport.sh \
		utils/simple-backport/changelog.sh

CMAKE_ARGS=	-DNO_WERROR=1 \
		-DUSE_INTERNAL_PROTOBUF_LIBRARY=FALSE

USERS=		clickhouse
GROUPS=		clickhouse

# The version stamp of libclickhouse.so doesn't always match ${PORTVERSION}
SOVERSION=	${PORTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=		TEST
TEST_RUN_DEPENDS+=	expect>0:lang/expect

TEST_CMAKE_BOOL=	ENABLE_TESTS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" MODERN_LIMITS="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|;s|/var/log/clickhouse-server|/var/log/clickhouse|;s|/etc/clickhouse-server|${PREFIX}/etc/clickhouse-server|' ${WRKSRC}/programs/server/config.xml

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/clickhouse-compressor
	@${RM} ${STAGEDIR}${PREFIX}/bin/config-processor
	@${RM} ${STAGEDIR}${PREFIX}/bin/corrector_utf8
	@${RM} -r ${STAGEDIR}${PREFIX}/include/gtest
	@${RM} ${STAGEDIR}${PREFIX}/lib/libgtest*
	@${RM} ${STAGEDIR}${PREFIX}/lib/libcxx.a
	@${RM} ${STAGEDIR}${PREFIX}/lib/libcxxabi.a
	@${RM} ${STAGEDIR}${PREFIX}/lib/libunwind.a
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-client/config.xml.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/config.xml.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml \
		${STAGEDIR}${PREFIX}/etc/clickhouse-server/users.xml.sample

	@${MKDIR} ${STAGEDIR}/var/db/clickhouse
	@${MKDIR} ${STAGEDIR}/var/log/clickhouse
	@${MKDIR} ${STAGEDIR}/var/run/clickhouse

do-test-TEST-on:
	cd ${WRKSRC} && ctest -j4 -V

.include <bsd.port.post.mk>
