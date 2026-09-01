PORTNAME=	perfetto
DISTVERSIONPREFIX=	v
DISTVERSION=	58.2
CATEGORIES=	devel
MASTER_SITES=	https://storage.googleapis.com/perfetto/:perfetto
DISTFILES=	sqlite-amalgamation-3500300.zip:perfetto \
		llvm-project-617a15a9eac96088ae5e9134248d8236e34b91b1.tgz:perfetto

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

MAINTAINER=	siva@FreeBSD.org
COMMENT=	System profiling, app tracing, and trace analysis
WWW=		https://perfetto.dev/

BUILD_DEPENDS=	gn:devel/gn

USES=		compiler:c++17-lang ninja python:build

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES
OPTIONS_SUB=		YES

USE_GITHUB=	yes
GH_ACCOUNT=	google
# Taken from tools/install-build-deps
GH_TUPLE=	protocolbuffers:protobuf:v31.1:buildtools_protobuf/buildtools/protobuf \
		abseil:abseil-cpp:20250512.1:buildtools_abseil_cpp/buildtools/abseil-cpp \
		sqlite:sqlite:version-3.50.3:buildtools_sqlite_src/buildtools/sqlite_src \
		google:re2:927f5d53caf8111721e734cf24724686bb745f55:buildtools_re2/buildtools/re2 \
		facebook:zstd:f8745da6ff1ad1e7bab384bd1f9d742439278e99:buildtools_zstd/buildtools/zstd \
		libexpat:libexpat:R_2_6_2:buildtools_expat/buildtools/expat/src

GN_ARGS=	is_debug=false \
		skip_buildtools_check=true \
		perfetto_use_system_zlib=true \
		extra_cflags="-I${LOCALBASE}/include -Wno-unused-parameter" \
		extra_ldflags="-L${LOCALBASE}/lib"

BINARY_ALIAS=	python3=${PYTHON_CMD}

BUILD_WRKSRC=	${WRKSRC}/out

_PERFETTO_TARGETS=	perfetto tracebox traceconv traced traced_relay
_FREEBSD_TARGETS=	dtrace_probe freebsd_power freebsd_sys
ALL_TARGET=		libperfetto.a libperfetto_c.so ${_PERFETTO_TARGETS} ${_FREEBSD_TARGETS}

post-extract:
	${MV} ${WRKDIR}/sqlite-amalgamation-3500300 ${WRKSRC}/buildtools/sqlite
	${MV} ${WRKDIR}/llvm-project ${WRKSRC}/buildtools/llvm-project

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} gn gen out --args='${GN_ARGS}' && ${SETENV} ${CONFIGURE_ENV} gn ls out --args='${GN_ARGS}'
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} tools/gen_c_protos \
		--proto protos/perfetto/trace/power/power_rails.proto \
		--proto protos/perfetto/trace/power/battery_counters.proto \
		--proto protos/perfetto/trace/system_info/cpu_info.proto \
		--proto protos/perfetto/trace/sys_stats/sys_stats.proto \
		--proto protos/perfetto/common/sys_stats_counters.proto \
		${BUILD_WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libperfetto_c.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${BUILD_WRKSRC}/libperfetto.a ${STAGEDIR}${PREFIX}/lib
.for b in ${_PERFETTO_TARGETS}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${b} ${STAGEDIR}${PREFIX}/bin
.endfor
.for b in ${_FREEBSD_TARGETS}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${b} ${STAGEDIR}${PREFIX}/bin/perfetto_${b}
.endfor

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
