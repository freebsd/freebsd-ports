# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-toolchain
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	# None
DISTFILES=	# None

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ toolchain for CloudABI

LICENSE=	MIT

RUN_DEPENDS=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		lld${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT} \
		pkgconf:devel/pkgconf

CONFLICTS=	cloudabi-binutils-*

CLOUDABI_ARCHS=	aarch64-unknown-cloudabi armv6-unknown-cloudabi-eabihf \
		armv7-unknown-cloudabi-eabihf i686-unknown-cloudabi \
		x86_64-unknown-cloudabi

BASE_TOOLS=	addr2line c++filt objcopy readelf strings strip
LLVM_TOOLS=	ar nm objdump ranlib size
SHELL_TOOLS=	man pkg-config

.include <bsd.port.pre.mk>

.for arch in ${CLOUDABI_ARCHS}
. for tool in ${BASE_TOOLS} ${LLVM_TOOLS} ${SHELL_TOOLS}
PLIST_FILES+=	bin/${arch}-${tool}
. endfor
PLIST_FILES+=	bin/${arch}-cc bin/${arch}-c++ bin/${arch}-ld \
		llvm${LLVM_DEFAULT}/${arch}
.endfor

do-build:
.for arch in ${CLOUDABI_ARCHS}
. for tool in ${SHELL_TOOLS}
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' -e 's:%%ARCH%%:${arch}:g' \
		${FILESDIR}/${tool}.in > ${WRKDIR}/${arch}-${tool}
. endfor
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/llvm${LLVM_DEFAULT}
.for arch in ${CLOUDABI_ARCHS}
. for tool in ${BASE_TOOLS}
	@${LN} -s /usr/bin/${tool} \
		${STAGEDIR}${PREFIX}/bin/${arch}-${tool}
. endfor
. for tool in ${LLVM_TOOLS}
	@${LN} -s ../llvm${LLVM_DEFAULT}/bin/llvm-${tool} \
		${STAGEDIR}${PREFIX}/bin/${arch}-${tool}
. endfor
. for tool in ${SHELL_TOOLS}
	${INSTALL_SCRIPT} ${WRKDIR}/${arch}-${tool} \
		${STAGEDIR}${PREFIX}/bin/${arch}-${tool}
. endfor
	@${LN} -s ../llvm${LLVM_DEFAULT}/bin/clang \
		${STAGEDIR}${PREFIX}/bin/${arch}-cc
	@${LN} -s ../llvm${LLVM_DEFAULT}/bin/clang++ \
		${STAGEDIR}${PREFIX}/bin/${arch}-c++
	@${LN} -s ../llvm${LLVM_DEFAULT}/bin/lld \
		${STAGEDIR}${PREFIX}/bin/${arch}-ld
	@${LN} -s ../${arch} ${STAGEDIR}${PREFIX}/llvm${LLVM_DEFAULT}/${arch}
.endfor

.include <bsd.port.post.mk>
