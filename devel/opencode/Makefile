PORTNAME=	opencode
DISTVERSION=	2.0.23
CATEGORIES=	devel

# OpenCode pins one exact @opentui/core release; OPENTUI_VERSION must match the
# version in packages/cli/package.json or the JS/native FFI ABI breaks.
OPENTUI_VERSION=	0.5.14

# Upstream ships no FreeBSD OpenTUI core and no FreeBSD native Rust bindings for
# the Vite 8 web UI, so do-build:
#   - builds OpenTUI's Zig core from the matching tag; setup-opentui-freebsd.py
#     teaches the bundled @opentui/core about freebsd and drops the .so into a
#     @opentui/core-freebsd-<arch> package so `bun --compile` embeds it;
#   - stages WASM fallbacks for the web UI's rolldown/lightningcss/oxide
#     (files/webui-wasm-package.json) plus a lightningcss-freebsd-arm64 shim
#     (LightningCSS's loader does not fall back automatically);
#   - applies files/patch-packages_cli_script_build.ts (freebsd targets, parcel
#     watcher degrade, bytecode off).
# The result is a single `bun --compile` executable embedding bun, the JS bundle,
# the OpenTUI core and the web UI assets.

MASTER_SITES=	https://github.com/anomalyco/opencode/archive/refs/tags/:opencode \
		https://github.com/anomalyco/opentui/archive/refs/tags/:opentui
DISTFILES=	v${DISTVERSION}${EXTRACT_SUFX}:opencode \
		v${OPENTUI_VERSION}${EXTRACT_SUFX}:opentui
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	samm@FreeBSD.org
COMMENT=	AI coding agent for the terminal
WWW=		https://opencode.ai/ \
		https://github.com/anomalyco/opencode

LICENSE=	MIT

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	OpenTUI's Zig core is only wired up for FreeBSD/aarch64 and FreeBSD/amd64

USES=		python:build

# node (husky `prepare` + Vite 8 web UI).  Use node24: on aarch64 Vite 8's
# rolldown has no native binding and its WASI fallback SIGSEGVs under node26.
BUILD_DEPENDS=	${LOCALBASE}/bin/bun:lang/bun \
		${LOCALBASE}/bin/zig:lang/zig \
		${LOCALBASE}/bin/node:www/node24
# post-fetch warms the offline bun install cache, so bun is needed there too.
FETCH_DEPENDS=	${LOCALBASE}/bin/bun:lang/bun

WRKSRC=		${WRKDIR}/opencode-${DISTVERSION}
OPENTUI_WRKSRC=	${WRKDIR}/opentui-${OPENTUI_VERSION}

BUN=			${LOCALBASE}/bin/bun
ZIG=			${LOCALBASE}/bin/zig
BUN_INSTALL_CACHE_DIR=	${WRKDIR}/bun-cache
WEBUI_WASM_DIR=	${WRKDIR}/gen-webui
WEBUI_WASM_CACHE=	${DISTDIR}/${DIST_SUBDIR}/opencode-webui-wasm-${DISTVERSION}.tar.gz
BUN_CACHE_TARBALL=	${DISTDIR}/${DIST_SUBDIR}/opencode-bun-cache-${DISTVERSION}.tar.gz

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

# OpenTUI/Bun arch names differ from ARCH: x64/arm64 for the JS side, and
# x86_64-freebsd/aarch64-freebsd for the Zig artifact directory.
.if ${ARCH} == amd64
OPENTUI_ARCH=	x64
OPENTUI_ZIGDIR=	x86_64-freebsd
.elif ${ARCH} == aarch64
OPENTUI_ARCH=	arm64
OPENTUI_ZIGDIR=	aarch64-freebsd
.endif

OPENTUI_SO=		${OPENTUI_WRKSRC}/packages/native/lib/${OPENTUI_ZIGDIR}/libopentui.so
OPENCODE_BIN=		${WRKSRC}/packages/cli/dist/cli-freebsd-${OPENTUI_ARCH}/bin/opencode

