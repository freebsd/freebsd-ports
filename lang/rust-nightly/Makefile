# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTVERSION=	1.25.0.${NIGHTLY_DATE:C,-,,g}
PKGNAMESUFFIX=	-nightly
DISTNAME=	rustc-nightly-src

MASTERDIR=	${.CURDIR}/../rust
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

CONFLICTS_BUILD=	rust # see FIXME in `pre-fetch` in lang/rust/Makefile
CONFLICTS_INSTALL=	rust

# Which source to pull:
#   https://static.rust-lang.org/dist/${NIGHTLY_DATE}/rustc-nightly-src.tar.gz
NIGHTLY_DATE=			2018-03-21
NIGHTLY_SUBDIR=			${NIGHTLY_DATE}/

# See WRKSRC/src/stage0.txt for this date
BOOTSTRAPS_DATE=		2018-03-18
RUST_BOOTSTRAP_VERSION=		beta
CARGO_BOOTSTRAP_VERSION=	beta

ONLY_FOR_ARCHS=			amd64 i386

.include "${MASTERDIR}/Makefile"
