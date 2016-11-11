# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	rust
PORTVERSION?=	1.13.0
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/:src \
		http://static.rust-lang.org/dist/:bootstrap \
		https://github.com/dhuseby/rust-manual-snapshots/raw/master/:bootstrap \
		LOCAL/marino:bootstrap
DISTNAME?=	${PORTNAME}c-${PORTVERSION}
DISTFILES?=	${DISTNAME}-src${EXTRACT_SUFX}:src
DISTFILES+=	${RUST_BOOT}:bootstrap
EXTRACT_ONLY?=	${DISTFILES:N*\:bootstrap:C/:.*//}

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

BROKEN_FreeBSD_9=	Only compiles on FreeBSD 10 and later

DISTINFO_FILE?=	${MASTERDIR}/distinfo.${ARCH}

# FIXME: The bootstrapped rustc adds -L/usr/local/lib in front of
# the LDFLAGS. When stage0's rustc is linked, it picks the installed
# librust*so and fails.
CONFLICTS_BUILD?=	rust-nightly
CONFLICTS_BUILD+=	${PKGBASE}
CONFLICTS_INSTALL?=	rust-nightly

RUST_BOOT_VERSION?=	1.12.1
RUST_BOOT=		rustc-${RUST_BOOT_VERSION}-${RUST_TARGET}.tar.gz

# Rust's libraries are named librustc_${component}-${RUST_VSN_HASH}.so.
# The hash depends on Rust version and, if the channel is not "stable",
# the channel name. See $(CFG_FILENAME_EXTRA) definition in mk/main.mk.
RUST_VSN=	${PORTVERSION:C/\.[0-9]{8}$//}
.if defined(.PARSEDIR) # fixes |make describe| on 9.x (which is BROKEN)
RUST_CHANNEL=	${PKGNAMESUFFIX:Ustable:S/^-//}
.endif
RUST_VSN_HASH!=	/usr/bin/printf '%s' ${RUST_VSN}${PKGNAMESUFFIX} | /sbin/md5 -q | cut -c 1-8
PLIST_SUB+=	RUST_VSN_HASH=${RUST_VSN_HASH}

# Rust's target arch string is different from *BSD arch strings
RUST_ARCH_x86_64=	x86_64 # dragonfly
RUST_ARCH_amd64=	x86_64
RUST_ARCH_i386=		i686
RUST_TARGET=		${RUST_ARCH_${ARCH}}-unknown-${OPSYS:tl}
PLIST_SUB+=	RUST_TARGET=${RUST_TARGET}

USES=		compiler gmake libedit python:2,build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-valgrind \
		${CHOSEN_COMPILER_TYPE:Mclang:C/.+/--enable-&/} \
		--prefix=${PREFIX}	\
		--musl-root=${PREFIX}	\
		--local-rust-root=${PREFIX} \
		--mandir=${MANPREFIX}/man \
		--release-channel=${RUST_CHANNEL}

PORTDOCS=	*

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
LLVM_VER?=			38
LLVM_PREFIX=			${LOCALBASE}/llvm${LLVM_VER}

# Note that make test does not work when rust is already installed
TEST_TARGET=	check
TEST_ENV+=	ALLOW_NONZERO_RLIMIT_CORE=1

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
	@${MKDIR} ${WRKSRC}/dl
	${LN} -sf ${DISTDIR}/${RUST_BOOT} ${WRKSRC}/dl

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
	@for f in manifest-rustc manifest-rust-std-${RUST_TARGET}; do \
	    if test -f ${STAGEDIR}${PREFIX}/lib/rustlib/$$f; then \
		${SED} -E -e 's,^(dir|file:),${STAGEDIR},' \
		< ${STAGEDIR}${PREFIX}/lib/rustlib/$$f \
		| ${XARGS} ${RM}; \
	    fi; \
	done
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/rustlib/components \
		${STAGEDIR}${PREFIX}/lib/rustlib/manifest-rustc \
		${STAGEDIR}${PREFIX}/lib/rustlib/manifest-rust-std-${RUST_TARGET} \
		${STAGEDIR}${PREFIX}/lib/rustlib/rust-installer-version \
		${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh

pre-install-DOCS-on:
	@for f in manifest-rust-docs; do \
	    if test -f ${STAGEDIR}${PREFIX}/lib/rustlib/$$f; then \
		${SED} -E -e 's,^(dir|file:),${STAGEDIR},' \
		< ${STAGEDIR}${PREFIX}/lib/rustlib/$$f \
		| ${XARGS} ${RM}; \
	    fi; \
	done
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/manifest-rust-docs

post-install:
	@for f in manifest-rustc manifest-rust-std-${RUST_TARGET}; do \
		${REINPLACE_CMD} -e 's|${STAGEDIR}||' \
			${STAGEDIR}${PREFIX}/lib/rustlib/$$f; \
		${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/$$f.bak; \
	done
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/install.log
# FIXME: Static libraries in lib/rustlib/*/lib/*.rlib are not stripped,
# but they contain non-object files which make strip(1) unhappy.
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/rustc \
		${STAGEDIR}${PREFIX}/bin/rustdoc \
		${STAGEDIR}${PREFIX}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/rustlib/*/lib/*.so

post-install-DOCS-on:
	@for f in manifest-rust-docs; do \
		${REINPLACE_CMD} -e 's|${STAGEDIR}||' \
			${STAGEDIR}${PREFIX}/lib/rustlib/$$f; \
		${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/$$f.bak; \
	done
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/doc/rust/html/extra

.include <bsd.port.mk>
