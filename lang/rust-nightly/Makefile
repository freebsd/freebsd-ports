# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTVERSION=	1.12.0.20160717
PKGNAMESUFFIX=	-nightly
DISTNAME=	#
DISTFILES=	#

MAINTAINER=	dumbbell@FreeBSD.org

ONLY_FOR_ARCHS=	amd64

MASTERDIR=	${.CURDIR}/../rust
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist

USE_GITHUB=	yes
GH_TUPLE=	rust-lang:rust:7ed6068 \
		rust-lang:compiler-rt:ac3d1cd:compiler_rt/src/compiler-rt \
		rust-lang:hoedown:a3736a0:hoedown/src/rt/hoedown \
		rust-lang:jemalloc:e058ca6:jemalloc/src/jemalloc \
		rust-lang:libc:b0d6253:liblibc/src/liblibc \
		rust-lang:rust-installer:c37d374:rust_installer/src/rust-installer \
		rust-lang:llvm:7ca76af:llvm

BUILD_DEPENDS=		cmake:devel/cmake

CONFLICTS_BUILD=	rust # see FIXME in `pre-fetch` in lang/rust/Makefile
CONFLICTS_INSTALL=	rust

RUST_BOOT_VERSION=	beta

PORT_LLVM_EXTRACT_ONLY_OFF=	${DISTFILE_llvm}
PORT_LLVM_GH_PROJECT_OFF=	llvm:llvm
PORT_LLVM_GH_TAGNAME_OFF=	7ca76af:llvm
PORT_LLVM_VARS_OFF=		NOPRECIOUSMAKEVARS=1 # ARCH

post-extract-PORT_LLVM-off:
	@(${RMDIR} ${WRKSRC}/src/llvm && \
	  ${MV} ${WRKSRC_llvm} ${WRKSRC}/src/llvm)

.include "${MASTERDIR}/Makefile"
