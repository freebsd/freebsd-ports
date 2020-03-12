# $FreeBSD$
#
# This file contains logic to ease porting of Rust packages or
# binaries using the `cargo` command.
#
# Feature:	cargo
# Usage:	USES=cargo
# Valid ARGS:	none
#
# MAINTAINER: rust@FreeBSD.org

.if !defined(_INCLUDE_USES_CARGO_MK)
_INCLUDE_USES_CARGO_MK=	yes

.if !empty(cargo_ARGS)
IGNORE+=	USES=cargo takes no arguments
.endif

# List of static dependencies.  The format is cratename-version.
# CARGO_CRATES will be downloaded from MASTER_SITES_CRATESIO.
CARGO_CRATES?=

# List of features to build (space separated list).
# Use special token --no-default-features to disable default
# features by passing it to cargo build/install/test.
CARGO_FEATURES?=

# Name of the local directory for vendoring crates.
CARGO_VENDOR_DIR?=	${WRKSRC}/cargo-crates

# Default path for cargo manifest.
CARGO_CARGOTOML?=	${WRKSRC}/Cargo.toml
CARGO_CARGOLOCK?=	${WRKSRC}/Cargo.lock

# Save crates inside ${DISTDIR}/rust/crates by default.
CARGO_DIST_SUBDIR?=	rust/crates

