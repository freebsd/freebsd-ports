# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-clang
PORTVERSION=	3.7
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

PLIST_FILES=	bin/x86_64-unknown-cloudabi-cc \
		bin/x86_64-unknown-cloudabi-c++ \
		llvm${LLVM_SUFFIX}/x86_64-unknown-cloudabi

do-install:
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang \
		${STAGEDIR}${PREFIX}/bin/x86_64-unknown-cloudabi-cc
	@${LN} -s ../llvm${LLVM_SUFFIX}/bin/clang++ \
		${STAGEDIR}${PREFIX}/bin/x86_64-unknown-cloudabi-c++
	@${MKDIR} ${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}
	@${LN} -s ../x86_64-unknown-cloudabi \
		${STAGEDIR}${PREFIX}/llvm${LLVM_SUFFIX}/x86_64-unknown-cloudabi

.include <bsd.port.mk>
