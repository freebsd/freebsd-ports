# Notes for port maintainer(s)
#
# Before copying package.json and yarn.lock to ${PKGJSONSDIR},
# do the following steps:
# 1. Add os=freebsd to package installation conditions of the following
#    node modules in yarn.lock:
#    onnxruntime-node, sqlite-vec-linux-x64
# Before copying package.json and package-lock.json to ${FILESDIR}/onnxruntime,
# do the following steps:
# 1. Add freebsd to os in js/node/package.json

PORTNAME=	joplin
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.16
CATEGORIES=	deskutils
MASTER_SITES=	https://www.sqlite.org/2024/:sqlite
PKGNAMESUFFIX=	-desktop
# Files needed for building onnxruntime-node node modules
DISTFILES=	${ONNXRUNTIME_NODE_MODULES_FILE}:prefetch
# Files needed for building sqlite-vec node module
DISTFILES+=	sqlite-amalgamation-3450300.zip:sqlite
# Node modules for joplin's default plugins and app-clipper
DISTFILES+=	${DEFAULT_PLUGINS_NODE_MODULES_FILE}:prefetch \
		${APP_CLIPPER_NODE_MODULES_FILE}:prefetch

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Note taking and to-do application with synchronisation capabilities
WWW=		https://joplinapp.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	7zz:archivers/7-zip \
		git:devel/git \
		gpatch:devel/patch \
		rsync:net/rsync \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}
LIB_DEPENDS=	libvips.so:graphics/vips \
		libsecret-1.so:security/libsecret

USES=		cargo cmake:indirect cpe electron:42 gettext-runtime:build \
		gmake iconv:wchar_t localbase:ldflags nodejs:24,build \
		npm:yarn4 python:build

CPE_VENDOR=	joplinapp
USE_GITHUB=	yes
GH_ACCOUNT=	laurent22
# Files needed for building native node modules (build-time dependencies)
GH_TUPLE=	rollup:rollup:v4.9.1:rollup/rollup \
		rustwasm:wasm-pack:v0.13.1:wasm_pack/wasm-pack
# Files needed for building native node modules (run-time dependencies)
GH_TUPLE+=	microsoft:onnxruntime:v${ONNXRUNTIME_VERSION}:onnxruntime/onnxruntime \
		emscripten-core:emsdk:c0bb220cb6e6f4e0fabb6f6db9efd53390ef5e56:emsdk/onnxruntime/cmake/external/emsdk \
		google:libprotobuf-mutator:7a2ed51a6b682a83e345ff49fc4cfd7ca47550db:libprotobuf_mutator/onnxruntime/cmake/external/libprotobuf-mutator \
		onnx:onnx:d3f6b795aedb48eaecc881bf5e8f5dd6efbe25b3:onnx/onnxruntime/cmake/external/onnx \
		asg017:sqlite-vec:v${SQLITE_VEC_VERSION}:sqlite_vec/sqlite-vec
# Dependencies needed for building onnxruntime
GH_TUPLE+=	abseil:abseil-cpp:20250814.0:abseil_cpp/onnxruntime/_deps/abseil_cpp-src \
		pytorch:cpuinfo:403d652dca4c1046e8145950b1c0997a9f748b57:cpuinfo/onnxruntime/_deps/pytorch_cpuinfo-src \
		HowardHinnant:date:v3.0.1:date/onnxruntime/_deps/date-src \
		eigen-mirror:eigen:1d8b82b0740839c0de7f1242a3585e3390ff5f33:eigen/onnxruntime/_deps/eigen3-src \
		google:flatbuffers:v23.5.26:flatbuffers/onnxruntime/_deps/flatbuffers-src \
		microsoft:GSL:v4.0.0:gsl/onnxruntime/_deps/gsl-src \
		boostorg:mp11:boost-1.82.0:mp11/onnxruntime/_deps/mp11-src \
		nlohmann:json:v3.11.3:json/onnxruntime/_deps/nlohmann_json-src \
		onnx:onnx:v1.20.1:onnx_src/onnxruntime/_deps/onnx-src \
		protocolbuffers:protobuf:v21.12:protobuf/onnxruntime/_deps/protobuf-src \
		google:re2:2024-07-02:re2/onnxruntime/_deps/re2-src \
		dcleblanc:SafeInt:3.0.28:safeint/onnxruntime/_deps/safeint-src