# Generate list of DISTFILES.
.for _crate in ${CARGO_CRATES}
MASTER_SITES+=	CRATESIO/${_crate:C/^(.*)-[0-9].*/\1/}/${_crate:C/^.*-([0-9].*)/\1/}:cargo_${_crate:C/[^a-zA-Z0-9_]//g}
DISTFILES+=	${CARGO_DIST_SUBDIR}/${_crate}.tar.gz:cargo_${_crate:C/[^a-zA-Z0-9_]//g}
.endfor

# Build dependencies.

CARGO_BUILDDEP?=	yes
.if ${CARGO_BUILDDEP:tl} == "yes"
BUILD_DEPENDS+=	${RUST_DEFAULT}>=1.42.0:lang/${RUST_DEFAULT}
.endif

# Location of cargo binary (default to lang/rust's Cargo binary)
CARGO_CARGO_BIN?=	${LOCALBASE}/bin/cargo

# Location of the cargo output directory.
CARGO_TARGET_DIR?=	${WRKDIR}/target

# Environment for cargo
#  - CARGO_HOME: local cache of the registry index
#  - CARGO_BUILD_JOBS: configure number of jobs to run
#  - CARGO_TARGET_DIR: location of where to place all generated artifacts
#  - RUST_BACKTRACE: produce backtraces when something in the build panics
#  - RUSTC: path of rustc binary (default to lang/rust)
#  - RUSTDOC: path of rustdoc binary (default to lang/rust)
#  - RUSTFLAGS: custom flags to pass to all compiler invocations that Cargo performs
CARGO_ENV+= \
	CARGO_HOME=${WRKDIR}/cargo-home \
	CARGO_BUILD_JOBS=${MAKE_JOBS_NUMBER} \
	CARGO_TARGET_DIR=${CARGO_TARGET_DIR} \
	RUST_BACKTRACE=1 \
	RUSTC=${LOCALBASE}/bin/rustc \
	RUSTDOC=${LOCALBASE}/bin/rustdoc \
	RUSTFLAGS="${RUSTFLAGS} -C linker=${CC:Q} ${LDFLAGS:C/.+/-C link-arg=&/}"

# Adjust -C target-cpu if -march/-mcpu is set by bsd.cpu.mk
.if ${ARCH} == amd64 || ${ARCH} == i386
RUSTFLAGS+=	${CFLAGS:M-march=*:S/-march=/-C target-cpu=/}
.else
RUSTFLAGS+=	${CFLAGS:M-mcpu=*:S/-mcpu=/-C target-cpu=/}
.endif

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv1
USE_GCC?=	yes
.endif

# Helper to shorten cargo calls.
CARGO_CARGO_RUN= \
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO_ENV} \
		${CARGO_CARGO_BIN}

# User arguments for cargo targets.
CARGO_BUILD_ARGS?=
CARGO_INSTALL_ARGS?=
CARGO_INSTALL_PATH?=	.
CARGO_TEST_ARGS?=
CARGO_UPDATE_ARGS?=

# Use module targets ?
CARGO_BUILD?=	yes
CARGO_CONFIGURE?=	yes
CARGO_INSTALL?=	yes
CARGO_TEST?=	yes

# Set CARGO_USE_GIT{HUB,LAB} to yes if your application requires
# some dependencies from git repositories hosted on GitHub or
# GitLab instances.  All Cargo.toml files will be patched to point
# to the right offline sources based on what is defined in
# {GH,GL}_TUPLE.  This makes sure that cargo does not attempt to
# access the network during the build.
CARGO_USE_GITHUB?=	no
CARGO_USE_GITLAB?=	no

# Manage crate features.
.if !empty(CARGO_FEATURES:M--no-default-features)
CARGO_BUILD_ARGS+=	--no-default-features
CARGO_INSTALL_ARGS+=	--no-default-features
CARGO_TEST_ARGS+=	--no-default-features
.endif
.if !empty(CARGO_FEATURES:N--no-default-features)
CARGO_BUILD_ARGS+=	--features='${CARGO_FEATURES:N--no-default-features}'
CARGO_INSTALL_ARGS+=	--features='${CARGO_FEATURES:N--no-default-features}'
CARGO_TEST_ARGS+=	--features='${CARGO_FEATURES:N--no-default-features}'
.endif

.if !defined(WITH_DEBUG)
CARGO_BUILD_ARGS+=	--release
CARGO_TEST_ARGS+=	--release
.else
CARGO_INSTALL_ARGS+=	--debug
.endif

.if ${CARGO_CRATES:Mcmake-[0-9]*}
BUILD_DEPENDS+=	cmake:devel/cmake
.endif

.if ${CARGO_CRATES:Mgettext-sys-[0-9]*}
CARGO_ENV+=	GETTEXT_BIN_DIR=${LOCALBASE}/bin \
		GETTEXT_INCLUDE_DIR=${LOCALBASE}/include \
		GETTEXT_LIB_DIR=${LOCALBASE}/lib
.endif

.if ${CARGO_CRATES:Mjemalloc-sys-[0-9]*}
BUILD_DEPENDS+=	gmake:devel/gmake
.endif

.for libc in ${CARGO_CRATES:Mlibc-[0-9]*}
# FreeBSD 12.0 changed ABI: r318736 and r320043
# https://github.com/rust-lang/libc/commit/78f93220d70e
# https://github.com/rust-lang/libc/commit/969ad2b73cdc
_libc_VER=	${libc:C/.*-//}
. if ${_libc_VER:R:R} == 0 && (${_libc_VER:R:E} < 2 || ${_libc_VER:R:E} == 2 && ${_libc_VER:E} < 38)
DEV_ERROR+=	"CARGO_CRATES=${libc} may be unstable on FreeBSD 12.0. Consider updating to the latest version \(higher than 0.2.37\)."
. endif
. if ${_libc_VER:R:R} == 0 && (${_libc_VER:R:E} < 2 || ${_libc_VER:R:E} == 2 && ${_libc_VER:E} < 49)
DEV_ERROR+=	"CARGO_CRATES=${libc} may be unstable on aarch64 or not build on armv6, armv7, powerpc64. Consider updating to the latest version \(higher than 0.2.49\)."
. endif
.undef _libc_VER
.endfor

.if ${CARGO_CRATES:Mlibgit2-sys-[0-9]*}
# Use the system's libgit2 instead of building the bundled version
CARGO_ENV+=	LIBGIT2_SYS_USE_PKG_CONFIG=1
.endif

.if ${CARGO_CRATES:Mlibssh2-sys-[0-9]*}
# Use the system's libssh2 instead of building the bundled version
CARGO_ENV+=	LIBSSH2_SYS_USE_PKG_CONFIG=1
.endif

.if ${CARGO_CRATES:Monig_sys-[0-9]*}
# onig_sys always prefers the system library but will try to link
# statically with it.  Since devel/oniguruma doesn't provide a static
# library it'll link to libonig.so instead.  Strictly speaking setting
# RUSTONIG_SYSTEM_LIBONIG is not necessary, but will force onig_sys to
# always use the system's libonig as returned by `pkg-config oniguruma`.
CARGO_ENV+=	RUSTONIG_SYSTEM_LIBONIG=1
.endif

.if ${CARGO_CRATES:Mopenssl-0.[0-9].*}
# FreeBSD 12.0 updated base OpenSSL in r339270:
# https://github.com/sfackler/rust-openssl/commit/276577553501
. if !exists(${PATCHDIR}/patch-openssl-1.1.1) # skip if backported
_openssl_VER=	${CARGO_CRATES:Mopenssl-0.[0-9].*:C/.*-//}
.  if ${_openssl_VER:R:R} == 0 && (${_openssl_VER:R:E} < 10 || ${_openssl_VER:R:E} == 10 && ${_openssl_VER:E} < 4)
DEV_WARNING+=	"CARGO_CRATES=openssl-0.10.3 or older do not support OpenSSL 1.1.1. Consider updating to the latest version."
.  endif
. endif
.undef _openssl_VER
.endif

.if ${CARGO_CRATES:Mopenssl-sys-[0-9]*}
# Make sure that openssl-sys can find the correct version of OpenSSL
CARGO_ENV+=	OPENSSL_LIB_DIR=${OPENSSLLIB} \
		OPENSSL_INCLUDE_DIR=${OPENSSLINC}
.endif

.if ${CARGO_CRATES:Mpkg-config-[0-9]*}
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
	@if [ -r ${CARGO_VENDOR_DIR}/${_crate}/Cargo.toml.orig ]; then \
		${MV} ${CARGO_VENDOR_DIR}/${_crate}/Cargo.toml.orig \
			${CARGO_VENDOR_DIR}/${_crate}/Cargo.toml.orig-cargo; \
	fi
.endfor

_CARGO_GIT_PATCH_CARGOTOML=
.if ${CARGO_USE_GITHUB:tl} == "yes"
.  for _group in ${GH_TUPLE:C@^[^:]*:[^:]*:[^:]*:(([^:/]*)?)((/.*)?)@\2@}
.    if empty(CARGO_GIT_SUBDIR:M${_group}\:*)
_CARGO_GIT_PATCH_CARGOTOML:= ${_CARGO_GIT_PATCH_CARGOTOML} \
	-e "s@git = ['\"](https|http|git)://github.com/${GH_ACCOUNT_${_group}}/${GH_PROJECT_${_group}}(\.git)?/?[\"']@path = \"${WRKSRC_${_group}}\"@"
.    else
.      for _group2 _crate _subdir in ${CARGO_GIT_SUBDIR:M${_group}\:*:S,:, ,g}
_CARGO_GIT_PATCH_CARGOTOML:= ${_CARGO_GIT_PATCH_CARGOTOML} \
	-e "/^${_crate} =/ s@git = ['\"](https|http|git)://github.com/${GH_ACCOUNT_${_group}}/${GH_PROJECT_${_group}}(\.git)?/?[\"']@path = \"${WRKSRC_${_group}}/${_subdir}\"@"
.	endfor
.    endif
.  endfor
.endif
.if ${CARGO_USE_GITLAB:tl} == "yes"
.  for _group in ${GL_TUPLE:C@^(([^:]*://[^:/]*(:[0-9]{1,5})?(/[^:]*[^/])?:)?)([^:]*):([^:]*):([^:]*)(:[^:/]*)((/.*)?)@\8@:S/^://}
.    if empty(CARGO_GIT_SUBDIR:M${_group}\:*)
_CARGO_GIT_PATCH_CARGOTOML:= ${_CARGO_GIT_PATCH_CARGOTOML} \
	-e "s@git = ['\"]${GL_SITE_${_group}}/${GL_ACCOUNT_${_group}}/${GL_PROJECT_${_group}}(\.git)?/?['\"]@path = \"${WRKSRC_${_group}}\"@"
.    else
.      for _group2 _crate _subdir in ${CARGO_GIT_SUBDIR:M${_group}\:*:S,:, ,g}
_CARGO_GIT_PATCH_CARGOTOML:= ${_CARGO_GIT_PATCH_CARGOTOML} \
	-e "/^${_crate} = / s@git = ['\"]${GL_SITE_${_group}}/${GL_ACCOUNT_${_group}}/${GL_PROJECT_${_group}}(\.git)?/?['\"]@path = \"${WRKSRC_${_group}}/${_subdir}\"@"
.      endfor
.    endif
.  endfor
.endif

.if !empty(_CARGO_GIT_PATCH_CARGOTOML)
_USES_patch+=	600:cargo-patch-git

cargo-patch-git:
	@${FIND} ${WRKDIR} -name Cargo.toml -type f -exec \
		${SED} -i.dist -E ${_CARGO_GIT_PATCH_CARGOTOML} {} +
.endif

.if ${CARGO_CONFIGURE:tl} == "yes"
_USES_configure+=	250:cargo-configure

# configure hook.  Place a config file for overriding crates-io index
# by local source directory.
cargo-configure:
# Check that the running kernel has COMPAT_FREEBSD11 required by lang/rust post-ino64
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh
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
.  for path in ${CARGO_INSTALL_PATH}
	@${CARGO_CARGO_RUN} install \
		--no-track \
		--path "${path}" \
		--root "${STAGEDIR}${PREFIX}" \
		--verbose \
		${CARGO_INSTALL_ARGS}
.  endfor
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

# cargo-crates will output the crates list from Cargo.lock.  If there
# is no Cargo.lock for some reason, try and generate it first.
cargo-crates: extract
	@if [ ! -r "${CARGO_CARGOLOCK}" ]; then \
		${ECHO_MSG} "===> ${CARGO_CARGOLOCK} not found.  Trying to generate it..."; \
		${CARGO_CARGO_RUN} generate-lockfile \
			--manifest-path ${CARGO_CARGOTOML} \
			--verbose; \
	fi
	@${SETENV} USE_GITHUB=${USE_GITHUB} USE_GITLAB=${USE_GITLAB} GL_SITE=${GL_SITE} \
		${AWK} -f ${SCRIPTSDIR}/cargo-crates.awk ${CARGO_CARGOLOCK}

# cargo-crates-licenses will try to grab license information from
# all downloaded crates.
cargo-crates-licenses: configure
	@${FIND} ${CARGO_VENDOR_DIR} -name 'Cargo.toml' -maxdepth 2 \
		-exec ${GREP} -H '^license' {} \; \
		| ${SED} \
		-e 's@^${CARGO_VENDOR_DIR}/@@' \
		-e 's@/Cargo.toml:license.*= *"@|@' \
		-e 's@"$$@@g' | sort | /usr/bin/column -t -s '|'
.endif
