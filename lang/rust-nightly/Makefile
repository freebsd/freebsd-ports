# Run update.sh to update to the latest nightly
PORTVERSION=	1.91.0.${NIGHTLY_DATE:C,-,,g}
# Always set PORTREVISION explicitly as otherwise it is inherited from lang/rust
PORTREVISION=	0
PKGNAMESUFFIX=	-nightly
DISTNAME=	rustc-nightly-src

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	upstream does not provide bootstraps for other architectures

CONFLICTS_INSTALL=	rust rust188

MASTERDIR=	${.CURDIR}/../rust
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

NIGHTLY_DATE=		2025-09-07
BOOTSTRAPS_DATE=	2025-08-05
RUST_BOOTSTRAP_VERSION=	beta

.include "${MASTERDIR}/Makefile"
