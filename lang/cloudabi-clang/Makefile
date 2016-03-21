# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-clang
PORTVERSION=	3.8
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	# None
DISTFILES=	# None

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Clang for CloudABI

LICENSE=	MIT

RUN_DEPENDS=	clang${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX} \
		aarch64-unknown-cloudabi-ld:${PORTSDIR}/devel/cloudabi-binutils-aarch64 \
		x86_64-unknown-cloudabi-ld:${PORTSDIR}/devel/cloudabi-binutils-x86_64

LLVM_SUFFIX=	${DISTVERSION:S/.//}

NO_BUILD=	yes

CLOUDABI_ARCHS=	aarch64-unknown-cloudabi x86_64-unknown-cloudabi

.for arch in ${CLOUDABI_ARCHS}
PLIST_FILES+=	bin/${arch}-ar bin/${arch}-cc bin/${arch}-c++ bin/${arch}-nm \
		bin/${arch}-objdump bin/${arch}-ranlib bin/${arch}-size \
		llvm${LLVM_SUFFIX}/${arch}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}
.for arch in ${CLOUDABI_ARCHS}
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/llvm-ar \
		${STAGEDIR}${PREFIX}/bin/${arch}-ar
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang \
		${STAGEDIR}${PREFIX}/bin/${arch}-cc
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang++ \
		${STAGEDIR}${PREFIX}/bin/${arch}-c++
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/llvm-nm \
		${STAGEDIR}${PREFIX}/bin/${arch}-nm
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/llvm-objdump \
		${STAGEDIR}${PREFIX}/bin/${arch}-objdump
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/llvm-ranlib \
		${STAGEDIR}${PREFIX}/bin/${arch}-ranlib
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/llvm-size \
		${STAGEDIR}${PREFIX}/bin/${arch}-size
	@${LN} -s ../${arch} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/${arch}
.endfor

.include <bsd.port.mk>
