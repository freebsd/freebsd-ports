# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudabi-clang
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	# None
DISTFILES=	# None

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Clang for CloudABI

LICENSE=	MIT

RUN_DEPENDS=	clang-devel:${PORTSDIR}/lang/clang-devel \
		x86_64-unknown-cloudabi-ld:${PORTSDIR}/devel/cloudabi-binutils

NO_BUILD=	yes

PLIST_FILES=	bin/x86_64-unknown-cloudabi-cc \
		bin/x86_64-unknown-cloudabi-c++ \
		llvm-devel/x86_64-unknown-cloudabi

do-install:
	@${LN} -s ../llvm-devel/bin/clang \
		${STAGEDIR}${PREFIX}/bin/x86_64-unknown-cloudabi-cc
	@${LN} -s ../llvm-devel/bin/clang++ \
		${STAGEDIR}${PREFIX}/bin/x86_64-unknown-cloudabi-c++
	@${MKDIR} ${STAGEDIR}${PREFIX}/llvm-devel
	@${LN} -s ../x86_64-unknown-cloudabi \
		${STAGEDIR}${PREFIX}/llvm-devel/x86_64-unknown-cloudabi

.include <bsd.port.mk>
