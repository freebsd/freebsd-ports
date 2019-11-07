# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION?=	1.39.0
PORTREVISION?=	0
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/:src \
		https://static.rust-lang.org/dist/:rust_bootstrap \
		LOCAL/tobik/rust:rust_bootstrap \
		https://static.rust-lang.org/dist/:cargo_bootstrap \
		LOCAL/tobik/rust:cargo_bootstrap \
		https://releases.llvm.org/${COMPILER_RT_VERSION}/:compiler_rt \
		https://github.com/llvm/llvm-project/releases/download/llvmorg-${COMPILER_RT_VERSION}/:compiler_rt
DISTNAME?=	${PORTNAME}c-${PORTVERSION}-src
DISTFILES?=	${NIGHTLY_SUBDIR}${DISTNAME}${EXTRACT_SUFX}:src \
		${_RUSTC_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}.tar.gz:rust_bootstrap \
		${_RUST_STD_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}.tar.gz:rust_bootstrap \
		${_CARGO_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}.tar.gz:cargo_bootstrap \
		${DISTFILES_${ARCH}}
DISTFILES_armv6=	compiler-rt-${COMPILER_RT_VERSION}.src.tar.xz:compiler_rt
DISTFILES_armv7=	compiler-rt-${COMPILER_RT_VERSION}.src.tar.xz:compiler_rt
DIST_SUBDIR?=	rust
EXTRACT_ONLY?=	${DISTFILES:N*\:*bootstrap:C/:.*//}

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Language with a focus on memory safety and concurrency

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

IGNORE_FreeBSD_11_powerpc64=	is missing a bootstrap for FreeBSD 11.x powerpc64
ONLY_FOR_ARCHS?=	aarch64 amd64 armv6 armv7 i386 powerpc64
ONLY_FOR_ARCHS_REASON=	requires prebuilt bootstrap compiler

BUILD_DEPENDS=	cmake:devel/cmake \
		gmake:devel/gmake
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		pkgconfig python:build ssl tar:xz

CONFLICTS_INSTALL?=	rust-nightly

PLIST_FILES=	lib/rustlib/components \
		lib/rustlib/rust-installer-version

OPTIONS_DEFINE=	DOCS GDB SOURCES
GDB_DESC=	Install ports gdb (necessary for debugging rust programs)
SOURCES_DESC=	Install source files

DOCS_VARS_OFF=		_RUST_BUILD_DOCS=false
DOCS_VARS=		_RUST_BUILD_DOCS=true
GDB_RUN_DEPENDS=	${LOCALBASE}/bin/gdb:devel/gdb

# See WRKSRC/src/stage0.txt for the date and version values.
BOOTSTRAPS_DATE?=		2019-09-26
RUST_BOOTSTRAP_VERSION?=	1.38.0
CARGO_BOOTSTRAP_VERSION?=	0.39.0
COMPILER_RT_VERSION?=		9.0.0

BOOTSTRAPS_SUFFIX?=		${BOOTSTRAPS_SUFFIX_${ARCH}}
BOOTSTRAPS_SUFFIX_powerpc64?=	-elfv1

CARGO_VENDOR_DIR?=		${WRKSRC}/vendor

# Rust's target arch string might be different from *BSD arch strings
_RUST_ARCH_amd64=	x86_64
_RUST_ARCH_i386=	i686
_RUST_TARGET=		${_RUST_ARCH_${ARCH}:U${ARCH}}-unknown-${OPSYS:tl}
_LLVM_TARGET=		${ARCH:C/armv.*/ARM/:S/aarch64/AArch64/:S/powerpc64/PowerPC/}

_RUSTC_BOOTSTRAP=	${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/rustc-${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}}-${_RUST_TARGET}
_RUST_STD_BOOTSTRAP=	${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/rust-std-${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}}-${_RUST_TARGET}
_CARGO_BOOTSTRAP=	${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/cargo-${CARGO_BOOTSTRAP_VERSION_${ARCH}:U${CARGO_BOOTSTRAP_VERSION}}-${_RUST_TARGET}

.include <bsd.port.pre.mk>

.if exists(${PATCHDIR}/${ARCH}${BOOTSTRAPS_SUFFIX})
EXTRA_PATCHES+=	${PATCHDIR}/${ARCH}${BOOTSTRAPS_SUFFIX}
.endif

.if ${ARCH} == powerpc64
# The bootstrap is hardcoded to use gcc9
# but we can build with a newer or older compiler as provided by USE_GCC=yes
BUILD_DEPENDS+=	gcc9:lang/gcc9
USE_GCC=	yes
.endif

.if ${ARCH} == aarch64 && ${OSVERSION} < 1200502
IGNORE=	fails to run due to a bug in rtld, update to 12-STABLE r342847 or 13-CURRENT r342113
.endif

.ifdef QEMU_EMULATING
IGNORE=	fails to build with qemu-user-static
.endif

X_PY_ENV=	HOME="${WRKDIR}" \
		LIBGIT2_SYS_USE_PKG_CONFIG=1 \
		LIBSSH2_SYS_USE_PKG_CONFIG=1 \
		OPENSSL_DIR="${OPENSSLBASE}"
X_PY_CMD=	${PYTHON_CMD} ${WRKSRC}/x.py

post-extract:
	@${MKDIR} ${WRKSRC}/build/cache/${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${_RUSTC_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}.tar.gz \
		${WRKSRC}/build/cache/${_RUSTC_BOOTSTRAP}.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${_RUST_STD_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}.tar.gz \
		${WRKSRC}/build/cache/${_RUST_STD_BOOTSTRAP}.tar.gz
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${_CARGO_BOOTSTRAP}${BOOTSTRAPS_SUFFIX}.tar.gz \
		${WRKSRC}/build/cache/${_CARGO_BOOTSTRAP}.tar.gz
.if ${ARCH} == armv6 || ${ARCH} == armv7
	${LN} -sf ${WRKDIR}/compiler-rt-${COMPILER_RT_VERSION}.src ${WRKSRC}/src/llvm-project/compiler-rt
.endif

post-patch:
	@${REINPLACE_CMD} 's,gdb,${LOCALBASE}/bin/gdb,' ${WRKSRC}/src/etc/rust-gdb
	@${ECHO_MSG} "Canonical bootstrap date and version before patching:"
	@${GREP} -E '^(date|rustc|cargo)' ${WRKSRC}/src/stage0.txt
# If we override the versions and date of the bootstraps (for instance
# on aarch64 where we provide our own bootstraps), we need to update
# places where they are recorded.
	@${REINPLACE_CMD} -e 's,^date:.*,date: ${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}},' \
		-e 's,^rustc:.*,rustc: ${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}},' \
		-e 's,^cargo:.*,cargo: ${CARGO_BOOTSTRAP_VERSION_${ARCH}:U${CARGO_BOOTSTRAP_VERSION}},' \
		${WRKSRC}/src/stage0.txt
	@${ECHO_MSG} "Bootstrap date and version after patching:"
	@${GREP} -E '^(date|rustc|cargo)' ${WRKSRC}/src/stage0.txt
.if ${ARCH} == powerpc64
	@${REINPLACE_CMD} -e 's,powerpc64-unknown-freebsd,powerpc64-unknown-freebsd${OSREL},' \
		${WRKSRC}/src/librustc_target/spec/powerpc64_unknown_freebsd.rs
.endif
# Disable vendor checksums
	@${REINPLACE_CMD} 's,"files":{[^}]*},"files":{},' \
		${CARGO_VENDOR_DIR}/*/.cargo-checksum.json

post-patch-SOURCES-off:
# Mimic tools in config.toml with just src excluded
	@${REINPLACE_CMD} -e 's/config.tools.*"src".*/false;/' \
		${WRKSRC}/src/bootstrap/install.rs

.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
CCACHE_VALUE=	"${CCACHE_BIN}"
.else
CCACHE_VALUE=	false
.endif

do-configure:
	${SED} -E \
		-e 's,%PREFIX%,${PREFIX},' \
		-e 's,%SYSCONFDIR%,${PREFIX}/etc,' \
		-e 's,%MANDIR%,${MANPREFIX}/man,' \
		-e 's,%PYTHON_CMD%,${PYTHON_CMD},' \
		-e 's,%CHANNEL%,${PKGNAMESUFFIX:Ustable:S/^-//},' \
		-e 's,%TARGET%,${_RUST_TARGET},' \
		-e 's,%CCACHE%,${CCACHE_VALUE},' \
		-e 's,%CC%,${CC},' \
		-e 's,%CXX%,${CXX},' \
		-e 's,%DOCS%,${_RUST_BUILD_DOCS},' \
		< ${FILESDIR}/config.toml \
		> ${WRKSRC}/config.toml
# no need to build a crosscompiler for these targets
.if ${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == powerpc64
	@${REINPLACE_CMD} -e 's,^#targets =.*,targets = "${_LLVM_TARGET}",' \
		-e 's,^#experimental-targets =.*,experimental-targets = "",' \
		${WRKSRC}/config.toml
.endif
	@${REINPLACE_CMD} -e 's,%CC%,${CC},g' \
		${WRKSRC}/src/librustc_llvm/build.rs \
		${WRKSRC}/src/bootstrap/native.rs

do-build:
	cd ${WRKSRC} && \
	${SETENV} ${X_PY_ENV} \
	${X_PY_CMD} build \
		--verbose \
		--config ./config.toml \
		--jobs ${MAKE_JOBS_NUMBER}

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${X_PY_ENV} \
		DESTDIR=${STAGEDIR} \
	${X_PY_CMD} 'install' \
		--verbose \
		--config ./config.toml \
		--jobs ${MAKE_JOBS_NUMBER}

# In post-install, we use the manifests generated during Rust install
# to in turn generate the PLIST. We do that, instead of the regular
# `pkg-plist`, because several libraries have a computed filename based
# on the absolute path of the source files. As it is user-specific, we
# can't know their filename in advance.
#
# Both rustc and Cargo components install the same README.md and LICENSE
# files. The install process backs up the first copy to install the
# second. Thus here, we need to remove those backups. We also need to
# dedup the entries in the generated PLIST, because both components'
# manifests list them.
#
# We fix manpage entries in the generated manifests because Rust
# installs them uncompressed but the Ports framework compresses them.
post-install:
	for f in ${STAGEDIR}${PREFIX}/lib/rustlib/manifest-*; do \
	    ${REINPLACE_CMD} -i '' -E \
	        -e 's|:${STAGEDIR}|:|' \
	        -e 's|(man/man[1-9]/.*\.[0-9])|\1.gz|' \
	        "$$f"; \
	    ${ECHO_CMD} "$${f#${STAGEDIR}}" >> ${TMPPLIST}; \
	    ${AWK} '\
	        /^file:/ { \
	            file=$$0; \
	            sub(/^file:/, "", file); \
	            print file; \
	        } \
	        /^dir:/ { \
	            dir=$$0; \
	            sub(/^dir:/, "", dir); \
	            system("find ${STAGEDIR}" dir " -type f | ${SED} -E -e \"s|${STAGEDIR}||\""); \
	        }' \
	        "$$f" >> ${TMPPLIST}; \
	done
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/rust/*.old
	${SORT} -u < ${TMPPLIST} > ${TMPPLIST}.uniq
	${MV} ${TMPPLIST}.uniq ${TMPPLIST}
	@${RM} \
	    ${STAGEDIR}${PREFIX}/lib/rustlib/install.log \
	    ${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh
# FIXME: Static libraries in lib/rustlib/*/lib/*.rlib are not stripped,
# but they contain non-object files which make strip(1) unhappy.
	@${FIND} ${STAGEDIR}${PREFIX}/bin -exec ${FILE} -i {} + | ${AWK} -F: \
		'/executable|sharedlib/ { print $$1 }' | ${XARGS} ${STRIP_CMD}

# Note that make test does not work when rust is already installed.
do-test:
	cd ${WRKSRC} && \
	${SETENV} ${X_PY_ENV} \
		ALLOW_NONZERO_RLIMIT_CORE=1 \
	${X_PY_CMD} test \
		--verbose \
		--config ./config.toml \
		--jobs ${MAKE_JOBS_NUMBER}

.if !defined(_RUST_MAKESUM_GUARD)
makesum:
	${MAKE} -D_RUST_MAKESUM_GUARD makesum ARCH=${ONLY_FOR_ARCHS:O:[1]} DISTINFO_FILE=${DISTINFO_FILE}.tmp
.for arch in ${ONLY_FOR_ARCHS:O:[2..-1]}
	${MAKE} -D_RUST_MAKESUM_GUARD makesum ARCH=${arch} DISTINFO_FILE=${DISTINFO_FILE}.${arch}
	${GREP} ${_RUST_ARCH_${arch}:U${arch}} ${DISTINFO_FILE}.${arch} >> ${DISTINFO_FILE}.tmp
.for file in ${DISTFILES_${arch}}
	${GREP} ${file:S,:, ,:[1]} ${DISTINFO_FILE}.${arch} >> ${DISTINFO_FILE}.tmp
.endfor
	${RM} ${DISTINFO_FILE}.${arch}
.endfor
	${MAKE} -D_RUST_MAKESUM_GUARD makesum ARCH=powerpc64 BOOTSTRAPS_SUFFIX="-elfv2" DISTINFO_FILE=${DISTINFO_FILE}.powerpc64-elfv2
	${GREP} ${_RUST_ARCH_powerpc64:Upowerpc64} ${DISTINFO_FILE}.powerpc64-elfv2 >> ${DISTINFO_FILE}.tmp
	${RM} ${DISTINFO_FILE}.powerpc64-elfv2
	${AWK} '!seen[$$0]++' ${DISTINFO_FILE}.tmp > ${DISTINFO_FILE}
	${RM} ${DISTINFO_FILE}.tmp
.endif

.include <bsd.port.post.mk>
