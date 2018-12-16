# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTVERSION=	1.33.0.${NIGHTLY_DATE:C,-,,g}
PKGNAMESUFFIX=	-nightly
DISTNAME=	rustc-nightly-src

MASTERDIR=	${.CURDIR}/../rust
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

CONFLICTS_INSTALL=	rust

# Which source to pull:
#   https://static.rust-lang.org/dist/${NIGHTLY_DATE}/rustc-nightly-src.tar.gz
#   https://static.rust-lang.org/dist/channel-rust-nightly.toml
NIGHTLY_DATE=			2018-12-16
NIGHTLY_SUBDIR=			${NIGHTLY_DATE}/

# See WRKSRC/src/stage0.txt for this date
BOOTSTRAPS_DATE=		2018-12-09
RUST_BOOTSTRAP_VERSION=		beta
CARGO_BOOTSTRAP_VERSION=	beta

# Other bootstraps aren't provided by upstream yet
ONLY_FOR_ARCHS=			amd64 i386

# Same as lang/rust except for src/vendor/ -> vendor/
CRATES_PATCHED_BY_FBSD10_FIX=	vendor/libssh2-sys \
				vendor/lzma-sys

post-patch:	nightly-post-patch
nightly-post-patch:
# Work around unused_unsafe errors in libcore with stage0
	@${REINPLACE_CMD} '/RUSTC_DENY_WARNINGS/d' ${WRKSRC}/src/bootstrap/builder.rs

# Same as lang/rust except for src/vendor/ -> vendor/
pre-configure:
	@for file in \
		${WRKSRC}/vendor/backtrace-sys/src/libbacktrace/configure \
		${WRKSRC}/vendor/backtrace-sys/src/libbacktrace/config/libtool.m4; do \
		mv "$$file" "$$file.dont-fix"; \
	done

# Same as lang/rust except for src/vendor/ -> vendor/
post-configure:
	@for file in \
		${WRKSRC}/vendor/backtrace-sys/src/libbacktrace/configure \
		${WRKSRC}/vendor/backtrace-sys/src/libbacktrace/config/libtool.m4; do \
		mv "$$file.dont-fix" "$$file"; \
	done

.include "${MASTERDIR}/Makefile"
