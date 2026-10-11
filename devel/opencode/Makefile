PORTNAME=	opencode
DISTVERSION=	2.0.26
CATEGORIES=	devel

# Upstream ships no FreeBSD builds of OpenTUI's Zig core, fff's Rust cdylib, the
# opencode-pty terminal daemon or the web UI's native Vite 8 bindings, so the
# port builds them from source (extra source trees plus a WASM fallback) and
# embeds everything into a single `bun --compile` executable.  See
# files/setup-*-freebsd.py, files/*.patch and files/webui-wasm-package.json.
#
# OPENTUI_VERSION and FFF_VERSION must match the pinned @opentui/core and
# @ff-labs/fff-bun releases (packages/cli/package.json, packages/core/package.json)
# or the native FFI ABI breaks.
OPENTUI_VERSION=	0.5.17
FFF_VERSION=	0.10.5
#
# opencode-pty is the persistent terminal daemon the client spawns.  Its version
# must match the pinned @opencode-ai/pty release and speak the same wire protocol
# as the bundled client (packages/cli/package.json, packages/core/package.json),
# and GHOSTTY_REVISION must match its ghostty-revision file, or the client
# rejects the daemon as a protocol mismatch.
OPENCODE_PTY_VERSION=	0.2.0
GHOSTTY_REVISION=	ab0b9da9e88fcb4b0533a1854e84628f663930af

MASTER_SITES=	https://github.com/anomalyco/opencode/archive/refs/tags/:opencode \
		https://github.com/anomalyco/opentui/archive/refs/tags/:opentui \
		https://github.com/dmtrKovalenko/fff/archive/refs/tags/:fff \
		https://registry.npmjs.org/@ff-labs/fff-bun/-/:fffbun \
		https://github.com/anomalyco/opencode-pty/archive/refs/tags/:opencodepty \
		https://github.com/ghostty-org/ghostty/archive/:ghostty
DISTFILES=	v${DISTVERSION}${EXTRACT_SUFX}:opencode \
		v${OPENTUI_VERSION}${EXTRACT_SUFX}:opentui \
		v${FFF_VERSION}${EXTRACT_SUFX}:fff \
		fff-bun-${FFF_VERSION}.tgz:fffbun \
		v${OPENCODE_PTY_VERSION}${EXTRACT_SUFX}:opencodepty \
		${GHOSTTY_REVISION}${EXTRACT_SUFX}:ghostty
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	samm@FreeBSD.org
COMMENT=	AI coding agent for the terminal
WWW=		https://opencode.ai/ \
		https://github.com/anomalyco/opencode

LICENSE=	MIT

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	OpenTUI's Zig core is only wired up for FreeBSD/aarch64 and FreeBSD/amd64

USES=		python:build cargo

# The port drives the whole build; keep cargo.mk from adding its own
# do-build/do-install/do-test.
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

# node (husky `prepare` + Vite 8 web UI).  Use node24: on aarch64 Vite 8's
# rolldown has no native binding and its WASI fallback SIGSEGVs under node26.
BUILD_DEPENDS=	${LOCALBASE}/bin/bun:lang/bun \
		${LOCALBASE}/bin/zig:lang/zig \
		${LOCALBASE}/bin/node:www/node24
# post-fetch warms the offline bun install cache, so bun is needed there too.
FETCH_DEPENDS=	${LOCALBASE}/bin/bun:lang/bun

# OpenCode's bundled ripgrep bootstrap has no FreeBSD build and only falls back
# to a system `rg`, so make sure one exists: it backs the non-VCS file search
# and the grep/glob tools.
RUN_DEPENDS=	rg:textproc/ripgrep

WRKSRC=		${WRKDIR}/opencode-${DISTVERSION}
OPENTUI_WRKSRC=	${WRKDIR}/opentui-${OPENTUI_VERSION}
FFF_WRKSRC=	${WRKDIR}/fff-${FFF_VERSION}
OPENCODE_PTY_WRKSRC=	${WRKDIR}/opencode-pty-${OPENCODE_PTY_VERSION}
GHOSTTY_WRKSRC=		${WRKDIR}/ghostty-${GHOSTTY_REVISION}

# Build only the fff C-ABI cdylib (not the nvim/python/mcp crates).
CARGO_BUILD_ARGS=	--package fff-c
FFF_SO=			${CARGO_TARGET_DIR}/release/libfff_c.so

BUN=			${LOCALBASE}/bin/bun
ZIG=			${LOCALBASE}/bin/zig
BUN_INSTALL_CACHE_DIR=	${WRKDIR}/bun-cache
WEBUI_WASM_DIR=	${WRKDIR}/gen-webui
WEBUI_WASM_CACHE=	${DISTDIR}/${DIST_SUBDIR}/opencode-webui-wasm-${DISTVERSION}.tar.gz
BUN_CACHE_TARBALL=	${DISTDIR}/${DIST_SUBDIR}/opencode-bun-cache-${DISTVERSION}.tar.gz
ZIG_PTY_CACHE_DIR=	${WRKDIR}/zig-pty-cache
ZIG_PTY_CACHE=		${DISTDIR}/${DIST_SUBDIR}/opencode-pty-zig-cache-${DISTVERSION}.tar.gz

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

# cargo.mk hard-assigns CARGO_WRKSRC from WRKSRC, so point it at the fff tree.
CARGO_WRKSRC=	${FFF_WRKSRC}

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
# Built from source by this port and embedded into the executable (see do-build).
OPENCODE_PTY_BIN=	${CARGO_TARGET_DIR}/release/opencode-pty

