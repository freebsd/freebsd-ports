PORTNAME=	rust-nightly-bun
PORTVERSION=	1.100.0.20260920
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/2026-09-20/:rust
DISTFILES=	rustc-nightly-${RUST_TARGET}.tar.xz:rust \
		cargo-nightly-${RUST_TARGET}.tar.xz:rust \
		rust-std-nightly-${RUST_TARGET}.tar.xz:rust \
		rust-src-nightly.tar.xz:rust
# Keep checksums for both supported architectures in distinfo.  A normal
# fetch only needs the current architecture, but `make makesum` must know
# about both so it does not drop the other one.
.if make(makesum)
DISTFILES=	rustc-nightly-x86_64-unknown-freebsd.tar.xz:rust \
		cargo-nightly-x86_64-unknown-freebsd.tar.xz:rust \
		rust-std-nightly-x86_64-unknown-freebsd.tar.xz:rust \
		rustc-nightly-aarch64-unknown-freebsd.tar.xz:rust \
		cargo-nightly-aarch64-unknown-freebsd.tar.xz:rust \
		rust-std-nightly-aarch64-unknown-freebsd.tar.xz:rust \
		rust-src-nightly.tar.xz:rust
.endif
DIST_SUBDIR=	rust-nightly-bun

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Rust nightly toolchain pinned for lang/bun
WWW=		https://www.rust-lang.org/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/rustc-nightly-${RUST_TARGET}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/rustc-nightly-${RUST_TARGET}/LICENSE-MIT

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	upstream publishes FreeBSD nightly binaries only for these architectures

USES=		tar:xz
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

RUST_TARGET_amd64=	x86_64-unknown-freebsd
RUST_TARGET_aarch64=	aarch64-unknown-freebsd
RUST_TARGET=		${RUST_TARGET_${ARCH}}

RUST_PREFIX=	${PREFIX}/rust-nightly-bun

do-install:
	@${MKDIR} ${STAGEDIR}${RUST_PREFIX}
	cd ${WRKSRC}/rustc-nightly-${RUST_TARGET} && \
		${SH} install.sh --prefix=${STAGEDIR}${RUST_PREFIX} --disable-ldconfig
	cd ${WRKSRC}/cargo-nightly-${RUST_TARGET} && \
		${SH} install.sh --prefix=${STAGEDIR}${RUST_PREFIX} --disable-ldconfig
	cd ${WRKSRC}/rust-std-nightly-${RUST_TARGET} && \
		${SH} install.sh --prefix=${STAGEDIR}${RUST_PREFIX} --disable-ldconfig
	cd ${WRKSRC}/rust-src-nightly && \
		${SH} install.sh --prefix=${STAGEDIR}${RUST_PREFIX} --disable-ldconfig

post-install:
	@${RM} ${STAGEDIR}${RUST_PREFIX}/lib/rustlib/components \
		${STAGEDIR}${RUST_PREFIX}/lib/rustlib/install.log \
		${STAGEDIR}${RUST_PREFIX}/lib/rustlib/manifest-* \
		${STAGEDIR}${RUST_PREFIX}/lib/rustlib/rust-installer-version \
		${STAGEDIR}${RUST_PREFIX}/lib/rustlib/uninstall.sh
	@${FIND} ${STAGEDIR}${RUST_PREFIX}/lib/rustlib/src -type f -exec ${CHMOD} \
		${SHAREMODE} {} +
	@${FIND} ${STAGEDIR}${RUST_PREFIX}/bin ${STAGEDIR}${RUST_PREFIX}/lib \
		${STAGEDIR}${RUST_PREFIX}/libexec -exec ${FILE} -i {} + | \
		${GREP} -E 'executable|sharedlib' | ${CUT} -d: -f1 | ${XARGS} ${STRIP_CMD}
	@${FIND} ${STAGEDIR}${RUST_PREFIX} -not -type d | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${RUST_PREFIX} -type d -empty | \
		${SED} -e 's,^${STAGEDIR}${PREFIX},@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
