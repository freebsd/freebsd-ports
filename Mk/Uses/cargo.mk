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

.  if !empty(cargo_ARGS)
IGNORE+=	USES=cargo takes no arguments
.  endif

.sinclude "${MASTERDIR}/Makefile.crates"

# List of static dependencies.  The format is cratename-version.
# CARGO_CRATES will be downloaded from MASTER_SITE_CRATESIO.
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
# Prefer canonical file extension .crate going forward
.  if make(makesum)
CARGO_CRATE_EXT=	.crate
.  else
# If there is a rust/crates/*.tar.gz in distinfo keep using the old
# extension.  We need to delay eval until the last moment for
# DISTINFO_FILE.  We cache the command output to avoid multiple
# slow grep runs for every CARGO_CRATE_EXT access.
CARGO_CRATE_EXT=	${defined(_CARGO_CRATE_EXT_CACHE):?${_CARGO_CRATE_EXT_CACHE}:${:!if ${GREP} -q '\(${CARGO_DIST_SUBDIR}/.*\.tar\.gz\)' "${DISTINFO_FILE}" 2>/dev/null; then ${ECHO_CMD} .tar.gz; else ${ECHO_CMD} .crate; fi!:_=_CARGO_CRATE_EXT_CACHE}}
.  endif

_CARGO_CRATES:=		${CARGO_CRATES:N*@git+*}
_CARGO_GIT_SOURCES:=	${CARGO_CRATES:M*@git+*}
# enumerate crates for unqiue and sane distfile group names
_CARGO_CRATES:=		${empty(_CARGO_CRATES):?:${_CARGO_CRATES:range:@i@$i ${_CARGO_CRATES:[$i]}@}}
# split up crates into (index, crate, name, version) 4-tuples
_CARGO_CRATES:=		${_CARGO_CRATES:C/^([-_a-zA-Z0-9]+)-([0-9].*)/\0 \1 \2/}

.  for _index _crate _name _version in ${_CARGO_CRATES}
# Resolving CRATESIO alias is very inefficient with many MASTER_SITES, consume MASTER_SITE_CRATESIO directly
MASTER_SITES+=	${MASTER_SITE_CRATESIO:S,%SUBDIR%,${_name}/${_version},:S,$,:_cargo_${_index},}
DISTFILES+=	${CARGO_DIST_SUBDIR}/${_crate}${CARGO_CRATE_EXT}:_cargo_${_index}

# Provide pointer to the crate's extraction dir
WRKSRC_crate_${_name}=	${CARGO_VENDOR_DIR}/${_crate}
# ...  also with version suffix in case of multiple versions of the
# same crate
WRKSRC_crate_${_crate}=	${CARGO_VENDOR_DIR}/${_crate}
.  endfor

_CARGO_AWK=	${AWK} -vCP="${CP}" -vFIND="${FIND}" -vGREP="${GREP}" \
		-vCARGO_VENDOR_DIR="${CARGO_VENDOR_DIR}" \
		-vGIT_SOURCES="${_CARGO_GIT_SOURCES}" \
		-vWRKDIR="${WRKDIR}" -vWRKSRC="${WRKSRC}" \
		-f${SCRIPTSDIR}/split-url.awk \
		-f${SCRIPTSDIR}/cargo-crates-git-common.awk -f

