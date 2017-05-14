# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION?=	1.17.0
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/:src \
		https://static.rust-lang.org/dist/:rust_bootstrap \
		https://s3.amazonaws.com/rust-lang-ci/cargo-builds/:cargo_bootstrap \
		LOCAL/marino:bootstrap
DISTNAME?=	${PORTNAME}c-${PORTVERSION}-src
BOOTSTRAP_FILES=${RUSTC_BOOTSTRAP}:rust_bootstrap \
		${RUST_STD_BOOTSTRAP}:rust_bootstrap \
		${CARGO_BOOTSTRAP}:cargo_bootstrap
DISTFILES?=	${DISTNAME}${EXTRACT_SUFX}:src \
		${BOOTSTRAP_FILES}
.if !defined(SKIP_CARGO_REGISTRY)
MASTER_SITES+=	LOCAL/riggs/rust:registry \
		LOCAL/dumbbell/rust:registry
DISTFILES+=	${CARGO_REGISTRY}:registry
.endif
DIST_SUBDIR?=	rust
EXTRACT_ONLY?=	${DISTFILES:N*\:*bootstrap:C/:.*//}

MAINTAINER?=	riggs@FreeBSD.org
COMMENT=	Language with a focus on memory safety and concurrency

LICENSE=	APACHE20 \
		MIT
LICENSE_COMB=	dual
# APACHE20 license is standard, see Templates/Licenses/APACHE20
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=		cmake:devel/cmake

ONLY_FOR_ARCHS?=	amd64 i386
ONLY_FOR_ARCHS_REASON=	requires prebuilt bootstrap compiler

# FIXME: The bootstrapped rustc adds -L/usr/local/lib in front of
# the LDFLAGS. When stage0's rustc is linked, it picks the installed
# librust*so and fails.
CONFLICTS_BUILD?=	rust-nightly
CONFLICTS_BUILD+=	${PKGBASE}
CONFLICTS_INSTALL?=	rust-nightly

RUST_BOOTSTRAP_DIR?=		2017-03-11
RUST_BOOTSTRAP_VERSION?=	1.16.0
RUSTC_BOOTSTRAP=		${RUST_BOOTSTRAP_DIR}/rustc-${RUST_BOOTSTRAP_VERSION}-${RUST_TARGET}.tar.gz
RUST_STD_BOOTSTRAP=		${RUST_BOOTSTRAP_DIR}/rust-std-${RUST_BOOTSTRAP_VERSION}-${RUST_TARGET}.tar.gz

CARGO_BOOTSTRAP_DIR?=		6b05583d71f982bcad049b9fa094c637c062e751
CARGO_BOOTSTRAP_VERSION?=	nightly
CARGO_BOOTSTRAP=		${CARGO_BOOTSTRAP_DIR}/cargo-${CARGO_BOOTSTRAP_VERSION}-${RUST_TARGET}.tar.gz
CARGO_REGISTRY=			${PORTNAME}-registry-${DISTVERSIONFULL}.tar.xz

RUST_CHANNEL=	${PKGNAMESUFFIX:Ustable:S/^-//}

# Rust's target arch string is different from *BSD arch strings
RUST_ARCH_x86_64=	x86_64 # dragonfly
RUST_ARCH_amd64=	x86_64
RUST_ARCH_i386=		i686
RUST_TARGET=		${RUST_ARCH_${ARCH}}-unknown-${OPSYS:tl}
PLIST_SUB+=		RUST_TARGET=${RUST_TARGET}

USES=		compiler gmake libedit python:2,build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-valgrind \
		${CHOSEN_COMPILER_TYPE:Mclang:C/.+/--enable-&/} \
		--prefix=${PREFIX}	\
		--musl-root=${PREFIX}	\
		--local-rust-root=${PREFIX} \
		--mandir=${MANPREFIX}/man \
		--release-channel=${RUST_CHANNEL}

MAKE_ARGS+=	VERBOSE=1

OPTIONS_DEFINE=		DOCS GDB LLNEXTGEN PORT_LLVM
GDB_DESC=		Install ports gdb (necessary for debugging rust programs)
LLNEXTGEN_DESC=		Build with grammar verification

DOCS_CONFIGURE_ENABLE=	docs
GDB_RUN_DEPENDS=		${LOCALBASE}/bin/gdb:devel/gdb
LLNEXTGEN_BUILD_DEPENDS=	LLnextgen:devel/llnextgen

# Rust may pass more regression tests with bundled LLVM
PORT_LLVM_DESC=	Build against devel/llvm${LLVM_VER} instead of bundled version
PORT_LLVM_BUILD_DEPENDS=	${LLVM_PREFIX}/bin/FileCheck:devel/llvm${LLVM_VER}
PORT_LLVM_CONFIGURE_ON=		--llvm-root=${LLVM_PREFIX}
LLVM_VER?=			40
LLVM_PREFIX=			${LOCALBASE}/llvm${LLVM_VER}

# Note that make test does not work when rust is already installed
TEST_TARGET=	check
TEST_ENV+=	ALLOW_NONZERO_RLIMIT_CORE=1

# Rust manifests list all files and directories installed by rust-installer.
# We use them in:
#     - pre-install to cleanup the ${STAGEDIR}
#     - post-install to populate the ${TMPPLIST}
RUST_MANIFESTS=		lib/rustlib/manifest-rustc \
			lib/rustlib/manifest-rust-std-${RUST_TARGET}
RUST_DOCS_MANIFESTS=	lib/rustlib/manifest-rust-docs
DOCS_VARS=		rust_manifests+=${RUST_DOCS_MANIFESTS}

PLIST_FILES=		lib/rustlib/components \
			lib/rustlib/rust-installer-version

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

post-extract:
	@${MKDIR} \
		${WRKSRC}/build/cache/${RUST_BOOTSTRAP_DIR} \
		${WRKSRC}/build/cache/${CARGO_BOOTSTRAP_DIR}
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${RUSTC_BOOTSTRAP} \
		${WRKSRC}/build/cache/${RUST_BOOTSTRAP_DIR}
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${RUST_STD_BOOTSTRAP} \
		${WRKSRC}/build/cache/${RUST_BOOTSTRAP_DIR}
	${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${CARGO_BOOTSTRAP} \
		${WRKSRC}/build/cache/${CARGO_BOOTSTRAP_DIR}

post-patch:
	@test ! -f ${WRKSRC}/mk/main.mk || \
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/mk/main.mk
	@${REINPLACE_CMD} -e 's|gdb|${LOCALBASE}/bin/gdb|' \
		${WRKSRC}/src/etc/rust-gdb

# In case the previous "make stage" failed, this ensures rust's
# install.sh won't backup previously staged files before reinstalling
# new ones. Otherwise, the staging directory is polluted with unneeded
# files.
pre-install:
	@for f in ${RUST_MANIFESTS} ${RUST_DOCS_MANIFESTS}; do \
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

# In post-install, we use the manifests generated during Rust install
# to in turn generate the PLIST. We do that, instead of the regular
# `pkg-plist`, because several libraries have a computed filename based
# on the absolute path of the source files. As it is user-specific, we
# can't know their filename in advance.
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
	@${RM} \
	    ${STAGEDIR}${PREFIX}/lib/rustlib/install.log \
	    ${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh
# FIXME: Static libraries in lib/rustlib/*/lib/*.rlib are not stripped,
# but they contain non-object files which make strip(1) unhappy.
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/rustc \
		${STAGEDIR}${PREFIX}/bin/rustdoc \
		${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/rustlib/*/lib/*.so

.include <bsd.port.mk>

# "make gen-registry" is a special target to ease this port update.
#
# After changing the version number and the Git revision, you can run
# "make gen-registry" to update the distinfo and create a new snapshot of
# the registry. The new registry is written to ${DISTDIR} and can be
# uploaded.

gen-registry:
	${MAKE} -C${.CURDIR} -DSKIP_CARGO_REGISTRY makesum
	${MAKE} -C${.CURDIR} -DSKIP_CARGO_REGISTRY
	${TAR} cJvf ${DISTDIR}/${DIST_SUBDIR}/${CARGO_REGISTRY} -C${WRKDIR} \
		--uid 0 --gid 0 \
		--exclude 'src/*/benches/' \
		--exclude 'src/*/ci/' \
		--exclude 'src/*/examples/' \
		--exclude 'src/*/tests/' \
		--exclude 'index/github.com-*/.git/' \
		.cargo
	${MAKE} -C${.CURDIR} makesum
