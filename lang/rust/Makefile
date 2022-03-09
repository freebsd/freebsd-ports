# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>

PORTNAME=	rust
PORTVERSION?=	1.59.0
PORTREVISION?=	0
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/:src \
		https://dev-static.rust-lang.org/dist/:src \
		LOCAL/tobik/rust:bootstrap \
		LOCAL/mikael/rust:bootstrap \
		https://static.rust-lang.org/dist/:bootstrap
DISTNAME?=	${PORTNAME}c-${PORTVERSION}-src
DISTFILES?=	${NIGHTLY_DATE:D${NIGHTLY_DATE}/}${DISTNAME}${EXTRACT_SUFX}:src \
		${_RUSTC_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}${EXTRACT_SUFX}:bootstrap \
		${_RUST_STD_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}${EXTRACT_SUFX}:bootstrap \
		${_CARGO_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}${EXTRACT_SUFX}:bootstrap
DIST_SUBDIR?=	rust

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Language with a focus on memory safety and concurrency

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

IGNORE_FreeBSD_12_powerpc=	is missing a bootstrap for FreeBSD 12.x powerpc
ONLY_FOR_ARCHS?=	aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le \
			powerpc riscv64
ONLY_FOR_ARCHS_REASON?=	requires prebuilt bootstrap compiler

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cpe ninja:build pkgconfig python:3.6+,build ssl tar:xz

CPE_VENDOR=	rust-lang

MAKE_ENV=	DESTDIR=${STAGEDIR} \
		LIBGIT2_NO_PKG_CONFIG=1 \
		OPENSSL_DIR="${OPENSSLBASE}" \
		RUST_BACKTRACE=1
TEST_ENV=	${MAKE_ENV} \
		ALLOW_NONZERO_RLIMIT_CORE=1

CONFLICTS_INSTALL?=	rust-nightly

# rustc stashes intermediary files in TMPDIR (default /tmp) which
# might cause issues for users that for some reason space limit
# their /tmp.  WRKDIR should have plenty of space.
# ?= to allow users to still overwrite it in make.conf.
TMPDIR?=	${WRKDIR}

OPTIONS_DEFINE=		DOCS GDB SOURCES WASM
OPTIONS_DEFAULT=	SOURCES WASM
OPTIONS_EXCLUDE_armv6=	DOCS

GDB_DESC=	Install ports gdb (necessary for debugging rust programs)
SOURCES_DESC=	Install source files
WASM_DESC=	Build the WebAssembly target (wasm32-unknown-unknown)

DOCS_VARS=		_RUST_BUILD_DOCS=true
DOCS_VARS_OFF=		_RUST_BUILD_DOCS=false
GDB_RUN_DEPENDS=	${LOCALBASE}/bin/gdb:devel/gdb
SOURCES_VARS=		_RUST_TOOLS+=src
WASM_VARS=		_RUST_BUILD_WASM=true \
			_RUST_TARGETS+=wasm32-unknown-unknown
WASM_VARS_OFF=		_RUST_BUILD_WASM=false

# See WRKSRC/src/stage0.json for the date and version values
BOOTSTRAPS_DATE?=		2022-01-20
RUST_BOOTSTRAP_VERSION?=	1.58.1

BOOTSTRAPS_SUFFIX?=		${BOOTSTRAPS_SUFFIX_${ARCH}}
BOOTSTRAPS_SUFFIX_powerpc64?=	-${PPC_ABI:tl}

CARGO_VENDOR_DIR?=		${WRKSRC}/vendor

# Rust's target arch string might be different from *BSD arch strings
_RUST_ARCH_amd64=	x86_64
_RUST_ARCH_i386=	i686
_RUST_ARCH_riscv64=	riscv64gc
_RUST_TARGET=		${_RUST_ARCH_${ARCH}:U${ARCH}}-unknown-${OPSYS:tl}
_RUST_TARGETS=		${_RUST_TARGET}
_RUST_TOOLS=		analysis cargo clippy rustfmt

_RUSTC_BOOTSTRAP=	${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/rustc-${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}}-${_RUST_TARGET}
_RUST_STD_BOOTSTRAP=	${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/rust-std-${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}}-${_RUST_TARGET}
_CARGO_BOOTSTRAP=	${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/cargo-${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}}-${_RUST_TARGET}

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		is only for FreeBSD
.endif

.if ${ARCH} == powerpc
# bfd to link rustc_driver; lld currently can't
BUILD_DEPENDS+=	ld.bfd:devel/binutils
.else
# rls needs 64-bit atomics
_RUST_TOOLS+=	rls
.endif