# Build the offline caches at fetch time.  Both archives live in DISTDIR but
# are deliberately not listed in DISTFILES, so `make checksum` does not try
# to verify the generated files.
post-fetch:
	@${ECHO_MSG} "===> Warming bun install cache"
	@${RM} -rf ${WRKDIR}/gen && ${MKDIR} ${WRKDIR}/gen
	@${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/v${DISTVERSION}${EXTRACT_SUFX} -C ${WRKDIR}/gen
	@if [ ! -f ${BUN_CACHE_TARBALL} ]; then \
		cd ${WRKDIR}/gen/opencode-${DISTVERSION} && \
		${SETENV} BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
			${BUN} install --frozen-lockfile && \
		${TAR} czf ${BUN_CACHE_TARBALL} -C ${BUN_INSTALL_CACHE_DIR} . ; \
	fi
	@if [ ! -f ${WEBUI_WASM_CACHE} ]; then \
		${ECHO_MSG} "===> Staging Web UI WASM fallbacks"; \
		${RM} -rf ${WEBUI_WASM_DIR} && ${MKDIR} ${WEBUI_WASM_DIR} && \
		${CP} ${FILESDIR}/webui-wasm-package.json ${WEBUI_WASM_DIR}/package.json && \
		cd ${WEBUI_WASM_DIR} && \
		${SETENV} BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} ${BUN} install && \
		${TAR} czf ${WEBUI_WASM_CACHE} -C ${WEBUI_WASM_DIR} node_modules ; \
	fi

post-extract:
	@${MKDIR} ${BUN_INSTALL_CACHE_DIR}
	@${TAR} xf ${BUN_CACHE_TARBALL} -C ${BUN_INSTALL_CACHE_DIR}

# OpenTUI is a second source tree, so its patch is applied by hand.
post-patch:
	@${PATCH} -d ${OPENTUI_WRKSRC} -p0 --batch < ${FILESDIR}/opentui-build.zig.patch

do-build:
	@${ECHO_MSG} "===> Installing OpenCode dependencies (offline)"
	@cd ${WRKSRC} && ${SETENV} BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
		${BUN} install --frozen-lockfile
	@${ECHO_MSG} "===> Adding Web UI WASM fallbacks"
	@${TAR} xf ${WEBUI_WASM_CACHE} -C ${WRKSRC}
	@${MKDIR} ${WRKSRC}/node_modules/lightningcss-freebsd-arm64
	@${ECHO_CMD} '{"name":"lightningcss-freebsd-arm64","version":"1.32.0","main":"index.js"}' \
		> ${WRKSRC}/node_modules/lightningcss-freebsd-arm64/package.json
	@${ECHO_CMD} 'module.exports = require("lightningcss-wasm")' \
		> ${WRKSRC}/node_modules/lightningcss-freebsd-arm64/index.js
	@${ECHO_MSG} "===> Building OpenTUI native core"
	@cd ${OPENTUI_WRKSRC}/packages/native && \
		${SETENV} HOME=${WRKDIR} \
			ZIG_GLOBAL_CACHE_DIR=${WRKDIR}/zig-cache \
			ZIG_LOCAL_CACHE_DIR=${WRKDIR}/zig-cache-local \
			${SH} scripts/prepare-zig-deps.sh && \
		${SETENV} HOME=${WRKDIR} \
			ZIG_GLOBAL_CACHE_DIR=${WRKDIR}/zig-cache \
			ZIG_LOCAL_CACHE_DIR=${WRKDIR}/zig-cache-local \
			${ZIG} build -Doptimize=ReleaseFast
	@${ECHO_MSG} "===> Wiring OpenTUI for FreeBSD"
	@cd ${WRKSRC} && ${PYTHON_CMD} ${FILESDIR}/setup-opentui-freebsd.py \
		"${WRKSRC}" "${OPENTUI_SO}" "${OPENTUI_VERSION}" "${OPENTUI_ARCH}"
	@${ECHO_MSG} "===> Building the web UI and compiling the OpenCode binary"
	@cd ${WRKSRC}/packages/cli && ${SETENV} \
		HOME=${WRKDIR} \
		OPENCODE_VERSION=${DISTVERSION} \
		BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
		${BUN} run script/build.ts \
			--target=opencode-freebsd-${OPENTUI_ARCH} \
			--skip-install \
			--outdir=dist
	@test -x ${OPENCODE_BIN} || (${ECHO_MSG} "Missing ${OPENCODE_BIN}"; ${FALSE})

do-install:
	# bun --compile appends the standalone payload to the executable.  Stripping
	# it (the default ${INSTALL_PROGRAM}) discards that payload, leaving a binary
	# that runs as plain bun, so install it unstripped.
	${INSTALL} -m 555 ${OPENCODE_BIN} ${STAGEDIR}${PREFIX}/bin/opencode

do-test:
	@${ECHO_MSG} "==> Running OpenCode smoke test..."
	${STAGEDIR}${PREFIX}/bin/opencode --version

.include <bsd.port.post.mk>
