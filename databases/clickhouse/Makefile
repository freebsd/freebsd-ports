# Created by: proler@gmail.com

PORTNAME=	clickhouse
PORTVERSION=	21.3.6.55
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-lts
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	olevole@olevole.ru
COMMENT=	Fast open-source OLAP database management system

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

BUILD_DEPENDS=	bash:shells/bash \
		clang++11:devel/llvm11
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:insource localbase python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
GH_TUPLE=	ClickHouse-Extras:AMQP-CPP:03781aa:ClickHouse_Extras_AMQP_CPP/contrib/AMQP-CPP \
		ClickHouse-Extras:NuRaft:9a0d78d:ClickHouse_Extras_NuRaft/contrib/NuRaft \
		ClickHouse-Extras:abseil-cpp:4f3b686:ClickHouse_Extras_abseil_cpp/contrib/abseil-cpp \
		ClickHouse-Extras:antlr4-runtime:a2fa7b7:ClickHouse_Extras_antlr4_runtime/contrib/antlr4-runtime \
		ClickHouse-Extras:arrow:744bdfe:ClickHouse_Extras_arrow/contrib/arrow \
		ClickHouse-Extras:avro:92caca2:ClickHouse_Extras_avro/contrib/avro \
		ClickHouse-Extras:aws-sdk-cpp:7d48b2c:ClickHouse_Extras_aws_sdk_cpp/contrib/aws \
		ClickHouse-Extras:aws-c-common:736a82d:ClickHouse_Extras_aws_c_common/contrib/aws-c-common \
		ClickHouse-Extras:aws-c-event-stream:3bc3366:ClickHouse_Extras_aws_c_event_stream/contrib/aws-c-event-stream \
		ClickHouse-Extras:aws-checksums:519d6d9:ClickHouse_Extras_aws_checksums/contrib/aws-checksums \
		ClickHouse-Extras:Turbo-Base64:af9b331:ClickHouse_Extras_Turbo_Base64/contrib/base64 \
		ClickHouse-Extras:boost:ee24fa5:ClickHouse_Extras_boost/contrib/boost \
		ClickHouse-Extras:boringssl:8b2bf91:ClickHouse_Extras_boringssl/contrib/boringssl \
		google:brotli:63be8a9:google_brotli/contrib/brotli \
		capnproto:capnproto:a00ccd9:capnproto_capnproto/contrib/capnproto \
		ClickHouse-Extras:cpp-driver:b446d7e:ClickHouse_Extras_cpp_driver/contrib/cassandra \
		ClickHouse-Extras:cctz:c0f1bcb:ClickHouse_Extras_cctz/contrib/cctz \
		mfontanini:cppkafka:b06e64e:mfontanini_cppkafka/contrib/cppkafka \
		RoaringBitmap:CRoaring:d840293:RoaringBitmap_CRoaring/contrib/croaring \
		curl:curl:3b8bbbb:curl_curl/contrib/curl \
		ClickHouse-Extras:cyrus-sasl:9995bf9:ClickHouse_Extras_cyrus_sasl/contrib/cyrus-sasl \
		google:double-conversion:cf2f0f3:google_double_conversion/contrib/double-conversion \
		ClickHouse-Extras:dragonbox:923705a:ClickHouse_Extras_dragonbox/contrib/dragonbox \
		fastfloat:fast_float:7eae925:fastfloat_fast_float/contrib/fast_float \
		ClickHouse-Extras:fastops:88752a5:ClickHouse_Extras_fastops/contrib/fastops \
		google:flatbuffers:6df40a2:google_flatbuffers/contrib/flatbuffers \
		fmtlib:fmt:c108ee1:fmtlib_fmt/contrib/fmtlib \
		kthohr:gcem:8d4f1b5:kthohr_gcem/contrib/gcem \
		google:googletest:356f2d2:google_googletest/contrib/googletest \
		ClickHouse-Extras:grpc:7436366:ClickHouse_Extras_grpc/contrib/grpc \
		ClickHouse-Extras:h3:e209086:ClickHouse_Extras_h3/contrib/h3 \
		ClickHouse-Extras:hyperscan:e9f08df:ClickHouse_Extras_hyperscan/contrib/hyperscan \
		unicode-org:icu:faa2f9f:unicode_org_icu/contrib/icu \
		ClickHouse-Extras:icudata:f020820:ClickHouse_Extras_icudata/contrib/icudata \
		ClickHouse-Extras:jemalloc:e6891d9:ClickHouse_Extras_jemalloc/contrib/jemalloc \
		ClickHouse-Extras:krb5:5149dea:ClickHouse_Extras_krb5/contrib/krb5 \
		ClickHouse-Extras:libc-headers:a720b71:ClickHouse_Extras_libc_headers/contrib/libc-headers \
		ClickHouse-Extras:libcpuid:8db3b8d:ClickHouse_Extras_libcpuid/contrib/libcpuid \
		ClickHouse-Extras:libcxx:8b80a15:ClickHouse_Extras_libcxx/contrib/libcxx \
		ClickHouse-Extras:libcxxabi:df8f1e7:ClickHouse_Extras_libcxxabi/contrib/libcxxabi \
		ClickHouse-Extras:libgsasl:383ee28:ClickHouse_Extras_libgsasl/contrib/libgsasl \
		ClickHouse-Extras:libhdfs3:095b9d4:ClickHouse_Extras_libhdfs3/contrib/libhdfs3 \
		ClickHouse-Extras:libpq:1f9c286:ClickHouse_Extras_libpq/contrib/libpq \
		jtv:libpqxx:58d2a02:jtv_libpqxx/contrib/libpqxx \
		ClickHouse-Extras:librdkafka:cf11d0a:ClickHouse_Extras_librdkafka/contrib/librdkafka \
		ClickHouse-Extras:libunwind:8fe25d7:ClickHouse_Extras_libunwind/contrib/libunwind \
		ClickHouse-Extras:libuv:e2e9b7e:ClickHouse_Extras_libuv/contrib/libuv \
		GNOME:libxml2:18890f4:GNOME_libxml2/contrib/libxml2 \
		ClickHouse-Extras:llvm:8f24d50:ClickHouse_Extras_llvm/contrib/llvm \
		lz4:lz4:f39b79f:lz4_lz4/contrib/lz4 \
		ClickHouse-Extras:mariadb-connector-c:21f451d:ClickHouse_Extras_mariadb_connector_c/contrib/mariadb-connector-c \
		danlark1:miniselect:be0af6b:danlark1_miniselect/contrib/miniselect \
		msgpack:msgpack-c:4668426:msgpack_msgpack_c/contrib/msgpack-c \
		ClickHouse-Extras:openldap:0208811:ClickHouse_Extras_openldap/contrib/openldap \
		apache:orc:5981208:apache_orc/contrib/orc \
		ClickHouse-Extras:poco:c55b91f:ClickHouse_Extras_poco/contrib/poco \
		ClickHouse-Extras:protobuf:73b1281:ClickHouse_Extras_protobuf/contrib/protobuf \
		ClickHouse-Extras:rapidjson:c4ef90c:ClickHouse_Extras_rapidjson/contrib/rapidjson \
		google:re2:7cf8b88:google_re2/contrib/re2 \
		ClickHouse-Extras:replxx:cdb6e3f:ClickHouse_Extras_replxx/contrib/replxx \
		ClickHouse-Extras:rocksdb:54a0dec:ClickHouse_Extras_rocksdb/contrib/rocksdb \
		ClickHouse-Extras:sentry-native:94644e9:ClickHouse_Extras_sentry_native/contrib/sentry-native \
		ClickHouse-Extras:simdjson:3190d66:ClickHouse_Extras_simdjson/contrib/simdjson \
		google:snappy:3f194ac:google_snappy/contrib/snappy \
		sparsehash:sparsehash-c11:cf0bffa:sparsehash_sparsehash_c11/contrib/sparsehash-c11 \
		kthohr:stats:b6dd459:kthohr_stats/contrib/stats \
		apache:thrift:010ccf0:apache_thrift/contrib/thrift \
		ClickHouse-Extras:UnixODBC:b0ad30f:ClickHouse_Extras_UnixODBC/contrib/unixodbc \
		xz-mirror:xz:869b9d1:xz_mirror_xz/contrib/xz \
		ClickHouse-Extras:zlib-ng:6fd1846:ClickHouse_Extras_zlib_ng/contrib/zlib-ng \
		facebook:zstd:10f0e69:facebook_zstd/contrib/zstd \
		apache:parquet-testing:d914f9d:apache_parquet_testing/contrib/arrow/cpp/submodules/parquet-testing \
		apache:arrow-testing:860376d:apache_arrow_testing/contrib/arrow/testing \
		hillbig:esaxx:ca7cb33:hillbig_esaxx/contrib/brotli/research/esaxx \
		y-256:libdivsufsort:5f60d6f:y_256_libdivsufsort/contrib/brotli/research/libdivsufsort \
		catchorg:Catch2:d2d8455:catchorg_Catch2/contrib/cppkafka/third_party/Catch2 \
		c-ares:c-ares:e982924:c_ares_c_ares/contrib/grpc/third_party/cares/cares \
		boostorg:predef:560ff52:boostorg_predef/contrib/msgpack-c/external/boost/predef \
		boostorg:preprocessor:56090c5:boostorg_preprocessor/contrib/msgpack-c/external/boost/preprocessor \
		google:googletest:ba96d0b:google_googletest/contrib/rapidjson/thirdparty/gtest \
		jarro2783:cxxopts:794c975:jarro2783_cxxopts/contrib/simdjson/dependencies/cxxopts

USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	src/Storages/System/StorageSystemLicenses.sh \
		tests/clickhouse-test tests/config/install.sh \
		tests/queries/0_stateless/00960_live_view_watch_events_live.py \
		tests/queries/0_stateless/00962_live_view_periodic_refresh.py \
		tests/queries/0_stateless/00962_live_view_periodic_refresh_and_timeout.py \
		tests/queries/0_stateless/00962_live_view_periodic_refresh_dictionary.py \
		tests/queries/0_stateless/00962_temporary_live_view_watch_live.py \
		tests/queries/0_stateless/00963_temporary_live_view_watch_live_timeout.py.disabled \
		tests/queries/0_stateless/00964_live_view_watch_events_heartbeat.py \
		tests/queries/0_stateless/00965_live_view_watch_heartbeat.py \
		tests/queries/0_stateless/00966_live_view_watch_events_http.py \
		tests/queries/0_stateless/00967_live_view_watch_http.py \
		tests/queries/0_stateless/00970_live_view_watch_events_http_heartbeat.py \
		tests/queries/0_stateless/00971_live_view_watch_http_heartbeat.py \
		tests/queries/0_stateless/00979_live_view_watch_continuous_aggregates.py \
		tests/queries/0_stateless/00979_live_view_watch_live.py \
		tests/queries/0_stateless/00979_live_view_watch_live_moving_avg.py.disabled \
		tests/queries/0_stateless/00979_live_view_watch_live_with_subquery.py \
		tests/queries/0_stateless/00991_live_view_watch_http.python \
		tests/queries/0_stateless/01176_mysql_client_interactive.expect \
		tests/queries/0_stateless/01179_insert_values_semicolon.expect \
		tests/queries/0_stateless/01180_client_syntax_errors.expect \
		tests/queries/0_stateless/01246_insert_into_watch_live_view.py \
		tests/queries/0_stateless/01293_client_interactive_vertical_multiline.expect \
		tests/queries/0_stateless/01293_client_interactive_vertical_singleline.expect \
		tests/queries/0_stateless/01300_client_save_history_when_terminated.expect \
		tests/queries/0_stateless/01370_client_autocomplete_word_break_characters.expect \
		tests/queries/0_stateless/01520_client_print_query_id.expect \
		tests/queries/0_stateless/01526_client_start_and_exit.expect-not-a-test-case \
		tests/queries/0_stateless/01565_reconnect_after_client_error.expect \
		tests/queries/0_stateless/01599_multiline_input_and_singleline_comments.sh \
		tests/queries/0_stateless/01610_client_spawn_editor.sh \
		tests/queries/0_stateless/helpers/00900_parquet_create_table_columns.py \
		tests/queries/0_stateless/helpers/client.py \
		tests/queries/0_stateless/helpers/httpclient.py \
		tests/queries/0_stateless/helpers/httpechoserver.py \
		tests/queries/0_stateless/helpers/httpexpect.py \
		tests/queries/0_stateless/helpers/protobuf_length_delimited_encoder.py \
		tests/queries/0_stateless/helpers/pure_http_client.py \
		tests/queries/0_stateless/helpers/shell.py \
		tests/queries/0_stateless/helpers/uexpect.py \
		utils/build/build_debian.sh utils/build/build_debian_shared.sh \
		utils/build/build_debian_unbundled.sh \
		utils/build/build_debian_unbundled_split.sh \
		utils/build/build_freebsd.sh utils/build/build_macos.sh \
		utils/build/build_minimal.sh utils/build/build_no_submodules.sh \
		utils/check-style/check-duplicate-includes.sh \
		utils/check-style/check-ungrouped-includes.sh \
		utils/check-style/format.sh utils/check-style/shellcheck-run.sh \
		utils/ci/build-clang-from-sources.sh \
		utils/ci/build-debian-packages.sh \
		utils/ci/build-gcc-from-sources.sh utils/ci/build-normal.sh \
		utils/ci/check-docker.sh utils/ci/check-syntax.sh \
		utils/ci/check-tzdata-updates.sh \
		utils/ci/create-sources-tarball.sh \
		utils/ci/docker-multiarch/update.sh utils/ci/get-sources.sh \
		utils/ci/install-compiler-from-packages.sh \
		utils/ci/install-compiler-from-sources.sh \
		utils/ci/install-libraries.sh utils/ci/install-os-packages.sh \
		utils/ci/jobs/quick-build/run.sh \
		utils/ci/prepare-docker-image-ubuntu.sh \
		utils/ci/prepare-toolchain.sh \
		utils/ci/prepare-vagrant-image-freebsd.sh \
		utils/ci/run-clickhouse-from-binaries.sh \
		utils/ci/run-with-docker.sh utils/ci/run-with-vagrant.sh \
		utils/clickhouse-docker utils/compressor/test.sh \
		utils/durability-test/durability-test.sh \
		utils/durability-test/install.sh \
		utils/generate-ya-make/generate-ya-make.sh \
		utils/link-validate/link-validate.sh \
		utils/list-licenses/list-licenses.sh \
		utils/list-versions/list-versions.sh \
		utils/release/release_lib.sh utils/simple-backport/backport.sh \
		utils/simple-backport/changelog.sh
SHEBANG_LANG=	expect

expect_OLD_CMD=	/usr/bin/expect
expect_CMD=	${LOCALBASE}/bin/expect

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=20 \
		-DENABLE_EMBEDDED_COMPILER=OFF \
		-DENABLE_PARQUET=OFF \
		-DENABLE_UTILS=ON \
		-DNO_WERROR=1

CC=		clang11
CXX=		clang++11

USERS=		clickhouse
GROUPS=		clickhouse

# The version stamp of libclickhouse.so doesn't always match ${PORTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=		TEST
TEST_RUN_DEPENDS+=	expect>0:lang/expect

TEST_CMAKE_BOOL=	ENABLE_TESTS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
SUB_LIST+=	LEGACY_LIMITS="@comment " \
		MODERN_LIMITS=""
.else
SUB_LIST+=	LEGACY_LIMITS="" \
		MODERN_LIMITS="@comment "
.endif

SOVERSION=	${PORTVERSION}

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
