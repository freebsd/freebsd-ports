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
GH_ACCOUNT=	rust-lang
GH_PROJECT=	rust \
		compiler-rt:compiler_rt \
		hoedown:hoedown \
		jemalloc:jemalloc \
		libc:liblibc \
		rust-installer:rust_installer
GH_TAGNAME=	7ed6068 \
		ac3d1cd:compiler_rt \
		a3736a0:hoedown \
		e058ca6:jemalloc \
		b0d6253:liblibc \
		c37d374:rust_installer

BUILD_DEPENDS=		cmake:devel/cmake

CONFLICTS_BUILD=	rust # see FIXME in `pre-fetch` in lang/rust/Makefile
CONFLICTS_INSTALL=	rust

RUST_BOOT_VERSION=	beta

PORT_LLVM_EXTRACT_ONLY_OFF=	${DISTFILE_llvm}
PORT_LLVM_GH_PROJECT_OFF=	llvm:llvm
PORT_LLVM_GH_TAGNAME_OFF=	7ca76af:llvm
PORT_LLVM_VARS_OFF=		NOPRECIOUSMAKEVARS=1 # ARCH

post-extract:	slave-post-extract
slave-post-extract:
	@(${RMDIR} ${WRKSRC}/src/compiler-rt && \
	  ${MV} ${WRKSRC_compiler_rt} ${WRKSRC}/src/compiler-rt)
	@(${RMDIR} ${WRKSRC}/src/rt/hoedown && \
	  ${MV} ${WRKSRC_hoedown} ${WRKSRC}/src/rt/hoedown)
	@(${RMDIR} ${WRKSRC}/src/jemalloc && \
	  ${MV} ${WRKSRC_jemalloc} ${WRKSRC}/src/jemalloc)
	@(${RMDIR} ${WRKSRC}/src/liblibc && \
	  ${MV} ${WRKSRC_liblibc} ${WRKSRC}/src/liblibc)
	@(${RMDIR} ${WRKSRC}/src/rust-installer && \
	  ${MV} ${WRKSRC_rust_installer} ${WRKSRC}/src/rust-installer)

post-extract-PORT_LLVM-off:
	@(${RMDIR} ${WRKSRC}/src/llvm && \
	  ${MV} ${WRKSRC_llvm} ${WRKSRC}/src/llvm)

.include "${MASTERDIR}/Makefile"
