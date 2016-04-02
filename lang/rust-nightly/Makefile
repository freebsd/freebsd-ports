# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTVERSION=	1.9.0.20160318
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
GH_TAGNAME=	235d77457d \
		57315f7:compiler_rt \
		4638c60:hoedown \
		aab1c0a:jemalloc \
		2278a54:liblibc \
		c37d374:rust_installer

CONFLICTS_BUILD=	rust # see FIXME in lang/rust
CONFLICTS_INSTALL=	rust

RUST_BOOT_SIG_amd64=	2016-02-17-4d3eebf-freebsd-x86_64-f38991fbb81c1cd8d0bbda396f98f13a55b42804

PORT_LLVM_EXTRACT_ONLY_OFF=	${DISTFILE_llvm}
PORT_LLVM_GH_PROJECT_OFF=	llvm:llvm
PORT_LLVM_GH_TAGNAME_OFF=	63f3a1b:llvm
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
