# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTVERSION=	1.43.0.${NIGHTLY_DATE:C,-,,g}
# Always set PORTREVISION explicitly as otherwise it is inherited from lang/rust
PORTREVISION=	0
PKGNAMESUFFIX=	-nightly
DISTNAME=	rustc-nightly-src

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	upstream does not provide bootstraps for other architectures

CONFLICTS_INSTALL=	rust

MASTERDIR=	${.CURDIR}/../rust
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

# Get latest from top level 'date' key in
# https://static.rust-lang.org/dist/channel-rust-nightly.toml
NIGHTLY_DATE=	2020-02-20

# See WRKSRC/src/stage0.txt for this date
BOOTSTRAPS_DATE=		2020-01-30
RUST_BOOTSTRAP_VERSION=		beta
CARGO_BOOTSTRAP_VERSION=	beta

post-configure:
# Don't abort if optional tools fail to build
# https://github.com/rust-lang/rust/commit/53254a888b42
	@${ECHO_CMD} 'missing-tools = true' >>${WRKSRC}/config.toml

.include "${MASTERDIR}/Makefile"