.if exists(${PATCHDIR}/${ARCH}${BOOTSTRAPS_SUFFIX})
EXTRA_PATCHES+=	${PATCHDIR}/${ARCH}${BOOTSTRAPS_SUFFIX}
.endif

# If the kernel does not return sane kern.proc.pathname values
# for hardlinks then disable hardlinks in the build to avoid
# intermittent "can't find crate for `std`" build failures,
# c.f. PR248184
#
# XXX: Avoiding OSVERSION since it is derived from userland but
# the running kernel might still be newer with sane behavior
# anyway...
.if exists(${PATCHDIR}/no-hardlinks)
_KERN_OSRELDATE!=	${SYSCTL} -n kern.osreldate 2>/dev/null || echo 0
.  if ${_KERN_OSRELDATE} >= 1400040
.  elif ${_KERN_OSRELDATE} >= 1300521
.  else
EXTRA_PATCHES+=		${PATCHDIR}/no-hardlinks
.  endif
.endif

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv1
# The bootstrap is hardcoded to use gcc9
# but we can build with a newer or older compiler as provided by USE_GCC=yes
BUILD_DEPENDS+=	gcc9:lang/gcc9
USE_GCC=	yes
STRIP_CMD=	${LOCALBASE}/bin/strip # unsupported e_type with base strip
.endif

.ifdef QEMU_EMULATING
IGNORE=	fails to build with qemu-user-static
.endif

.if make(makesum)
DISTFILES:=	${DISTFILES:M*\:src} \
		${ONLY_FOR_ARCHS:O:@_arch@${:!${MAKE} ARCH=${_arch} PPC_ABI=ELFv1 -V'DISTFILES:N*\:src'!}@} \
		${ONLY_FOR_ARCHS:Mpowerpc64:@_arch@${:!${MAKE} ARCH=${_arch} PPC_ABI=ELFv2 -V'DISTFILES:N*\:src'!}@}
.endif

post-patch:
	@${REINPLACE_CMD} 's,gdb,${LOCALBASE}/bin/gdb,' ${WRKSRC}/src/etc/rust-gdb
.if defined(NIGHTLY_DATE)
	@${REINPLACE_CMD} 's/"rustfmt"/"nothx"/' ${WRKSRC}/src/stage0.json