.  if !empty(_CARGO_GIT_SOURCES)
.    for _index _site _filename _wrksrc _crates in ${:!${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates-git-fetch.awk /dev/null!}
MASTER_SITES+=	${_site}:_cargo_git${_index}
DISTFILES+=	${_filename}:_cargo_git${_index}
.      for _crate in ${_crates:S/,/ /g}
# Make sure the build dependencies checks below can work for git sourced crates too
_CARGO_CRATES+=	@git ${_crate} ${_crate} @git

# Provide pointer to the crate's extraction dir
#
# This might not point to the actual crate's sources since a
# single git source can contain multiple crates.  We cannot collect
# subdir information until after the full extraction is done and we
# cannot set make variables at that point.  This is better than
# nothing.
WRKSRC_crate_${_crate}=	${WRKDIR}/${_wrksrc}
.      endfor
.    endfor
.  endif

# Build dependencies.

CARGO_BUILDDEP?=	yes
.  if ${CARGO_BUILDDEP:tl} == "yes"
BUILD_DEPENDS+=	${RUST_DEFAULT}>=1.89.0:lang/${RUST_DEFAULT}
.  elif ${CARGO_BUILDDEP:tl} == "any-version"
BUILD_DEPENDS+=	${RUST_DEFAULT}>=0:lang/${RUST_DEFAULT}
.  endif

# Location of toolchain (default to lang/rust's toolchain)
CARGO?=		${LOCALBASE}/bin/cargo
RUSTC?=		${LOCALBASE}/bin/rustc
RUSTDOC?=	${LOCALBASE}/bin/rustdoc

# Location of the cargo output directory.
CARGO_TARGET_DIR?=	${WRKDIR}/target

_CARGO_RUST_ARCH_amd64=		x86_64
_CARGO_RUST_ARCH_i386=		i686
_CARGO_RUST_ARCH_riscv64=	riscv64gc

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
	RUSTC=${RUSTC} \
	RUSTDOC=${RUSTDOC} \
	RUSTFLAGS="${RUSTFLAGS} -C ar=${AR} -C linker=${CC} ${LDFLAGS:C/.+/-C link-args=&/}"

.  if ${ARCH} != powerpc64le
CARGO_ENV+=	RUST_BACKTRACE=1
.  endif

.  if !defined(WITHOUT_LTO)
_CARGO_MSG=	"===>   Additional optimization to port applied"
WITH_LTO=	yes
.  endif

# Adjust -C target-cpu if -march/-mcpu is set by bsd.cpu.mk
.  if ${ARCH} == amd64 || ${ARCH} == i386
RUSTFLAGS+=	${CFLAGS:M-march=*:S/-march=/-C target-cpu=/}
.  elif ${ARCH:Mpowerpc*}
RUSTFLAGS+=	${CFLAGS:M-mcpu=*:S/-mcpu=/-C target-cpu=/:S/power/pwr/}
.  elif ${ARCH} == aarch64 || ${ARCH} == armv7
RUSTFLAGS+=	-C target-cpu=${CPUTYPE:C/\+.+//g}
.  else
RUSTFLAGS+=	${CFLAGS:M-mcpu=*:S/-mcpu=/-C target-cpu=/}
.  endif

# Helper to shorten cargo calls.
_CARGO_RUN=		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CARGO_ENV} ${CARGO}
CARGO_CARGO_RUN=	cd ${WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CARGO_ENV} \
			CARGO_FREEBSD_PORTS_SKIP_GIT_UPDATE=1 ${CARGO}

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

# rustc stashes intermediary files in TMPDIR (default /tmp) which
# might cause issues for users that for some reason space limit
# their /tmp.  WRKDIR should have plenty of space.
# Allow users and ports to still overwrite it.
.  if ${TMPDIR:U/tmp} == /tmp
TMPDIR=		${WRKDIR}
.  endif

# Manage crate features.
.  if !empty(CARGO_FEATURES:M--no-default-features)
CARGO_BUILD_ARGS+=	--no-default-features
CARGO_INSTALL_ARGS+=	--no-default-features
CARGO_TEST_ARGS+=	--no-default-features
.  endif
.  if !empty(CARGO_FEATURES:N--no-default-features)
CARGO_BUILD_ARGS+=	--features='${CARGO_FEATURES:N--no-default-features}'
CARGO_INSTALL_ARGS+=	--features='${CARGO_FEATURES:N--no-default-features}'
CARGO_TEST_ARGS+=	--features='${CARGO_FEATURES:N--no-default-features}'
.  endif

.  if !defined(WITH_DEBUG)
CARGO_BUILD_ARGS+=	--release
CARGO_TEST_ARGS+=	--release
.  else
CARGO_INSTALL_ARGS+=	--debug
.  endif

.  if ${_CARGO_CRATES:Mcmake}
BUILD_DEPENDS+=	cmake:devel/cmake-core
.  endif

.  if ${_CARGO_CRATES:Mgettext-sys}
CARGO_ENV+=	GETTEXT_BIN_DIR=${LOCALBASE}/bin \
		GETTEXT_INCLUDE_DIR=${LOCALBASE}/include \
		GETTEXT_LIB_DIR=${LOCALBASE}/lib
.  endif

.  if ${_CARGO_CRATES:Mjemalloc-sys}
BUILD_DEPENDS+=	gmake:devel/gmake
.  endif

.  if ${_CARGO_CRATES:Mlibgit2-sys}
# Use the system's libgit2 instead of building the bundled version
CARGO_ENV+=	LIBGIT2_SYS_USE_PKG_CONFIG=1
.  endif

.  if ${_CARGO_CRATES:Mlibssh2-sys}
# Use the system's libssh2 instead of building the bundled version
CARGO_ENV+=	LIBSSH2_SYS_USE_PKG_CONFIG=1
.  endif

.  if ${_CARGO_CRATES:Monig_sys}
# onig_sys always prefers the system library but will try to link
# statically with it.  Since devel/oniguruma doesn't provide a static
# library it'll link to libonig.so instead.  Strictly speaking setting
# RUSTONIG_SYSTEM_LIBONIG is not necessary, but will force onig_sys to
# always use the system's libonig as returned by `pkg-config oniguruma`.
CARGO_ENV+=	RUSTONIG_SYSTEM_LIBONIG=1
.  endif

.  if ${_CARGO_CRATES:Mopenssl-src}
DEV_WARNING+=	"Please make sure this port uses the system OpenSSL and consider removing CARGO_CRATES=${CARGO_CRATES:Mopenssl-src-[0-9]*} (a vendored copy of OpenSSL) from the build, e.g., by patching Cargo.toml appropriately."
.  endif

.  if ${_CARGO_CRATES:Mopenssl-sys}
# Make sure that openssl-sys can find the correct version of OpenSSL
CARGO_ENV+=	OPENSSL_LIB_DIR=${OPENSSLLIB} \
		OPENSSL_INCLUDE_DIR=${OPENSSLINC}
.  endif

.  if ${_CARGO_CRATES:Mpkg-config}
.include "${USESDIR}/pkgconfig.mk"
.  endif

.  if ${_CARGO_CRATES:Mzstd-sys}
# Use the system's zstd instead of building the bundled version
CARGO_ENV+=	ZSTD_SYS_USE_PKG_CONFIG=1
.  endif

.  for _index _crate _name _version in ${_CARGO_CRATES}
# Split up semantic version and try to sanitize it by removing
# pre-release identifier (-) or build metadata (+)
.    if ${_version:S/./ /:S/./ /:C/[-+].*//:_:[#]} == 3
.      for _major _minor _patch in $_
# FreeBSD 12.0 changed ABI: r318736 and r320043
# https://github.com/rust-lang/libc/commit/78f93220d70e
# https://github.com/rust-lang/libc/commit/969ad2b73cdc
.        if ${_name} == libc && ${_major} == 0 && (${_minor} < 2 || (${_minor} == 2 && ${_patch} < 38))
DEV_ERROR+=	"CARGO_CRATES=${_crate} may be unstable on FreeBSD 12.0. Consider updating to the latest version \(higher than 0.2.37\)."
.        endif
.        if ${_name} == libc && ${_major} == 0 && (${_minor} < 2 || (${_minor} == 2 && ${_patch} < 49))
DEV_ERROR+=	"CARGO_CRATES=${_crate} may be unstable on aarch64 or not build on armv6, armv7, powerpc64. Consider updating to the latest version \(higher than 0.2.49\)."
.        endif
# FreeBSD 12.0 updated base OpenSSL in r339270:
# https://github.com/sfackler/rust-openssl/commit/276577553501
.        if ${_name} == openssl && !exists(${PATCHDIR}/patch-openssl-1.1.1) && ${_major} == 0 && (${_minor} < 10 || (${_minor} == 10 && ${_patch} < 4))
DEV_WARNING+=	"CARGO_CRATES=${_crate} does not support OpenSSL 1.1.1. Consider updating to the latest version \(higher than 0.10.3\)."
.        endif
.      endfor
.    endif
.  endfor

_USES_extract+=	600:cargo-extract
cargo-extract:
# target for preparing crates directory.  It will put all crates in
# the local crates directory.
	@${ECHO_MSG} "===>  Moving crates to ${CARGO_VENDOR_DIR}"
	@${MKDIR} ${CARGO_VENDOR_DIR}
.  for _index _crate _name _version in ${_CARGO_CRATES}
.    if ${_index} != @git
	@${MV} ${WRKDIR}/${_crate} ${CARGO_VENDOR_DIR}/${_crate}
	@${PRINTF} '{"package":"%s","files":{}}' \
		$$(${SHA256} -q ${_DISTDIR}/${CARGO_DIST_SUBDIR}/${_crate}${CARGO_CRATE_EXT}) \
		> ${CARGO_VENDOR_DIR}/${_crate}/.cargo-checksum.json
	@if [ -r ${CARGO_VENDOR_DIR}/${_crate}/Cargo.toml.orig ]; then \
		${MV} ${CARGO_VENDOR_DIR}/${_crate}/Cargo.toml.orig \
			${CARGO_VENDOR_DIR}/${_crate}/Cargo.toml.orig-cargo; \
	fi
.    endif
.  endfor

.  if ${CARGO_CONFIGURE:tl} == "yes"
_USES_configure+=	250:cargo-configure

# configure hook.  Place a config file for overriding crates-io index
# by local source directory.
cargo-configure:
# Check that the running kernel has COMPAT_FREEBSD11 required by lang/rust post-ino64
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh
.    if defined(_CARGO_MSG)
	@${ECHO_MSG} ${_CARGO_MSG}
.    endif
	@${ECHO_MSG} "===>   Cargo config:"
	@${MKDIR} ${WRKDIR}/.cargo
	@: > ${WRKDIR}/.cargo/config.toml
	@${ECHO_CMD} "[source.cargo]" >> ${WRKDIR}/.cargo/config.toml
	@${ECHO_CMD} "directory = '${CARGO_VENDOR_DIR}'" >> ${WRKDIR}/.cargo/config.toml
	@${ECHO_CMD} "[source.crates-io]" >> ${WRKDIR}/.cargo/config.toml
	@${ECHO_CMD} "replace-with = 'cargo'" >> ${WRKDIR}/.cargo/config.toml
.    if !empty(_CARGO_GIT_SOURCES)
	@${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates-git-configure.awk \
		/dev/null >> ${WRKDIR}/.cargo/config.toml
.    endif
	@${CAT} ${WRKDIR}/.cargo/config.toml
	@if ! ${GREP} -qF '[profile.release]' ${CARGO_CARGOTOML}; then \
		${ECHO_CMD} "" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "[profile.release]" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "opt-level = 2" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "debug = false" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} 'strip = "symbols"' >> ${CARGO_CARGOTOML}; \
	fi
	@${ECHO_MSG} "===>   Updating Cargo.lock"
	@${CARGO_CARGO_RUN} update \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		--verbose \
		${CARGO_UPDATE_ARGS}
.  endif

.  if !target(do-build) && ${CARGO_BUILD:tl} == "yes"
do-build:
	@${CARGO_CARGO_RUN} build \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}
.  endif

.  if !target(do-install) && ${CARGO_INSTALL:tl} == "yes"
do-install:
.    for path in ${CARGO_INSTALL_PATH}
	@${CARGO_CARGO_RUN} install \
		--no-track \
		--path "${path}" \
		--root "${STAGEDIR}${PREFIX}" \
		--verbose \
		--verbose \
		${CARGO_INSTALL_ARGS}
.    endfor
.  endif

.  if !target(do-test) && ${CARGO_TEST:tl} == "yes"
do-test:
	@${CARGO_CARGO_RUN} test \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		--verbose \
		${CARGO_TEST_ARGS}
.  endif

#
# Helper targets for port maintainers
#

# cargo-audit generates a vulnerability report using
# security/cargo-audit based on the crates in Cargo.lock.
cargo-audit: configure
	@if ! type cargo-audit > /dev/null 2>&1; then \
		${ECHO_MSG} "===> Please install \"security/cargo-audit\""; exit 1; \
	fi
	@${ECHO_MSG} "===> Checking for vulnerable crates"
	@${CARGO} audit --file ${CARGO_CARGOLOCK}

# cargo-crates will output the crates list from Cargo.lock.  If there
# is no Cargo.lock for some reason, try and generate it first.
cargo-crates: cargo-crates-generate-lockfile
	@${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates.awk ${CARGO_CARGOLOCK}

# cargo-crates-generate-lockfile will try to generate a Cargo.lock file
# if it does not exist.
cargo-crates-generate-lockfile: extract
	@if [ ! -r "${CARGO_CARGOLOCK}" ]; then \
		${ECHO_MSG} "===> ${CARGO_CARGOLOCK} not found.  Trying to generate it..."; \
		cd ${CARGO_CARGOLOCK:H}; ${_CARGO_RUN} generate-lockfile \
			--manifest-path ${CARGO_CARGOTOML} \
			--verbose; \
	fi

# cargo-crates-licenses will try to grab license information from
# all downloaded crates.
cargo-crates-licenses: configure
	@${FIND} ${CARGO_VENDOR_DIR} -name 'Cargo.toml' -maxdepth 2 \
		-exec ${GREP} -H '^license' {} \; \
		| ${SED} \
		-e 's@^${CARGO_VENDOR_DIR}/@@' \
		-e 's@/Cargo.toml:license.*= *"@|@' \
		-e 's@"$$@@g' | sort | /usr/bin/column -t -s '|'

# cargo-crates-merge will in-place update CARGO_CRATES in the port
# based on the crates list from Cargo.lock.  If there is no Cargo.lock
# for some reason, try and generate it first.
cargo-crates-merge:
	@if ! type portedit > /dev/null 2>&1; then \
		${ECHO_MSG} "===> Please install \"ports-mgmt/portfmt\""; exit 1; \
	fi
	@${MAKE} clean cargo-crates-generate-lockfile
	@f="${MASTERDIR}/Makefile"; [ -r "${MASTERDIR}/Makefile.crates" ] && f="${MASTERDIR}/Makefile.crates"; \
		${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates.awk ${CARGO_CARGOLOCK} | \
			portedit merge -i $$f; \
		${MAKE} clean makesum; \
		${ECHO_MSG} "${DISTINFO_FILE} and CARGO_CRATES in $$f were updated";

.endif
