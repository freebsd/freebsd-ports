# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cargo
PORTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Rust's Package Manager
# ' <-- Help Vim syntax hilighting...

LICENSE=	APACHE20 \
		MIT
LICENSE_COMB=	dual
# APACHE20 license is standard, see Templates/Licenses/APACHE20
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

# The following files are required:
#
# Main source archive from GitHub
#   This is the source of Cargo, taken from GitHub.
#
# :bootstrap
#   Like Rust, this is a prebuilt "cargo" used to bootstrap it, because
#   Cargo is a standard Rust package itself.
#
# :registry
#   Cargo clones several Git repositories for its dependencies and
#   caches them in its "registry". This is an archive of this registry
#   so nothing is downloaded during the build.
#
# :rust_installer
#   This is a collection of mainly shell scripts which are used to
#   install Cargo.

MASTER_SITES=	https://static.rust-lang.org/cargo-dist/2016-04-10/:bootstrap \
		LOCAL/jbeich:registry
.if !defined(SKIP_CARGO_REGISTRY)
DISTFILES+=	${CARGO_REGISTRY}:registry
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang
GH_PROJECT=	rust-installer:rust_installer
GH_TAGNAME=	4915c75:rust_installer

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	requires prebuilt bootstrap cargo

CARGO_BOOT_SIG=	${ARCH:S/amd64/x86_64/}-unknown-${OPSYS:tl}
CARGO_BOOT=	${PORTNAME}-nightly-${CARGO_BOOT_SIG}${EXTRACT_SUFX}
CARGO_REGISTRY=	${PORTNAME}-registry-${DISTVERSIONFULL}.tar.xz

# We don't USES=cmake here, because cmake is not Cargo's build system.
# It's used by a bundled dependency (libgit2).
BUILD_DEPENDS=	cmake:devel/cmake \
		${RUST_PORT:T}>=1.5.0:${RUST_PORT}
LIB_DEPENDS=	libssh2.so:security/libssh2 \
		libcurl.so:ftp/curl
RUN_DEPENDS=	rustc:${RUST_PORT}
RUST_PORT?=	lang/rust

USES=		gmake python:-2.7,build pkgconfig
USE_OPENSSL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --mandir="${MANPREFIX}/man"
MAKE_ENV=	ARGS="${CARGO_ARGS}"
CARGO_ARGS=	--jobs ${MAKE_JOBS_NUMBER}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
MAKE_ARGS+=	VERBOSE=1
.endif

OPTIONS_DEFINE=	BOOTSTRAP
OPTIONS_DEFAULT=BOOTSTRAP

BOOTSTRAP_DESC=		Bootstrap using pre-built vendor snapshot
BOOTSTRAP_CONFIGURE_OFF=--local-cargo="$$(command -v cargo)" # respect PATH
BOOTSTRAP_DISTFILES=	${CARGO_BOOT}:bootstrap
BOOTSTRAP_EXTRACT_ONLY=	${DISTFILES:N*\:bootstrap:C/:.*//}
BOOTSTRAP_MAKE_ENV=	LD_LIBRARY_PATH="${WRKSRC}/target/snapshot/cargo/lib"
.if !exists(/usr/lib/libssl.so.8) # OPENSSL_SHLIBVER
BOOTSTRAP_VARS+=	WITH_OPENSSL_PORT=yes
.endif

post-extract:
	@${RMDIR} ${WRKSRC}/src/rust-installer
	@${MV} ${WRKSRC_rust_installer} ${WRKSRC}/src/rust-installer

post-extract-BOOTSTRAP-on:
	@${MKDIR} ${WRKSRC}/target/dl
	${LN} -sf ${DISTDIR}/${CARGO_BOOT} ${WRKSRC}/target/dl/

post-patch:
# Fix mandir and don't install licenses outside of ${_LICENSE_DIR}
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		-e 's, LICENSE-[^[:space:]]*,,g' \
		${WRKSRC}/Makefile.in

# In case the previous "make stage" failed, this ensures rust's
# install.sh won't backup previously staged files before reinstalling
# new ones. Otheriwe, the staging directory is polluted with unneeded
# files.
pre-install:
	@if test -f ${STAGEDIR}${PREFIX}/lib/rustlib/manifest-cargo; then \
		${SED} -E -e 's,^(dir|file:),${STAGEDIR},' \
		< ${STAGEDIR}${PREFIX}/lib/rustlib/manifest-cargo \
		| ${XARGS} ${RM}; \
	fi
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/rustlib/components \
		${STAGEDIR}${PREFIX}/lib/rustlib/manifest-cargo \
		${STAGEDIR}${PREFIX}/lib/rustlib/rust-installer-version \
		${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/install.log
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/lib/rustlib/manifest-cargo
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cargo
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/rustlib/components \
		${STAGEDIR}${PREFIX}/lib/rustlib/rust-installer-version \
		${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh

# "make gen-registry" is a special target to ease this port update.
#
# After changing the version number and the Git revision, you can run
# "make gen-registry" to update the distinfo and create a new snapshot of
# the registry. The new registry is written to ${DISTDIR} and can be
# uploaded.

gen-registry:
	${MAKE} -C${.CURDIR} -DSKIP_CARGO_REGISTRY makesum
	${MAKE} -C${.CURDIR} -DSKIP_CARGO_REGISTRY
	${TAR} cJvf ${_DISTDIR}/${CARGO_REGISTRY} -C${WRKDIR} \
		--uid 0 --gid 0 \
		--exclude libgit2/tests/ \
		--exclude curl/tests/ \
		--exclude 'index/github.com-*/.git/' \
		.cargo
	${MAKE} -C${.CURDIR} makesum

.include <bsd.port.mk>