.endif
# Disable vendor checksums
	@${REINPLACE_CMD} 's,"files":{[^}]*},"files":{},' \
		${CARGO_VENDOR_DIR}/*/.cargo-checksum.json
.if defined(PPC_ABI) && ${PPC_ABI} == ELFv1
	@${REINPLACE_CMD} 's,%CC%,${CC},g' \
		${WRKSRC}/compiler/rustc_llvm/build.rs \
		${WRKSRC}/src/bootstrap/native.rs
.if ${LOCALBASE} != /usr/local
	@${REINPLACE_CMD} 's,/usr/local/,${LOCALBASE}/,g' \
		${WRKSRC}/compiler/rustc_llvm/build.rs \
		${WRKSRC}/src/bootstrap/native.rs
.endif
.endif

do-configure:
# Check that the running kernel has COMPAT_FREEBSD11 required by lang/rust post-ino64
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh
.for _component in cargo rust-std rustc
	@cd ${WRKDIR}/${_component}-*-${OPSYS:tl} && \
		${SH} install.sh --prefix=${WRKDIR}/bootstrap --verbose
.endfor
	@${ECHO_CMD} 'changelog-seen=2' > ${WRKSRC}/config.toml
	@${ECHO_CMD} '[build]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'build-dir="${WRKDIR}/_build"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'build-stage=2' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'doc-stage=2' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'test-stage=2' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'vendor=true' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'extended=true' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'python="${PYTHON_CMD}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'docs=${_RUST_BUILD_DOCS}' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'verbose=2' >> ${WRKSRC}/config.toml
.if defined(NIGHTLY_DATE)
	@${ECHO_CMD} 'profiler=true' >> ${WRKSRC}/config.toml
.endif
	@${ECHO_CMD} 'target=[${_RUST_TARGETS:@.target.@"${.target.}"@:ts,}]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cargo="${WRKDIR}/bootstrap/bin/cargo"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'rustc="${WRKDIR}/bootstrap/bin/rustc"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'tools=[${_RUST_TOOLS:@.tool.@"${.tool.}"@:ts,}]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} '[install]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'prefix="${PREFIX}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'sysconfdir="${PREFIX}/etc"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} '[rust]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'channel="${PKGNAMESUFFIX:Ustable:S/^-//}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'default-linker="${CC}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'deny-warnings=false' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'verbose-tests=true' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'lld=${_RUST_BUILD_WASM}' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} '[llvm]' >> ${WRKSRC}/config.toml
.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
	@${ECHO_CMD} 'ccache="${CCACHE_BIN}"' >> ${WRKSRC}/config.toml
.else
	@${ECHO_CMD} 'ccache=false' >> ${WRKSRC}/config.toml
.endif
	@${ECHO_CMD} 'ninja=true' >> ${WRKSRC}/config.toml
.if ${ARCH} == powerpc
# Rust doesn't call the system compiler with the full version of the target.
# This makes powerpc miscompile due to the secure-plt ABI change.
# Additionally, force using ld.bfd to work around a linking problem in rustc_mir
	@${PRINTF} '#!/bin/sh\nexec ${CC} "$$@" --target=powerpc-unknown-freebsd13.0' > ${WRKDIR}/cc-wrapper
	@${CHMOD} +x ${WRKDIR}/cc-wrapper
	@${PRINTF} '#!/bin/sh\nexec ${CXX} "$$@" --target=powerpc-unknown-freebsd13.0' > ${WRKDIR}/cxx-wrapper
	@${CHMOD} +x ${WRKDIR}/cxx-wrapper
	@${PRINTF} '#!/bin/sh\nexec ${CC} -fuse-ld=bfd "$$@" --target=powerpc-unknown-freebsd13.0' > ${WRKDIR}/ld-wrapper
	@${CHMOD} +x ${WRKDIR}/ld-wrapper
.endif
.for _target in ${_RUST_TARGETS}
	@${ECHO_CMD} '[target.${_target}]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'ar="${AR}"' >> ${WRKSRC}/config.toml
.if ${ARCH} == powerpc
	@${ECHO_CMD} 'cc="${WRKDIR}/cc-wrapper"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cxx="${WRKDIR}/cxx-wrapper"' >> ${WRKSRC}/config.toml
.else
	@${ECHO_CMD} 'cc="${CC}"' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'cxx="${CXX}"' >> ${WRKSRC}/config.toml
.endif
.if ${ARCH} == powerpc
	@${ECHO_CMD} 'linker="${WRKDIR}/ld-wrapper"' >> ${WRKSRC}/config.toml
.else
	@${ECHO_CMD} 'linker="${CC}"' >> ${WRKSRC}/config.toml
.endif
.endfor
	@${ECHO_CMD} '[dist]' >> ${WRKSRC}/config.toml
	@${ECHO_CMD} 'src-tarball=false' >> ${WRKSRC}/config.toml
.if defined(NIGHTLY_DATE)
# Don't abort if optional tools fail to build
	@${ECHO_CMD} 'missing-tools=true' >> ${WRKSRC}/config.toml
.endif

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} x.py build --jobs=${MAKE_JOBS_NUMBER}

do-install:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} x.py install --jobs=${MAKE_JOBS_NUMBER}
# We autogenerate the plist file.  We do that, instead of the
# regular pkg-plist, because several libraries have a computed
# filename based on the absolute path of the source files.  As it
# is user-specific, we cannot know their filename in advance.
	@${RM} -r ${STAGEDIR}${DOCSDIR}/*.old \
		${STAGEDIR}${DOCSDIR}/html/.lock \
		${STAGEDIR}${DOCSDIR}/html/.stamp \
		${STAGEDIR}${PREFIX}/lib/rustlib/install.log \
		${STAGEDIR}${PREFIX}/lib/rustlib/manifest-* \
		${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh
	@${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib \
		${STAGEDIR}${PREFIX}/libexec -exec ${FILE} -i {} + | \
		${AWK} -F: '/executable|sharedlib/ { print $$1 }' | ${XARGS} ${STRIP_CMD}
	@${FIND} ${STAGEDIR}${PREFIX} -not -type d | \
		${SED} -E -e 's,^${STAGEDIR}${PREFIX}/,,' \
			-e 's,(share/man/man[1-9]/.*\.[0-9]),\1.gz,' >> ${TMPPLIST}

post-install-DOCS-on:
# Ignore any left behind empty directories in case some docs fail
# to build (failures are ignored due to deny-warnings=false).
	@${FIND} ${STAGEDIR}${DOCSDIR}/html -empty -type d | \
		${SED} 's,^${STAGEDIR},@comment @dir ,' >> ${TMPPLIST}

post-install-SOURCES-on:
# Silence stage-qa warnings by sanitizing permissions on sources
	@${FIND} ${STAGEDIR}${PREFIX}/lib/rustlib/src -type f -exec ${CHMOD} \
		${SHAREMODE} {} +

# Note that make test does not work when rust is already installed.
do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} x.py test --jobs=${MAKE_JOBS_NUMBER}

.include <bsd.port.post.mk>
