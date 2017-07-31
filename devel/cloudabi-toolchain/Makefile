# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-toolchain
PORTVERSION=	1.10
CATEGORIES=	devel
MASTER_SITES=	# None
DISTFILES=	# None

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ toolchain for CloudABI

LICENSE=	MIT

RUN_DEPENDS=	clang${LLVM_SUFFIX}:devel/llvm${LLVM_SUFFIX} \
		lld${LLVM_SUFFIX}:devel/llvm${LLVM_SUFFIX} \
		pkgconf:devel/pkgconf

CONFLICTS=	cloudabi-binutils-*

LLVM_SUFFIX=	40

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
		llvm${LLVM_SUFFIX}/${arch}
.endfor

do-build:
.for arch in ${CLOUDABI_ARCHS}
. for tool in ${SHELL_TOOLS}
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' -e 's:%%ARCH%%:${arch}:g' \
		${FILESDIR}/${tool}.in > ${WRKDIR}/${arch}-${tool}
. endfor
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}
.for arch in ${CLOUDABI_ARCHS}
. for tool in ${BASE_TOOLS}
	@${LN} -s /usr/bin/${tool} \
		${STAGEDIR}${PREFIX}/bin/${arch}-${tool}
. endfor
. for tool in ${LLVM_TOOLS}
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/llvm-${tool} \
		${STAGEDIR}${PREFIX}/bin/${arch}-${tool}
. endfor
. for tool in ${SHELL_TOOLS}
	${INSTALL_SCRIPT} ${WRKDIR}/${arch}-${tool} \
		${STAGEDIR}${PREFIX}/bin/${arch}-${tool}
. endfor
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang \
		${STAGEDIR}${PREFIX}/bin/${arch}-cc
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang++ \
		${STAGEDIR}${PREFIX}/bin/${arch}-c++
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/lld \
		${STAGEDIR}${PREFIX}/bin/${arch}-ld
	@${LN} -s ../${arch} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/${arch}
.endfor

.include <bsd.port.post.mk>
