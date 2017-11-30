# $FreeBSD$
#
# This file contains logic to ease porting of Rust packages or
# binaries using the `cargo` command.
#
# Feature:	cargo
# Usage:	USES=cargo
# Valid ARGS:	none
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_CARGO_MK)
_INCLUDE_USES_CARGO_MK=	yes

.if !empty(cargo_ARGS)
IGNORE+=	USES=cargo takes no arguments
.endif

# List of static dependencies.  The format is cratename-version.
# CARGO_CRATES will be downloaded from MASTER_SITES_CRATESIO.
CARGO_CRATES?=

# List of features to build (space separated list).
CARGO_FEATURES?=

# Name of the local directory for vendoring crates.
CARGO_VENDOR_DIR?=	${WRKSRC}/cargo-crates

# Default path for cargo manifest.
CARGO_CARGOTOML?=	${WRKSRC}/Cargo.toml
CARGO_CARGOLOCK?=	${WRKSRC}/Cargo.lock

# Define MASTER_SITES_CRATESIO for crates.io
MASTER_SITES_CRATESIO=	https://crates.io/api/v1/crates

# Save crates inside ${DISTDIR}/rust/crates by default.
CARGO_DIST_SUBDIR?=	rust/crates

# Generate list of DISTFILES.
.for _crate in ${CARGO_CRATES}
MASTER_SITES+=	${MASTER_SITES_CRATESIO}/${_crate:C/-[0-9].*$//}/${_crate:C/^.*-([0-9].*)/\1/}/download?dummy=/:cargo_${_crate:S/-//g:S/.//g}
DISTFILES+=	${CARGO_DIST_SUBDIR}/${_crate}.tar.gz:cargo_${_crate:S/-//g:S/.//g}
.endfor

# Build dependencies.

CARGO_BUILDDEP?=	yes
.if ${CARGO_BUILDDEP:tl} == "yes"
BUILD_DEPENDS+=	 rust>=1.19.0_2:lang/rust
.endif

# Location of cargo binary (default to lang/rust's Cargo binary)
CARGO_CARGO_BIN?=	${LOCALBASE}/bin/cargo

# Location of the cargo output directory.
CARGO_TARGET_DIR?=	${WRKDIR}/target

# Environment for cargo
#  - CARGO_HOME: local cache of the registry index
#  - CARGO_BUILD_JOBS: configure number of jobs to run
#  - CARGO_TARGET_DIR: location of where to place all generated artifacts
#  - RUSTC: path of rustc binary (default to lang/rust)
#  - RUSTDOC: path of rustdoc binary (default to lang/rust)
#  - RUSTFLAGS: custom flags to pass to all compiler invocations that Cargo performs
#
# XXX LDFLAGS => -C link-arg=$1 (via RUSTFLAGS)
CARGO_ENV+= \
	CARGO_HOME=${WRKDIR}/cargo-home \
	CARGO_BUILD_JOBS=${MAKE_JOBS_NUMBER} \
	CARGO_TARGET_DIR=${CARGO_TARGET_DIR} \
	RUSTC=${LOCALBASE}/bin/rustc \
	RUSTDOC=${LOCALBASE}/bin/rustdoc \
	RUSTFLAGS="${RUSTFLAGS}"

# Adjust -C target-cpu if -march/-mcpu is set by bsd.cpu.mk
.if ${ARCH} == amd64 || ${ARCH} == i386
RUSTFLAGS+=	${CFLAGS:M-march=*:S/-march=/-C target-cpu=/}
.else
RUSTFLAGS+=	${CFLAGS:M-mcpu=*:S/-mcpu=/-C target-cpu=/}
.endif

# Helper to shorten cargo calls.
CARGO_CARGO_RUN= \
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO_ENV} \
		${CARGO_CARGO_BIN}

# User arguments for cargo targets.
CARGO_BUILD_ARGS?=
CARGO_INSTALL_ARGS?=
CARGO_TEST_ARGS?=
CARGO_UPDATE_ARGS?=

# Use module targets ?
CARGO_BUILD?=	yes
CARGO_CONFIGURE?=	yes
CARGO_INSTALL?=	yes
CARGO_TEST?=	yes
CARGO_USE_GITHUB?=	no

# If your application has multiple Cargo.toml files which all use
# git-sourced dependencies and require the use of CARGO_USE_GITHUB and
# GH_TUPLE, then you add them to CARGO_GH_CARGOTOML to also point them
# to the correct offline sources.
CARGO_GH_CARGOTOML?=	${CARGO_CARGOTOML}

# Manage crate features.
.if !empty(CARGO_FEATURES)
CARGO_BUILD_ARGS+=	--features='${CARGO_FEATURES}'
CARGO_INSTALL_ARGS+=	--features='${CARGO_FEATURES}'
CARGO_TEST_ARGS+=	--features='${CARGO_FEATURES}'
.endif

.if !defined(WITH_DEBUG)
CARGO_BUILD_ARGS+=	--release
CARGO_TEST_ARGS+=	--release
.else
CARGO_INSTALL_ARGS+=	--debug
.endif

.if ${CARGO_CRATES:Mlibgit2-sys-*}
# Use the system's libgit2 instead of building the bundled version
LIB_DEPENDS+=	libgit2.so:devel/libgit2
CARGO_ENV+=	LIBGIT2_SYS_USE_PKG_CONFIG=1
.endif

.if ${CARGO_CRATES:Mopenssl-sys-*}
# Make sure that openssl-sys can find the correct version of OpenSSL
.include "${USESDIR}/ssl.mk"
CARGO_ENV+=	OPENSSL_LIB_DIR=${OPENSSLLIB} \
		OPENSSL_INCLUDE_DIR=${OPENSSLINC}
.endif

.if ${CARGO_CRATES:Mpkg-config-*}
.include "${USESDIR}/pkgconfig.mk"
.endif

_USES_extract+=	600:cargo-extract
cargo-extract:
# target for preparing crates directory.  It will put all crates in
# the local crates directory.
	@${ECHO_MSG} "===>  Moving crates to ${CARGO_VENDOR_DIR}"
	@${MKDIR} ${CARGO_VENDOR_DIR}
.for _crate in ${CARGO_CRATES}
	@${MV} ${WRKDIR}/${_crate} ${CARGO_VENDOR_DIR}/${_crate}
	@${PRINTF} '{"package":"%s","files":{}}' \
		$$(${SHA256} -q ${DISTDIR}/${CARGO_DIST_SUBDIR}/${_crate}.tar.gz) \
		> ${CARGO_VENDOR_DIR}/${_crate}/.cargo-checksum.json
.endfor

.if ${CARGO_USE_GITHUB:tl} == "yes"
_USES_patch+=	600:cargo-patch-github

.for _group in ${GH_TUPLE:C@^[^:]*:[^:]*:[^:]*:(([^:/]*)?)((/.*)?)@\2@}
_CARGO_GH_PATCH_CARGOTOML:= ${_CARGO_GH_PATCH_CARGOTOML} \
	-e 's@git = "(https|http|git)://github.com/${GH_ACCOUNT_${_group}}/${GH_PROJECT_${_group}}(\.git)?"@path = "${WRKSRC_${_group}}"@'
.endfor

cargo-patch-github:
	@${SED} -i.dist -E ${_CARGO_GH_PATCH_CARGOTOML} ${CARGO_GH_CARGOTOML}
.endif

.if !target(do-configure) && ${CARGO_CONFIGURE:tl} == "yes"
# configure hook.  Place a config file for overriding crates-io index
# by local source directory.
do-configure:
	@${MKDIR} ${WRKDIR}/.cargo
	@${ECHO_CMD} "[source.cargo]" > ${WRKDIR}/.cargo/config
	@${ECHO_CMD} "directory = '${CARGO_VENDOR_DIR}'" >> ${WRKDIR}/.cargo/config
	@${ECHO_CMD} "[source.crates-io]" >> ${WRKDIR}/.cargo/config
	@${ECHO_CMD} "replace-with = 'cargo'" >> ${WRKDIR}/.cargo/config
	@if ! ${GREP} -qF '[profile.release]' ${CARGO_CARGOTOML}; then \
		${ECHO_CMD} "" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "[profile.release]" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "opt-level = 2" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "debug = false" >> ${CARGO_CARGOTOML}; \
	fi
	@${CARGO_CARGO_RUN} update \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		${CARGO_UPDATE_ARGS}
.endif

.if !target(do-build) && ${CARGO_BUILD:tl} == "yes"
do-build:
	@${CARGO_CARGO_RUN} build \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		${CARGO_BUILD_ARGS}
.endif

.if !target(do-install) && ${CARGO_INSTALL:tl} == "yes"
do-install:
	@${CARGO_CARGO_RUN} install \
		--root "${STAGEDIR}${PREFIX}" \
		--verbose \
		${CARGO_INSTALL_ARGS}
	@${RM} -- "${STAGEDIR}${PREFIX}/.crates.toml"
.endif

.if !target(do-test) && ${CARGO_TEST:tl} == "yes"
do-test:
	@${CARGO_CARGO_RUN} test \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		${CARGO_TEST_ARGS}
.endif

#
# Helper targets for port maintainers
#

# cargo-crates will output the crates list from Cargo.lock.
cargo-crates: extract
	@${SETENV} USE_GITHUB=${USE_GITHUB} \
		${AWK} -f ${SCRIPTSDIR}/cargo-crates.awk ${CARGO_CARGOLOCK}

# cargo-crates-licenses will try to grab license information from
# all downloaded crates.
cargo-crates-licenses: configure
	@${FIND} ${CARGO_VENDOR_DIR} -name 'Cargo.toml' -maxdepth 2 \
		-exec ${GREP} -H '^license' {} \; \
		| ${SED} \
		-e 's@^${CARGO_VENDOR_DIR}/@@' \
		-e 's@/Cargo.toml:license.*= *"@|@' \
		-e 's@"$$@@g' | /usr/bin/column -t -s '|'
.endif
