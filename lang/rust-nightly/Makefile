# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTVERSION=	1.17.0.20170212
PKGNAMESUFFIX=	-nightly
DISTNAME=	#
DISTFILES=	${BOOTSTRAP_FILES}

MAINTAINER=	dumbbell@FreeBSD.org

MASTERDIR=	${.CURDIR}/../rust
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

USE_GITHUB=	yes
GH_TUPLE=	rust-lang:rust:282fa87 \
		rust-lang:compiler-rt:d30da54:compiler_rt/src/compiler-rt \
		rust-lang:hoedown:da282f1:hoedown/src/rt/hoedown \
		rust-lang:jemalloc:11bfb0d:jemalloc/src/jemalloc \
		rust-lang:libc:8d8264b:liblibc/src/liblibc \
		rust-lang:rust-installer:4f99485:rust_installer/src/rust-installer

BROKEN=		needs to be adapted after changes in lang/rust

CONFLICTS_BUILD=	rust # see FIXME in `pre-fetch` in lang/rust/Makefile
CONFLICTS_INSTALL=	rust

PKGMESSAGE=	${.CURDIR}/../rust/pkg-message

RUST_BOOTSTRAP_DIR=		2017-02-01
RUST_BOOTSTRAP_VERSION=		beta

CARGO_BOOTSTRAP_DIR=		bfee18f73287687c543bda8c35e4e33808792715
CARGO_BOOTSTRAP_VERSION=	nightly

PORT_LLVM_EXTRACT_ONLY_OFF=	${DISTFILE_llvm}
PORT_LLVM_GH_TUPLE_OFF=		rust-lang:llvm:ceb177e:llvm
PORT_LLVM_VARS_OFF=		NOPRECIOUSMAKEVARS=1 # ARCH

post-extract-PORT_LLVM-off:
	@(${RMDIR} ${WRKSRC}/src/llvm && \
	  ${MV} ${WRKSRC_llvm} ${WRKSRC}/src/llvm)

.include "${MASTERDIR}/Makefile"
