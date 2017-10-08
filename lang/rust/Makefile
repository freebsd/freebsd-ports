# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION?=	1.20.0
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/:src \
		https://static.rust-lang.org/dist/:rust_bootstrap \
		LOCAL/dumbbell/rust:rust_bootstrap \
		https://static.rust-lang.org/dist/:cargo_bootstrap \
		https://s3.amazonaws.com/rust-lang-ci/cargo-builds/:cargo_bootstrap \
		LOCAL/dumbbell/rust:cargo_bootstrap \
		LOCAL/marino:bootstrap
DISTNAME?=	${PORTNAME}c-${PORTVERSION}-src
DISTFILES?=	${DISTNAME}${EXTRACT_SUFX}:src \
		${RUSTC_BOOTSTRAP}:rust_bootstrap \
		${RUST_STD_BOOTSTRAP}:rust_bootstrap \
		${CARGO_BOOTSTRAP}:cargo_bootstrap
DIST_SUBDIR?=	rust
EXTRACT_ONLY?=	${DISTFILES:N*\:*bootstrap:C/:.*//}

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Language with a focus on memory safety and concurrency

LICENSE=	APACHE20 \
		MIT
LICENSE_COMB=	dual
# APACHE20 license is standard, see Templates/Licenses/APACHE20
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=		cmake:devel/cmake
LIB_DEPENDS=		libcurl.so:ftp/curl \
			libssh2.so:security/libssh2

ONLY_FOR_ARCHS?=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	requires prebuilt bootstrap compiler

# FIXME: The bootstrapped rustc adds -L/usr/local/lib in front of
# the LDFLAGS. When stage0's rustc is linked, it picks the installed
# librust*so and fails.
#CONFLICTS_BUILD?=	rust-nightly
#CONFLICTS_BUILD+=	${PKGBASE}
CONFLICTS_INSTALL?=	rust-nightly

BOOTSTRAPS_DATE?=		2017-07-20
BOOTSTRAPS_DATE_aarch64?=	2017-07-20

RUST_BOOTSTRAP_VERSION?=	1.19.0
RUST_BOOTSTRAP_VERSION_aarch64?=1.19.0
RUSTC_BOOTSTRAP=		${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/rustc-${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}}-${RUST_TARGET}.tar.gz
RUST_STD_BOOTSTRAP=		${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/rust-std-${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}}-${RUST_TARGET}.tar.gz

CARGO_BOOTSTRAP_VERSION?=	0.20.0
CARGO_BOOTSTRAP_VERSION_aarch64?=0.20.0
CARGO_BOOTSTRAP=		${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}/cargo-${CARGO_BOOTSTRAP_VERSION_${ARCH}:U${CARGO_BOOTSTRAP_VERSION}}-${RUST_TARGET}${EXTRACT_SUFX}

RUST_CHANNEL=	${PKGNAMESUFFIX:Ustable:S/^-//}

# Rust's target arch string is different from *BSD arch strings
RUST_ARCH_aarch64=	aarch64
RUST_ARCH_amd64=	x86_64
RUST_ARCH_i386=		i686
RUST_ARCH_x86_64=	x86_64 # dragonfly
RUST_TARGET=		${RUST_ARCH_${ARCH}}-unknown-${OPSYS:tl}
PLIST_SUB+=		RUST_TARGET=${RUST_TARGET}

USES=		compiler gmake libedit pkgconfig python:2.7,build ssl

OPTIONS_DEFINE=		DOCS GDB LLNEXTGEN PORT_LLVM SOURCES
GDB_DESC=		Install ports gdb (necessary for debugging rust programs)
LLNEXTGEN_DESC=		Build with grammar verification
SOURCES_DESC=		Install source files

GDB_RUN_DEPENDS=		${LOCALBASE}/bin/gdb:devel/gdb
LLNEXTGEN_BUILD_DEPENDS=	LLnextgen:devel/llnextgen

# Rust may pass more regression tests with bundled LLVM
PORT_LLVM_DESC=	Build against devel/llvm${LLVM_VER} instead of bundled version
PORT_LLVM_BUILD_DEPENDS=	${LOCALBASE}/bin/FileCheck${LLVM_VER}:devel/llvm${LLVM_VER}
LLVM_VER?=			40
LLVM_CONFIG=			${LOCALBASE}/bin/llvm-config${LLVM_VER}

# Rust manifests list all files and directories installed by rust-installer.
# We use them in:
#     - pre-install to cleanup the ${STAGEDIR}
#     - post-install to populate the ${TMPPLIST}
RUST_MANIFESTS=		lib/rustlib/manifest-cargo \
			lib/rustlib/manifest-rustc \
			lib/rustlib/manifest-rust-analysis-${RUST_TARGET} \
			lib/rustlib/manifest-rust-std-${RUST_TARGET}
RUST_DOCS_MANIFEST=	lib/rustlib/manifest-rust-docs
RUST_SRC_MANIFEST=	lib/rustlib/manifest-rust-src
DOCS_VARS=		rust_manifests+=${RUST_DOCS_MANIFEST}
SOURCES_VARS=		rust_manifests+=${RUST_SRC_MANIFEST}

PLIST_FILES=		lib/rustlib/components \
			lib/rustlib/rust-installer-version

.include <bsd.port.pre.mk>
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200031
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-ino64
.endif

X_PY_ENV=	HOME="${WRKDIR}" \
		OPENSSL_DIR="${OPENSSLBASE}"
X_PY_CMD=	${PYTHON_CMD} ${WRKSRC}/x.py

CRATES_PATCHED_BY_FBSD10_FIX=	src/vendor/libssh2-sys \
				src/vendor/lzma-sys

pre-fetch:
	# FIXME: This is the same check for CONFLICTS as the standard
	# one, except port origins are not compared. This allows
	# the port to conflict with itself, because Rust would pick
	# installed Rust libraries instead of freshly built ones.
	@conflicts_with=$$( \
	{ ${PKG_QUERY} -g "%n-%v %p %o" ${CONFLICTS:C/.+/'&'/} ${CONFLICTS_BUILD:C/.+/'&'/} 2>/dev/null || : ; } \
		| while read pkgname prfx orgn; do \
		if [ "/${PREFIX}" = "/$${prfx}" ]; then \
			${ECHO_CMD} -n " $${pkgname}"; \
		fi; \
	done); \
	if [ -n "$${conflicts_with}" ]; then \
		${ECHO_MSG}; \
		${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package(s): "; \
		for entry in $${conflicts_with}; do \
			${ECHO_MSG} "      $${entry}"; \
		done; \
		${ECHO_MSG}; \
		${ECHO_MSG} "      They will not build together."; \
		${ECHO_MSG} "      Please remove them first with pkg delete."; \
		exit 1;\
	fi

RUST_STD_DIR=		${RUST_STD_BOOTSTRAP:T:R:R}
LIBSTD_SUFFIX=		35ad9950c7e5074b
LIBSTD_SUFFIX_aarch64=	ab4dd4f618cec2e9
LIBSTD=			${RUST_STD_DIR}/rust-std-${RUST_TARGET}/lib/rustlib/${RUST_TARGET}/lib/libstd-${LIBSTD_SUFFIX_${ARCH}:U${LIBSTD_SUFFIX}}.rlib
STDF=			${LIBSTD:T:R:S/lib//}.0.o

post-extract:
	@${MKDIR} \
		${WRKSRC}/build/cache/${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}} \
		${WRKSRC}/build/cache/${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${RUSTC_BOOTSTRAP} \
		${WRKSRC}/build/cache/${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}
.if ${OPSYS} != FreeBSD || ${OSVERSION} < 1200031
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${RUST_STD_BOOTSTRAP} \
		${WRKSRC}/build/cache/${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}
.endif
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${CARGO_BOOTSTRAP} \
		${WRKSRC}/build/cache/${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200031
	${TAR} -x -C ${WRKSRC} -f ${DISTDIR}/${DIST_SUBDIR}/${RUST_STD_BOOTSTRAP}
	${CC} ${CFLAGS} -fPIC -c -o ${WRKSRC}/old_fstat.o ${FILESDIR}/old_fstat.c
	(cd ${WRKSRC} && ${AR} x ${WRKSRC}/${LIBSTD} ${STDF})
	${LD} -r -o ${WRKSRC}/std.xx.o ${WRKSRC}/${STDF} ${WRKSRC}/old_fstat.o
	${MV} ${WRKSRC}/std.xx.o ${WRKSRC}/${STDF}
	(cd ${WRKSRC} && ${AR} r ${WRKSRC}/${LIBSTD} ${STDF})
	${TAR} -cy --format=ustar -C ${WRKSRC} -f ${WRKSRC}/rustc.tbz ${RUST_STD_DIR}
	${MV} ${WRKSRC}/rustc.tbz ${WRKSRC}/build/cache/${RUST_STD_BOOTSTRAP}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gdb|${LOCALBASE}/bin/gdb|' \
		${WRKSRC}/src/etc/rust-gdb
# If we override the versions and date of the bootstraps (for instance
# on aarch64 where we provide our own bootstraps), we need to update
# places where they are recorded.
	@if test "${BOOTSTRAPS_DATE_${ARCH}}"; then \
		${REINPLACE_CMD} -e \
		's|^date:.*|date: ${BOOTSTRAPS_DATE_${ARCH}:U${BOOTSTRAPS_DATE}}|' \
		${WRKSRC}/src/stage0.txt; \
	fi
	@if test "${RUST_BOOTSTRAP_VERSION_${ARCH}}"; then \
		${REINPLACE_CMD} -e \
		's|^rustc:.*|rustc: ${RUST_BOOTSTRAP_VERSION_${ARCH}:U${RUST_BOOTSTRAP_VERSION}}|' \
		${WRKSRC}/src/stage0.txt; \
	fi
	@if test "${CARGO_BOOTSTRAP_VERSION_${ARCH}}"; then \
		${REINPLACE_CMD} -e \
		's|^cargo:.*|cargo: ${CARGO_BOOTSTRAP_VERSION_${ARCH}:U${CARGO_BOOTSTRAP_VERSION}}|' \
		${WRKSRC}/src/stage0.txt; \
		${REINPLACE_CMD} -e \
		's|cargo-nightly-|cargo-${CARGO_BOOTSTRAP_VERSION_${ARCH}:U${CARGO_BOOTSTRAP_VERSION}}-|' \
		${WRKSRC}/src/bootstrap/bootstrap.py; \
	fi
# `extra-patch-ino64` may be applied. If that's the case, we need to
# update `.cargo-checksum.json` to reflect the new checksums verified by
# Cargo.
	@cd "${WRKSRC}/src/vendor/libc"; \
	for file in $$(${FIND} * -name "*.orig"); do \
		old_checksum=$$(${SHA256} -q "$$file"); \
		new_checksum=$$(${SHA256} -q "$${file%%.orig}"); \
		regex="$$regex -e s|\"$${file%%.orig}\":\"$$old_checksum\"|\"$${file%%.orig}\":\"$$new_checksum\"|"; \
	done; \
	if test "$$regex"; then \
		${REINPLACE_CMD} -E $$regex .cargo-checksum.json; \
	fi
# We make a backup of a few files before the FreeBSD 10 autotools
# fix is applied. We'll need them in `do-configure` to update the
# `.cargo-checksum.json` files.
	@for crate in ${CRATES_PATCHED_BY_FBSD10_FIX}; do \
		for file in $$(${FIND} "${WRKSRC}/$$crate" -name "config.rpath"); do \
			${CP} "$$file" "$$file.orig"; \
		done; \
	done

do-configure:
	${SED} -E \
		-e 's,%PREFIX%,${PREFIX},' \
		-e 's,%SYSCONFDIR%,${PREFIX}/etc,' \
		-e 's,%MANDIR%,${MANPREFIX}/man,' \
		-e 's,%PYTHON_CMD%,${PYTHON_CMD},' \
		-e 's,%CHANNEL%,${RUST_CHANNEL},' \
		-e 's,%TARGET%,${RUST_TARGET},' \
		< ${FILESDIR}/config.toml \
		> ${WRKSRC}/config.toml
# The FreeBSD 10 autotools fix may modify some files just before
# `do-configure`. Like after `extra-path-ino64`, we need to update
# `.cargo-checksum.json`.
	@for crate in ${CRATES_PATCHED_BY_FBSD10_FIX}; do \
		cd "${WRKSRC}/$$crate"; \
		for file in $$(${FIND} * -name "*.orig"); do \
			old_checksum=$$(${SHA256} -q "$$file"); \
			new_checksum=$$(${SHA256} -q "$${file%%.orig}"); \
			regex="$$regex -e s|\"$${file%%.orig}\":\"$$old_checksum\"|\"$${file%%.orig}\":\"$$new_checksum\"|"; \
		done; \
		if test "$$regex"; then \
			${REINPLACE_CMD} -E $$regex .cargo-checksum.json; \
		fi; \
	done

post-configure-DOCS-on:
	${REINPLACE_CMD} -e 's,%DOCS%,true,' ${WRKSRC}/config.toml

post-configure-DOCS-off:
	${REINPLACE_CMD} -e 's,%DOCS%,false,' ${WRKSRC}/config.toml

post-configure-PORT_LLVM-on:
	${REINPLACE_CMD} -e 's,%LLVM_CONFIG%,${LLVM_CONFIG},' ${WRKSRC}/config.toml

post-configure-PORT_LLVM-off:
	${REINPLACE_CMD} -e '/%LLVM_CONFIG%/d' ${WRKSRC}/config.toml

do-build:
	cd ${WRKSRC} && \
	${SETENV} ${X_PY_ENV} \
	${X_PY_CMD} build \
		--verbose \
		--config ./config.toml \
		--jobs ${MAKE_JOBS_NUMBER}

# In case the previous "make stage" failed, this ensures rust's
# install.sh won't backup previously staged files before reinstalling
# new ones. Otherwise, the staging directory is polluted with unneeded
# files.
pre-install:
	@for f in ${RUST_MANIFESTS} ${RUST_DOCS_MANIFEST} ${RUST_SRC_MANIFEST}; do \
	    if test -f "${STAGEDIR}${PREFIX}/$$f"; then \
	        ${SED} -E -e 's,^(file|dir):,${STAGEDIR},' \
	            < "${STAGEDIR}${PREFIX}/$$f" \
	            | ${XARGS} ${RM} -r; \
	        ${RM} "${STAGEDIR}${PREFIX}/$$f"; \
	    fi; \
	done
	@for f in ${PLIST_FILES}; do \
	    ${RM} "${STAGEDIR}${PREFIX}/$$f"; \
	done

do-install:
	cd ${WRKSRC} && \
	${SETENV} ${X_PY_ENV} \
		DESTDIR=${STAGEDIR} \
	${X_PY_CMD} install \
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
	for f in ${RUST_MANIFESTS}; do \
	    ${REINPLACE_CMD} -E \
	        -e 's|:${STAGEDIR}|:|' \
	        -e 's|(man/man[1-9]/.*\.[0-9])|\1.gz|' \
	        ${STAGEDIR}${PREFIX}/$$f; \
	    ${RM} ${STAGEDIR}${PREFIX}/$$f.bak; \
	    ${ECHO} "${PREFIX}/$$f" >> ${TMPPLIST}; \
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
	        ${STAGEDIR}${PREFIX}/$$f >> ${TMPPLIST}; \
	done
	${RM} ${STAGEDIR}${PREFIX}/share/doc/rust/*.old
	${SORT} -u < ${TMPPLIST} > ${TMPPLIST}.uniq
	${MV} ${TMPPLIST}.uniq ${TMPPLIST}
	@${RM} \
	    ${STAGEDIR}${PREFIX}/lib/rustlib/install.log \
	    ${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh
# FIXME: Static libraries in lib/rustlib/*/lib/*.rlib are not stripped,
# but they contain non-object files which make strip(1) unhappy.
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/cargo \
		${STAGEDIR}${PREFIX}/bin/rustc \
		${STAGEDIR}${PREFIX}/bin/rustdoc \
		${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/rustlib/*/lib/*.so

# We set `extended = true` in config.toml because we want to build
# Cargo at the same time. However, this installs the rust-src component
# as well. If the user doesn't want that, I don't know how to prevent
# its install. So for now, use the rust-src manifest to remove it from
# ${STAGEDIR}.
post-install-SOURCES-off:
	if test -f "${STAGEDIR}${PREFIX}/${RUST_SRC_MANIFEST}"; then \
	    ${SED} -E -e 's,^(file|dir):,,' \
	        < "${STAGEDIR}${PREFIX}/${RUST_SRC_MANIFEST}" \
	        | ${XARGS} ${RM} -r; \
	    ${RM} "${STAGEDIR}${PREFIX}/${RUST_SRC_MANIFEST}"; \
	    ${RM} -r "${STAGEDIR}${PREFIX}/lib/rustlib/src"; \
	fi

# Note that make test does not work when rust is already installed.
do-test:
	cd ${WRKSRC} && \
	${SETENV} ${X_PY_ENV} \
		ALLOW_NONZERO_RLIMIT_CORE=1 \
	${X_PY_CMD} test \
		--verbose \
		--config ./config.toml \
		--jobs ${MAKE_JOBS_NUMBER}

.include <bsd.port.post.mk>
