# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rust-nightly
PORTVERSION=	1.9.0.20160318
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/stage0-snapshots/:bootstrap
DISTFILES=	${RUST_BOOT}:bootstrap
EXTRACT_ONLY=	${DISTNAME}${_GITHUB_EXTRACT_SUFX} \
		${DISTFILE_compiler_rt} \
		${DISTFILE_hoedown} \
		${DISTFILE_jemalloc} \
		${DISTFILE_liblibc} \
		${DISTFILE_rust_installer}

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Language with a focus on memory safety and concurrency

LICENSE=	APACHE20 \
		MIT
LICENSE_COMB=	dual
# APACHE20 license is standard, see Templates/Licenses/APACHE20
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires prebuilt bootstrap compiler

BROKEN_FreeBSD_9=	Only compiles on FreeBSD 10 and 11

USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang
GH_PROJECT=	rust \
		compiler-rt:compiler_rt \
		hoedown:hoedown \
		jemalloc:jemalloc \
		libc:liblibc \
		rust-installer:rust_installer
GH_TAGNAME=	235d77457d \
		57315f7:compiler_rt \
		4638c60:hoedown \
		aab1c0a:jemalloc \
		2278a54:liblibc \
		c37d374:rust_installer

# FIXME: The bootstrapped rustc adds -L/usr/local/lib in front of
# the LDFLAGS. When stage0's rustc is linked, it picks the installed
# librust*so and fails.
CONFLICTS_BUILD=	rust \
			rust-nightly
CONFLICTS_INSTALL=	rust-nightly

RUST_BOOT=	rust-stage0-${RUST_BOOT_SIG_${ARCH}}.tar.bz2

RUST_BOOT_SIG_amd64=	2016-02-17-4d3eebf-freebsd-x86_64-f38991fbb81c1cd8d0bbda396f98f13a55b42804

# Rust's libraries are named librustc_${component}-${RUST_VSN_HASH}.so.
# The hash depends on Rust version and, if the channel is not "stable",
# the channel name. See $(CFG_FILENAME_EXTRA) definition in mk/main.mk.
RUST_VSN=	${PORTVERSION:R}
RUST_CHANNEL=	${PORTNAME:S/^rust-//}
RUST_VSN_HASH!=	/usr/bin/printf '%s' ${RUST_VSN}-${RUST_CHANNEL} | /sbin/md5 -q | cut -c 1-8
PLIST_SUB+=	RUST_VSN_HASH=${RUST_VSN_HASH}

# Rust's target arch string is different from *BSD arch strings
RUST_ARCH_amd64=	x86_64
RUST_ARCH_i386=		i686
RUST_TARGET=		${RUST_ARCH_${ARCH}}-unknown-${OPSYS:tl}
PLIST_SUB+=	RUST_TARGET=${RUST_TARGET}

USES=		gmake libedit python:2,build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-valgrind --disable-docs \
		--enable-clang --mandir=${MANPREFIX}/man \
		--release-channel=${RUST_CHANNEL}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
MAKE_ARGS+=	VERBOSE=1
.endif

OPTIONS_DEFINE=		DOCS GDB LLNEXTGEN PORT_LLVM
GDB_DESC=		Install ports gdb (necessary for debugging rust programs)
LLNEXTGEN_DESC=		Build with grammar verification

GDB_RUN_DEPENDS=		${LOCALBASE}/bin/gdb:devel/gdb
LLNEXTGEN_BUILD_DEPENDS=	LLnextgen:devel/llnextgen

# Rust may pass more regression tests with bundled LLVM
PORT_LLVM_DESC=	Build against devel/llvm${LLVM_VER} instead of bundled version
PORT_LLVM_BUILD_DEPENDS=	${LLVM_PREFIX}/bin/FileCheck:devel/llvm${LLVM_VER}
PORT_LLVM_CONFIGURE_ON=		--llvm-root=${LLVM_PREFIX}
PORT_LLVM_EXTRACT_ONLY_OFF=	${DISTFILE_llvm}
PORT_LLVM_GH_PROJECT_OFF=	llvm:llvm
PORT_LLVM_GH_TAGNAME_OFF=	63f3a1b:llvm
PORT_LLVM_VARS_OFF=		NOPRECIOUSMAKEVARS=1 # ARCH
LLVM_VER?=			36 # XXX Move to DEFAULT_VERSIONS
LLVM_PREFIX=			${LOCALBASE}/llvm${LLVM_VER}

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
	@(${RMDIR} ${WRKSRC}/src/compiler-rt && \
	  ${MV} ${WRKSRC_compiler_rt} ${WRKSRC}/src/compiler-rt)
	@(${RMDIR} ${WRKSRC}/src/rt/hoedown && \
	  ${MV} ${WRKSRC_hoedown} ${WRKSRC}/src/rt/hoedown)
	@(${RMDIR} ${WRKSRC}/src/jemalloc && \
	  ${MV} ${WRKSRC_jemalloc} ${WRKSRC}/src/jemalloc)
	@(${RMDIR} ${WRKSRC}/src/liblibc && \
	  ${MV} ${WRKSRC_liblibc} ${WRKSRC}/src/liblibc)
	@(${RMDIR} ${WRKSRC}/src/rust-installer && \
	  ${MV} ${WRKSRC_rust_installer} ${WRKSRC}/src/rust-installer)
	@${MKDIR} ${WRKSRC}/dl
	${LN} -sf ${DISTDIR}/${RUST_BOOT} ${WRKSRC}/dl
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 {} +

post-extract-PORT_LLVM-off:
	@(${RMDIR} ${WRKSRC}/src/llvm && \
	  ${MV} ${WRKSRC_llvm} ${WRKSRC}/src/llvm)

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/mk/main.mk
	@${REINPLACE_CMD} -e 's|gdb|${LOCALBASE}/bin/gdb|' \
		${WRKSRC}/src/etc/rust-gdb

# In case the previous "make stage" failed, this ensures rust's
# install.sh won't backup previously staged files before reinstalling
# new ones. Otherwise, the staging directory is polluted with unneeded
# files.
pre-install:
.for f in manifest-rustc manifest-rust-std-${RUST_TARGET}
	@if test -f ${STAGEDIR}${PREFIX}/lib/rustlib/${f}; then \
		${SED} -E -e 's,^(dir|file:),${STAGEDIR},' \
		< ${STAGEDIR}${PREFIX}/lib/rustlib/${f} \
		| ${XARGS} ${RM}; \
	fi
.endfor
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/rustlib/components \
		${STAGEDIR}${PREFIX}/lib/rustlib/manifest-rustc \
		${STAGEDIR}${PREFIX}/lib/rustlib/manifest-rust-std-${RUST_TARGET} \
		${STAGEDIR}${PREFIX}/lib/rustlib/rust-installer-version \
		${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh

post-install:
.for f in manifest-rustc manifest-rust-std-${RUST_TARGET}
	@${REINPLACE_CMD} -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/lib/rustlib/${f}
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/${f}.bak
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/install.log
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/rustc \
		${STAGEDIR}${PREFIX}/bin/rustdoc \
		${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/rustlib/*/lib/*.so
# FIXME: Static libraries in lib/rustlib/*/lib/*.rlib are not stripped,
# but they contain non-object files which make strip(1) unhappy.

post-install-DOCS-on:
	${MV} ${STAGEDIR}${PREFIX}/share/doc/rust ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
