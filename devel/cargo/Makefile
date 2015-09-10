# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cargo
PORTVERSION=	0.4.0.20150720
CATEGORIES=	devel

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Rust's Package Manager
# ' <-- Help Vim syntax hilighting...

LICENSE=	APACHE20 \
		MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE-APACHE \
		${WRKSRC}/LICENSE-MIT

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

MASTER_SITES=	https://static.rust-lang.org/cargo-dist/2015-04-02/:bootstrap \
		LOCAL/dumbbell:registry

DISTFILES=	${CARGO_BOOT}:bootstrap
EXTRACT_ONLY=	${DISTNAME}${_GITHUB_EXTRACT_SUFX} \
		${DISTFILE_rust_installer}

.if (${.TARGET} != gen-registry) && !defined(SKIP_CARGO_REGISTRY)
DISTFILES+=	${CARGO_REGISTRY}:registry
EXTRACT_ONLY+=	${CARGO_REGISTRY}
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang
GH_PROJECT=	${PORTNAME} \
		rust-installer:rust_installer
GH_TAGNAME=	9c5ffcb871 \
		c37d374:rust_installer

CARGO_BOOT_SIG=	x86_64-unknown-freebsd
CARGO_BOOT=	${PORTNAME}-nightly-${CARGO_BOOT_SIG}${EXTRACT_SUFX}
CARGO_REGISTRY=	${DISTNAME:S/${GH_ACCOUNT}-${PORTNAME}/${PORTNAME}-registry/}${EXTRACT_SUFX}

USES=		gmake python:2,build pkgconfig

# The bootstrapped cargo is built with OpenSSL from ports (libssl.so.8).
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=yes

# We don't USES=cmake here, because cmake is not Cargo's build system.
# It's used by a bundled dependency (libgit2).
BUILD_DEPENDS=	${LOCALBASE}/bin/cmake:${PORTSDIR}/devel/cmake \
		rustc:${PORTSDIR}/lang/rust-nightly
LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2 \
		libcurl.so:${PORTSDIR}/ftp/curl

# FIXME: Don't add rust as a runtime dependency. As we need rust-nightly
# to build Cargo, the same version would be pulled by installing Cargo,
# preventing its use with the stable version of Rust.
# RUN_DEPENDS=	rustc:${PORTSDIR}/lang/rust

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
MAKE_ENV+=	LD_LIBRARY_PATH="${WRKSRC}/target/snapshot/cargo/lib"

# git log -1 --date=short --pretty=format:'%cd'
CFG_VER_DATE=	${PORTVERSION:C/.*\.([0-9]{4})([0-9]{2})([0-9]{2})/\1-\2-\3/}
# git rev-parse --short HEAD
CFG_VER_HASH=	${GH_TAGNAME}

.if defined(BATCH) || defined(PACKAGE_BUILDING)
MAKE_ARGS+=	VERBOSE=1
.endif

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

post-extract:
	@(${RMDIR} ${WRKSRC}/src/rust-installer && \
	  ${MV} ${WRKSRC_rust_installer} ${WRKSRC}/src/rust-installer)
	@${MKDIR} ${WRKSRC}/target/dl
	${LN} -sf ${DISTDIR}/${CARGO_BOOT} ${WRKSRC}/target/dl/

post-patch:
	${REINPLACE_CMD} \
		-e 's|^CFG_VER_DATE =.*|CFG_VER_DATE = ${CFG_VER_DATE}|' \
		-e 's|^CFG_VER_HASH =.*|CFG_VER_HASH = ${CFG_VER_HASH}|' \
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
	@${MV} ${STAGEDIR}${PREFIX}/share/man/man1/cargo.1 \
		${STAGEDIR}${PREFIX}/man/man1/cargo.1
	@${RMDIR} ${STAGEDIR}${PREFIX}/share/man/man1 \
		${STAGEDIR}${PREFIX}/share/man
	@${REINPLACE_CMD} -e 's|${STAGEDIR}||' \
		-e 's|share/man/man1/cargo\.1|man/man1/cargo.1.gz|' \
		${STAGEDIR}${PREFIX}/lib/rustlib/manifest-cargo
	@${RM} ${STAGEDIR}${PREFIX}/lib/rustlib/manifest-cargo.bak
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cargo
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/rustlib/components \
		${STAGEDIR}${PREFIX}/lib/rustlib/rust-installer-version \
		${STAGEDIR}${PREFIX}/lib/rustlib/uninstall.sh

# "make gen-registry" is a special target to ease this port update.
#
# After changing the version number and the Git revision, you can run
# "make registry" to update the distinfo and create a new snapshot of
# the registry. The new registry is written to ${DISTDIR} and can be
# uploaded.

gen-registry:
	${MAKE} -DSKIP_CARGO_REGISTRY makesum
	${MAKE} -DSKIP_CARGO_REGISTRY
	cd ${WRKDIR} && \
		${TAR} cvf - \
		--exclude libgit2/tests/ \
		--exclude curl/tests/ \
		--exclude 'index/github.com-*/.git/' \
		.cargo | ${GZIP_CMD} > ${DISTDIR}/${CARGO_REGISTRY}
	${MAKE} makesum

.include <bsd.port.post.mk>
