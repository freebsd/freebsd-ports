# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-toolchain
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	# None
DISTFILES=	# None

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C and C++ toolchain for CloudABI

LICENSE=	MIT

RUN_DEPENDS=	clang${LLVM_SUFFIX}:devel/llvm${LLVM_SUFFIX} \
		pkgconf:devel/pkgconf \
		aarch64-unknown-cloudabi-ld:devel/cloudabi-binutils-aarch64 \
		x86_64-unknown-cloudabi-ld:devel/cloudabi-binutils-x86_64

LLVM_SUFFIX=	38

CLOUDABI_ARCHS=	aarch64-unknown-cloudabi x86_64-unknown-cloudabi

LLVM_TOOLS=	ar nm objdump ranlib size
SHELL_TOOLS=	man pkg-config

.for arch in ${CLOUDABI_ARCHS}
. for tool in ${LLVM_TOOLS} ${SHELL_TOOLS}
PLIST_FILES+=	bin/${arch}-${tool}
. endfor
PLIST_FILES+=	bin/${arch}-cc bin/${arch}-c++ llvm${LLVM_SUFFIX}/${arch}
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
. for tool in ${LLVM_TOOLS}
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/llvm-${tool} \
		${STAGEDIR}${PREFIX}/bin/${arch}-${tool}
. endfor
. for tool in ${SHELL_TOOLS}
	@${INSTALL_SCRIPT} ${WRKDIR}/${arch}-${tool} \
		${STAGEDIR}${PREFIX}/bin/${arch}-${tool}
. endfor
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang \
		${STAGEDIR}${PREFIX}/bin/${arch}-cc
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang++ \
		${STAGEDIR}${PREFIX}/bin/${arch}-c++
	@${LN} -s ../${arch} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/${arch}
.endfor

.include <bsd.port.mk>
