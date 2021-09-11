# Created by: proler@gmail.com

PORTNAME=	clickhouse
PORTVERSION=	21.7.4.18
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=-stable
CATEGORIES=	databases

MAINTAINER=	olevole@olevole.ru
COMMENT=	Fast open-source OLAP database management system

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	"Only supported on amd64"

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:insource cpe localbase python shebangfix

CPE_VENDOR=	yandex

USE_GITHUB=	yes
GH_ACCOUNT=	yandex
GH_PROJECT=	ClickHouse
GH_TUPLE=	\
		ClickHouse-Extras:AMQP-CPP:03781aa:ClickHouse_Extras_AMQP_CPP/contrib/AMQP-CPP \
		ClickHouse-Extras:NuRaft:976874b:ClickHouse_Extras_NuRaft/contrib/NuRaft \
		ClickHouse-Extras:abseil-cpp:4f3b686:ClickHouse_Extras_abseil_cpp/contrib/abseil-cpp \
		ClickHouse-Extras:antlr4-runtime:672643e:ClickHouse_Extras_antlr4_runtime/contrib/antlr4-runtime \
		ClickHouse-Extras:arrow:debf751:ClickHouse_Extras_arrow/contrib/arrow \
		ClickHouse-Extras:avro:e43c46e:ClickHouse_Extras_avro/contrib/avro \
		ClickHouse-Extras:aws-sdk-cpp:7d48b2c:ClickHouse_Extras_aws_sdk_cpp/contrib/aws \
		ClickHouse-Extras:aws-c-common:736a82d:ClickHouse_Extras_aws_c_common/contrib/aws-c-common \
		ClickHouse-Extras:aws-c-event-stream:3bc3366:ClickHouse_Extras_aws_c_event_stream/contrib/aws-c-event-stream \
		ClickHouse-Extras:aws-checksums:519d6d9:ClickHouse_Extras_aws_checksums/contrib/aws-checksums \
		ClickHouse-Extras:Turbo-Base64:af9b331:ClickHouse_Extras_Turbo_Base64/contrib/base64 \
		ClickHouse-Extras:boost:1ccbb5a:ClickHouse_Extras_boost/contrib/boost \
		ClickHouse-Extras:boringssl:a6a2e2a:ClickHouse_Extras_boringssl/contrib/boringssl \
		google:brotli:63be8a9:google_brotli/contrib/brotli \
		capnproto:capnproto:a00ccd9:capnproto_capnproto/contrib/capnproto \
		ClickHouse-Extras:cpp-driver:eb9b68d:ClickHouse_Extras_cpp_driver/contrib/cassandra \
		ClickHouse-Extras:cctz:c0f1bcb:ClickHouse_Extras_cctz/contrib/cctz \
		mfontanini:cppkafka:5a119f6:mfontanini_cppkafka/contrib/cppkafka \
		RoaringBitmap:CRoaring:2c867e9:RoaringBitmap_CRoaring/contrib/croaring \
		curl:curl:3b8bbbb:curl_curl/contrib/curl \
		ClickHouse-Extras:cyrus-sasl:e6466ed:ClickHouse_Extras_cyrus_sasl/contrib/cyrus-sasl \
		google:double-conversion:cf2f0f3:google_double_conversion/contrib/double-conversion \
		apache:datasketches-cpp:7d73d76:contrib/datasketches-cpp \
		google:double-conversion:cf2f0f3:contrib/double-conversion \
		ClickHouse-Extras:dragonbox:923705a:ClickHouse_Extras_dragonbox/contrib/dragonbox \
		fastfloat:fast_float:7eae925:fastfloat_fast_float/contrib/fast_float \
		ClickHouse-Extras:fastops:88752a5:ClickHouse_Extras_fastops/contrib/fastops \
		google:flatbuffers:eb3f827:google_flatbuffers/contrib/flatbuffers \
		fmtlib:fmt:c108ee1:fmtlib_fmt/contrib/fmtlib \
		kthohr:gcem:8d4f1b5:kthohr_gcem/contrib/gcem \
		google:googletest:e7e5917:google_googletest/contrib/googletest \
		ClickHouse-Extras:grpc:60c986e:ClickHouse_Extras_grpc/contrib/grpc \
		ClickHouse-Extras:h3:e209086:ClickHouse_Extras_h3/contrib/h3 \
		ClickHouse-Extras:hyperscan:e9f08df:ClickHouse_Extras_hyperscan/contrib/hyperscan \
		unicode-org:icu:faa2f9f:unicode_org_icu/contrib/icu \
		ClickHouse-Extras:icudata:f020820:ClickHouse_Extras_icudata/contrib/icudata \
		ClickHouse-Extras:jemalloc:e6891d9:ClickHouse_Extras_jemalloc/contrib/jemalloc \
		ClickHouse-Extras:krb5:5149dea:ClickHouse_Extras_krb5/contrib/krb5 \
		ClickHouse-Extras:libc-headers:a720b71:ClickHouse_Extras_libc_headers/contrib/libc-headers \
		ClickHouse-Extras:libcpuid:8db3b8d:ClickHouse_Extras_libcpuid/contrib/libcpuid \
		ClickHouse-Extras:libcxx:2fa892f:ClickHouse_Extras_libcxx/contrib/libcxx \
		ClickHouse-Extras:libcxxabi:df8f1e7:ClickHouse_Extras_libcxxabi/contrib/libcxxabi \
		ClickHouse-Extras:libgsasl:383ee28:ClickHouse_Extras_libgsasl/contrib/libgsasl \
		ClickHouse-Extras:libhdfs3:095b9d4:ClickHouse_Extras_libhdfs3/contrib/libhdfs3 \
		ClickHouse-Extras:libpq:c762458:ClickHouse_Extras_libpq/contrib/libpq \
		jtv:libpqxx:357608d:jtv_libpqxx/contrib/libpqxx \
		ClickHouse-Extras:librdkafka:43491d3:ClickHouse_Extras_librdkafka/contrib/librdkafka \
		ClickHouse-Extras:libunwind:6b816d2:ClickHouse_Extras_libunwind/contrib/libunwind \
		ClickHouse-Extras:libuv:e2e9b7e:ClickHouse_Extras_libuv/contrib/libuv \
		GNOME:libxml2:18890f4:GNOME_libxml2/contrib/libxml2 \
		ClickHouse-Extras:llvm:e575145:ClickHouse_Extras_llvm/contrib/llvm \
		lz4:lz4:f39b79f:lz4_lz4/contrib/lz4 \
		ClickHouse-Extras:mariadb-connector-c:5f4034a:ClickHouse_Extras_mariadb_connector_c/contrib/mariadb-connector-c \
		danlark1:miniselect:be0af6b:danlark1_miniselect/contrib/miniselect \
		msgpack:msgpack-c:4668426:msgpack_msgpack_c/contrib/msgpack-c \
		nanodbc:nanodbc:9fc4596:contrib/nanodbc \
		ClickHouse-Extras:openldap:0208811:ClickHouse_Extras_openldap/contrib/openldap \
		apache:orc:0a936f6:apache_orc/contrib/orc \
		ClickHouse-Extras:poco:5994506:ClickHouse_Extras_poco/contrib/poco \
		ClickHouse-Extras:protobuf:73b1281:ClickHouse_Extras_protobuf/contrib/protobuf \
		ClickHouse-Extras:rapidjson:c4ef90c:ClickHouse_Extras_rapidjson/contrib/rapidjson \
		google:re2:13ebb37:google_re2/contrib/re2 \
		ClickHouse-Extras:replxx:c81be6c:ClickHouse_Extras_replxx/contrib/replxx \
		ClickHouse-Extras:rocksdb:07c7754:ClickHouse_Extras_rocksdb/contrib/rocksdb \
		ClickHouse-Extras:sentry-native:94644e9:ClickHouse_Extras_sentry_native/contrib/sentry-native \
		ClickHouse-Extras:simdjson:8df32ce:ClickHouse_Extras_simdjson/contrib/simdjson \
		google:snappy:3f194ac:google_snappy/contrib/snappy \
		sparsehash:sparsehash-c11:cf0bffa:sparsehash_sparsehash_c11/contrib/sparsehash-c11 \
		kthohr:stats:b6dd459:kthohr_stats/contrib/stats \
		apache:thrift:010ccf0:apache_thrift/contrib/thrift \
		ClickHouse-Extras:UnixODBC:b0ad30f:ClickHouse_Extras_UnixODBC/contrib/unixodbc \
		xz-mirror:xz:869b9d1:xz_mirror_xz/contrib/xz \
		ClickHouse-Extras:yaml-cpp:0c86ada:ClickHouse_Extras_yaml_cpp/contrib/yaml-cpp \
		ClickHouse-Extras:zlib-ng:db232d3:ClickHouse_Extras_zlib_ng/contrib/zlib-ng \
		facebook:zstd:a488ba1:facebook_zstd/contrib/zstd \
		c-ares:c-ares:e982924:c_ares_c_ares/contrib/grpc/third_party/cares/cares

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
		tests/queries/0_stateless/01293_client_interactive_vertical_multiline_long.expect \
		tests/queries/0_stateless/01293_client_interactive_vertical_singleline.expect \
		tests/queries/0_stateless/01300_client_save_history_when_terminated_long.expect \
		tests/queries/0_stateless/01370_client_autocomplete_word_break_characters.expect \
		tests/queries/0_stateless/01520_client_print_query_id.expect \
		tests/queries/0_stateless/01526_client_start_and_exit.expect-not-a-test-case \
		tests/queries/0_stateless/01565_reconnect_after_client_error.expect \
		tests/queries/0_stateless/01599_multiline_input_and_singleline_comments.sh \
		tests/queries/0_stateless/01610_client_spawn_editor.sh \
		tests/queries/0_stateless/01755_client_highlight_multi_line_comment_regression.expect \
		tests/queries/0_stateless/01910_client_replxx_container_overflow_long.expect  \
		tests/queries/0_stateless/01921_test_progress_bar.py \
		tests/queries/0_stateless/helpers/00900_parquet_create_table_columns.py \
		tests/queries/0_stateless/helpers/client.py \
		tests/queries/0_stateless/helpers/httpclient.py \
		tests/queries/0_stateless/helpers/httpexpect.py \
		tests/queries/0_stateless/helpers/protobuf_length_delimited_encoder.py \
		tests/queries/0_stateless/helpers/pure_http_client.py \
		tests/queries/0_stateless/helpers/shell.py \
		tests/queries/0_stateless/helpers/uexpect.py \
		utils/build/build_debian.sh utils/build/build_debian_shared.sh \
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
		utils/list-versions/list-versions.sh
SHEBANG_LANG=	expect

expect_OLD_CMD=	/usr/bin/expect
expect_CMD=	${LOCALBASE}/bin/expect

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=20 \
		-DENABLE_EMBEDDED_COMPILER=OFF \
		-DENABLE_PARQUET=OFF \
		-DENABLE_UTILS=ON \
		-DNO_WERROR=1

USERS=		clickhouse
GROUPS=		clickhouse

# The version stamp of libclickhouse.so doesn't always match ${PORTVERSION}
PLIST_SUB=	SOVERSION=${SOVERSION}

OPTIONS_DEFINE=		TEST
TEST_RUN_DEPENDS+=	expect>0:lang/expect

TEST_CMAKE_BOOL=	ENABLE_TESTS

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1300000
CC=			clang11
CXX=		clang++11
BUILD_DEPENDS+= clang++11:devel/llvm11
.else
CC=			clang
CXX=		clang++
.endif

SOVERSION=	${PORTVERSION}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/var/lib/clickhouse|/var/db/clickhouse|;s|/var/log/clickhouse-server|/var/log/clickhouse|;s|/etc/clickhouse-server|${PREFIX}/etc/clickhouse-server|' ${WRKSRC}/programs/server/config.xml

post-install:
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