# Node modules for joplin's default plugins
# See ${WRKSRC}/packages/default-plugins/pluginRepositories.json for GH_TUPLEs for default plugins
GH_TUPLE+=	JackGruber:joplin-plugin-backup:2c3da7056e7ac39c86c2051a4fdb99d9534dd0a1:joplin_plugin_backup/packages/default-plugins/plugin-sources/io.github.jackgruber.backup

CMAKE_ON=		onnxruntime_BUILD_SHARED_LIB \
			onnxruntime_BUILD_NODEJS
CMAKE_OFF=		onnxruntime_BUILD_UNIT_TESTS
CMAKE_SOURCE_PATH=	${WRKDIR}/onnxruntime/cmake

CARGO_CARGOTOML_ROLLUP=	${WRKSRC}/rollup/rust/Cargo.toml
CARGO_CARGOLOCK_ROLLUP=	${WRKSRC}/rollup/rust/Cargo.lock
CARGO_CARGOTOML_WASM_PACK=	${WRKSRC}/wasm-pack/Cargo.toml
CARGO_CARGOLOCK_WASM_PACK=	${WRKSRC}/wasm-pack/Cargo.lock
CARGO_CARGOTOML=	${CARGO_CARGOTOML_ROLLUP}
CARGO_CARGOLOCK=	${CARGO_CARGOLOCK_ROLLUP}
CARGO_CARGOLOCKS=	${CARGO_CARGOLOCK_ROLLUP} \
			${CARGO_CARGOLOCK_WASM_PACK}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

CXXFLAGS+=	-I${WRKDIR}/onnxruntime/include/onnxruntime/core/common/logging

BINARY_ALIAS=		patch=gpatch \
			python3=${PYTHON_CMD}
SUB_FILES=		${PORTNAME}${PKGNAMESUFFIX}
TARGET_ORDER_OVERRIDE=	750:npm-install-node-modules

BUILD_WRKSRC=	${WRKSRC}/packages/app-desktop
TEST_WRKSRC=	${WRKSRC}/packages/app-desktop

PORTDOCS=	README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

USE_ELECTRON=	appbuilder build:builder

