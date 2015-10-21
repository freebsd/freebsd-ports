# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-clang
PORTVERSION=	3.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	# None
DISTFILES=	# None

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Clang for CloudABI

LICENSE=	MIT

RUN_DEPENDS=	clang${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX} \
		x86_64-unknown-cloudabi-ld:${PORTSDIR}/devel/cloudabi-binutils

LLVM_SUFFIX=	${DISTVERSION:S/.//}

NO_BUILD=	yes

CLOUDABI_ARCHS=	aarch64-unknown-cloudabi x86_64-unknown-cloudabi

.for arch in ${CLOUDABI_ARCHS}
PLIST_FILES+=	bin/${arch}-cc bin/${arch}-c++ llvm${LLVM_SUFFIX}/${arch}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}
.for arch in ${CLOUDABI_ARCHS}
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang \
		${STAGEDIR}${PREFIX}/bin/${arch}-cc
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang++ \
		${STAGEDIR}${PREFIX}/bin/${arch}-c++
	@${LN} -s ../${arch} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/${arch}
.endfor

.include <bsd.port.mk>