# Build the offline caches at fetch time.  The generated archives live in
# DISTDIR but are deliberately not listed in DISTFILES, so `make checksum` does
# not try to verify the generated files.
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
	@if [ ! -f ${ZIG_PTY_CACHE} ]; then \
		${ECHO_MSG} "===> Warming the Ghostty Zig dependency cache"; \
		${RM} -rf ${WRKDIR}/gen-ghostty && ${MKDIR} ${WRKDIR}/gen-ghostty && \
		${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${GHOSTTY_REVISION}${EXTRACT_SUFX} \
			-C ${WRKDIR}/gen-ghostty && \
		cd ${WRKDIR}/gen-ghostty/ghostty-${GHOSTTY_REVISION} && \
		${SETENV} ZIG_GLOBAL_CACHE_DIR=${ZIG_PTY_CACHE_DIR} \
			${ZIG} build --fetch=all && \
		${TAR} czf ${ZIG_PTY_CACHE} -C ${ZIG_PTY_CACHE_DIR} . ; \
	fi

post-extract:
	@${MKDIR} ${BUN_INSTALL_CACHE_DIR}
	@${TAR} xf ${BUN_CACHE_TARBALL} -C ${BUN_INSTALL_CACHE_DIR}
	@${MKDIR} ${ZIG_PTY_CACHE_DIR}
	@${TAR} xf ${ZIG_PTY_CACHE} -C ${ZIG_PTY_CACHE_DIR}

# OpenTUI, opencode-pty and Ghostty are extra source trees, so their patches are
# applied by hand.
post-patch:
	@${PATCH} -d ${OPENTUI_WRKSRC} -p0 --batch < ${FILESDIR}/opentui-build.zig.patch
	@${PATCH} -d ${OPENTUI_WRKSRC} -p0 --batch < ${FILESDIR}/opentui-ghostty-vt-freebsd.patch
	@${PATCH} -d ${OPENCODE_PTY_WRKSRC} -p1 --batch < ${FILESDIR}/opencode-pty-build.rs.patch
	@${PATCH} -d ${GHOSTTY_WRKSRC} -p1 --batch < ${FILESDIR}/ghostty-zig-0.16-std.patch

do-build:
	@${ECHO_MSG} "===> Installing OpenCode dependencies (offline)"
	@cd ${WRKSRC} && ${SETENV} BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
		${BUN} install --frozen-lockfile
	@${ECHO_MSG} "===> Installing @ff-labs/fff-bun (upstream ships no FreeBSD package)"
	@${MKDIR} ${WRKSRC}/node_modules/@ff-labs
	@${RM} -rf ${WRKSRC}/node_modules/@ff-labs/fff-bun
	@${MKDIR} ${WRKSRC}/node_modules/@ff-labs/fff-bun
	@${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/fff-bun-${FFF_VERSION}.tgz \
		-C ${WRKSRC}/node_modules/@ff-labs/fff-bun --strip-components=1
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
	@${ECHO_MSG} "===> Building the fff native library"
	@${CARGO_CARGO_RUN} build --manifest-path ${CARGO_CARGOTOML} ${CARGO_BUILD_ARGS}
	@${ECHO_MSG} "===> Wiring fff for FreeBSD"
	@cd ${WRKSRC} && ${PYTHON_CMD} ${FILESDIR}/setup-fff-freebsd.py \
		"${WRKSRC}" "${FFF_SO}" "${FFF_VERSION}" "${OPENTUI_ARCH}"
	@${ECHO_MSG} "===> Building the opencode-pty terminal daemon"
	@cd ${OPENCODE_PTY_WRKSRC} && ${SETENV} ${CARGO_ENV} \
		HOME=${WRKDIR} \
		ZIG_GLOBAL_CACHE_DIR=${ZIG_PTY_CACHE_DIR} \
		GHOSTTY_SOURCE_DIR=${GHOSTTY_WRKSRC} \
		OPENCODE_ZIG_CPU=baseline \
		${CARGO} build --release --locked
	@test -x ${OPENCODE_PTY_BIN} || (${ECHO_MSG} "Missing ${OPENCODE_PTY_BIN}"; ${FALSE})
	@${ECHO_MSG} "===> Building the web UI and compiling the OpenCode binary"
	@cd ${WRKSRC}/packages/cli && ${SETENV} \
		HOME=${WRKDIR} \
		OPENCODE_VERSION=${DISTVERSION} \
		BUN_INSTALL_CACHE_DIR=${BUN_INSTALL_CACHE_DIR} \
		OPENCODE_PTY_BIN=${OPENCODE_PTY_BIN} \
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
	@${ECHO_MSG} "==> Checking the fff native library is embedded..."
	@if ! ${GREP} -aq "crates/fff-c/src" ${STAGEDIR}${PREFIX}/bin/opencode; then \
		${ECHO_MSG} "ERROR: the fff native library is not embedded in the binary"; \
		${FALSE}; \
	fi
	@${ECHO_MSG} "==> Checking the opencode-pty terminal daemon is embedded..."
	@if ! ${GREP} -aq "libghostty" ${STAGEDIR}${PREFIX}/bin/opencode; then \
		${ECHO_MSG} "ERROR: the opencode-pty terminal daemon is not embedded in the binary"; \
		${FALSE}; \
	fi

.include <bsd.port.post.mk>