SQLITE_VEC_VERSION=			0.1.9
ONNXRUNTIME_VERSION=			1.24.3
ONNXRUNTIME_NODE_MODULES_FILE=		onnxruntime-${ONNXRUNTIME_VERSION}-node-modules${EXTRACT_SUFX}
DEFAULT_PLUGINS_NODE_MODULES_FILE=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-default-plugins-node-modules${EXTRACT_SUFX}
APP_CLIPPER_NODE_MODULES_FILE=		${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-app-clipper-node-modules${EXTRACT_SUFX}

pre-fetch:
	@if [ ! -f ${DISTDIR}/${ONNXRUNTIME_NODE_MODULES_FILE} ]; then \
		${ECHO_MSG} "===>  Prefetching and archiving node modules for onnxruntime-node"; \
		${MKDIR} ${WRKDIR}/node-modules-cache-onnxruntime; \
		${CP} -R ${FILESDIR}/onnxruntime/* ${WRKDIR}/node-modules-cache-onnxruntime; \
		for dir in `${FIND} ${FILESDIR}/onnxruntime/. -type d -print | ${SED} -e 's|${FILESDIR}/onnxruntime||'`; do \
			cd ${WRKDIR}/node-modules-cache-onnxruntime/$${dir} && \
			${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
				npm ci --ignore-scripts --no-progress --no-audit --no-fund --no-update-notifier --loglevel=error; \
			${RM} package.json package-lock.json; \
		done; \
		cd ${WRKDIR} && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/npm-create-mtree.sh node-modules-cache-onnxruntime > \
			node-modules-cache-onnxruntime.mtree && \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${ONNXRUNTIME_NODE_MODULES_FILE} @node-modules-cache-onnxruntime.mtree; \
		${RM} -r ${WRKDIR}/node-modules-cache-onnxruntime; \
	fi
	@if [ ! -f ${DISTDIR}/${DEFAULT_PLUGINS_NODE_MODULES_FILE} ]; then \
		${ECHO_MSG} "===>  Prefetching and archiving node modules for default plugins"; \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		${CP} -R ${FILESDIR}/default-plugins/* ${WRKDIR}/node-modules-cache; \
		for dir in `${FIND} ${FILESDIR}/default-plugins -type d -depth 1 -print | ${SED} -e 's|${FILESDIR}/default-plugins||'`; do \
			cd ${WRKDIR}/node-modules-cache/$${dir} && \
			${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
				npm ci --ignore-scripts --no-progress --no-audit --no-fund --no-update-notifier --loglevel=error; \
			${RM} package.json package-lock.json; \
		done; \
		cd ${WRKDIR} && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/npm-create-mtree.sh node-modules-cache > \
			node-modules-cache.mtree && \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${DEFAULT_PLUGINS_NODE_MODULES_FILE} @node-modules-cache.mtree; \
		${RM} -r ${WRKDIR}/node-modules-cache; \
	fi
	@if [ ! -f ${DISTDIR}/${APP_CLIPPER_NODE_MODULES_FILE} ]; then \
		${ECHO_MSG} "===>  Prefetching and archiving node modules for app-clipper"; \
		${MKDIR} ${WRKDIR}/node-modules-cache-app-clipper; \
		${CP} -R ${FILESDIR}/app-clipper/* ${WRKDIR}/node-modules-cache-app-clipper; \
		cd ${WRKDIR}/node-modules-cache-app-clipper && \
		${SETENV} HOME=${WRKDIR} XDG_CACHE_HOME=${WRKDIR}/.cache \
			npm ci --ignore-scripts --no-progress --no-audit --no-fund --no-update-notifier --loglevel=error && \
		${RM} package.json package-lock.json; \
		cd ${WRKDIR} && \
		${SETENV} SCRIPTSDIR=${SCRIPTSDIR} WRKDIR=${WRKDIR} \
			${SH} ${SCRIPTSDIR}/npm-create-mtree.sh node-modules-cache-app-clipper > \
			node-modules-cache-app-clipper.mtree && \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${APP_CLIPPER_NODE_MODULES_FILE} @node-modules-cache-app-clipper.mtree; \
		${RM} -r ${WRKDIR}/node-modules-cache-app-clipper; \
	fi

post-extract:
	@${ECHO_MSG} "===>  Moving prefetched node modules for onnxruntime to ${WRKSRC}/onnxruntime"
	@for dir in `${FIND} ${FILESDIR}/onnxruntime/. -type d -print | ${SED} -e 's|${FILESDIR}/onnxruntime||'`; do \
		${MV} ${WRKDIR}/node-modules-cache-onnxruntime/$${dir}/node_modules \
			${WRKSRC}/onnxruntime/js/$${dir}; \
	done
	@${ECHO_MSG} "===>  Copying sqlite3 sources to ${WRKSRC}/sqlite-vec/vendor"
	@${MKDIR} ${WRKSRC}/sqlite-vec/vendor
	@${CP} ${WRKDIR}/sqlite-amalgamation-3450300/* ${WRKSRC}/sqlite-vec/vendor
	@${ECHO_MSG} "===>  Moving prefetched node modules for default plugins to ${WRKSRC}/packages/default-plugins/plugin-sources"
	@for dir in `${FIND} ${WRKDIR}/node-modules-cache -type d -depth 1 -print | ${SED} -e 's|${WRKDIR}/node-modules-cache||'`; do \
		${MV} ${WRKDIR}/node-modules-cache/$${dir}/node_modules \
			${WRKSRC}/packages/default-plugins/plugin-sources/$${dir}; \
	done
	@${ECHO_MSG} "===>  Moving prefetched node modules for app-clipper to ${WRKSRC}/packages/app-clipper/popup"
	@${MV} ${WRKDIR}/node-modules-cache-app-clipper/node_modules \
		${WRKSRC}/packages/app-clipper/popup
	# Rename '@' character in file names with '_at_'
	@for patch_file in `${FIND} ${WRKSRC}/.yarn/patches -type f -name '*@*'`; do \
		${MV} $${patch_file} `${ECHO_CMD} $${patch_file} | ${SED} -e 's/@/_at_/g'`; \
	done

pre-patch:
	# Prepare a placeholder for native node modules of sqlite-vec.
	# The native module are overwritten later.
	@${CP} -R ${WRKSRC}/packages/app-desktop/node_modules/sqlite-vec-linux-${ELECTRON_ARCH} \
		${WRKSRC}/packages/app-desktop/node_modules/sqlite-vec-freebsd-${ELECTRON_ARCH}

post-configure:
	# Move onnxruntime directory out of WRKSRC to prevent node modules
	# from conflicting with joplin's ones
	@${MV} ${WRKSRC}/onnxruntime ${WRKDIR}
	# Configure onnxruntime
	@cd ${WRKDIR}/onnxruntime && \
	${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_SOURCE_PATH}
	# Configure wasm-pack
	@${ECHO_MSG} "===>   Updating Cargo.lock for ${CARGO_CARGOTOML_WASM_PACK}"
	@${CARGO_CARGO_RUN} update --manifest-path ${CARGO_CARGOTOML_WASM_PACK} \
		--verbose --verbose ${CARGO_UPDATE_ARGS}

pre-build:
	# Prepare onnxruntime node sources prior to build
	cd ${WRKDIR}/onnxruntime/js && ${SETENV} ${MAKE_ENV} npm run prepare
	cd ${WRKDIR}/onnxruntime/js/common && ${SETENV} ${MAKE_ENV} npm run prepare
	cd ${WRKDIR}/onnxruntime/js/node && ${SETENV} ${MAKE_ENV} npm run prepare
	# Build onnxruntime and copy the resulting native node module
	cd ${WRKDIR}/onnxruntime && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS}
	${MKDIR} ${WRKSRC}/packages/app-desktop/node_modules/onnxruntime-node/bin/napi-v6/freebsd/${ELECTRON_ARCH}
	${CP} -P ${WRKDIR}/onnxruntime/js/node/bin/napi-v6/freebsd/${ELECTRON_ARCH}/* \
		${WRKSRC}/packages/app-desktop/node_modules/onnxruntime-node/bin/napi-v6/freebsd/${ELECTRON_ARCH}
	# Build sqlite-vec and copy the resulting native node module
	cd ${WRKSRC}/sqlite-vec && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} loadable
	${CP} ${WRKSRC}/sqlite-vec/dist/vec0.so \
		${WRKSRC}/packages/app-desktop/node_modules/sqlite-vec-freebsd-${ELECTRON_ARCH}
	# Build rollup and copy the resulting native node module
	cd ${WRKSRC}/rollup/rust && \
	${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${CARGO} build \
		--manifest-path ${CARGO_CARGOTOML_ROLLUP} \
		--release --verbose --verbose
	${CP} ${CARGO_TARGET_DIR}/*/libbindings_napi.so \
		${WRKSRC}/packages/turndown/node_modules/rollup/dist/rollup.freebsd-${ELECTRON_ARCH}.node
	# Build wasm-pack and copy the resulting native node module
	cd ${WRKSRC}/wasm-pack && \
	${SETENV} ${MAKE_ENV} ${CARGO_ENV} ${CARGO} build \
		--manifest-path ${CARGO_CARGOTOML_WASM_PACK} \
		--release --verbose --verbose
	@${MKDIR} ${WRKSRC}/packages/onenote-converter/node_modules/binary-install/node_modules/.bin
	${CP} ${CARGO_TARGET_DIR}/*/wasm-pack \
		${WRKSRC}/packages/onenote-converter/node_modules/binary-install/node_modules/.bin
	# Copy system 7zip binary to node module directory
	@${MKDIR} ${WRKSRC}/packages/app-desktop/node_modules/7zip-bin/freebsd/${ELECTRON_ARCH}
	${CP} ${LOCALBASE}/bin/7zz \
		${WRKSRC}/packages/app-desktop/node_modules/7zip-bin/freebsd/${ELECTRON_ARCH}/7za
	# Build joplin
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn exec gulp build
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} yarn run electronRebuild
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${ELECTRON_REBUILD_ENV} yarn exec gulp before-dist

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}${PKGNAMESUFFIX}.desktop ${STAGEDIR}${DESKTOPDIR}
.for size in 16 24 32 48 72 96 128 144 256 512 1024
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${BUILD_WRKSRC}/build/icons/${size}x${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/dist/${ELECTRON_BUILDER_APP_OUT_DIR} && \
		${COPYTREE_SHARE} resources ${STAGEDIR}${DATADIR}
	${FIND} ${STAGEDIR}${DATADIR}/resources -type f -exec ${FILE} {} ';' | \
		${GREP} 'ELF.*FreeBSD' | ${AWK} -F ': ' '{print $$1}' | ${XARGS} ${STRIP_CMD}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} yarn run test

#
# targets for port maintainer(s)
#
cargo-crates-from-multiple-lockfiles: extract
	@for lf in ${CARGO_CARGOLOCKS}; do \
		${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates.awk $${lf}; \
	done | \
	${SED} -E 's/^CARGO_CRATES=\t+/\t\t/; s/ \\$$//' | \
	${SORT} -u | \
	${SED} -e '1s/^\t\t/CARGO_CRATES=\t/; s/$$/ \\/' | \
	${SED} -e '$$s/ \\//'

.include <bsd.port.mk>
