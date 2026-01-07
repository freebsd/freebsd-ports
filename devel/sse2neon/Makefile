PORTNAME=	sse2neon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	SSE to NEON compatibility shim
WWW=		https://github.com/DLTcollab/sse2neon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386
ONLY_FOR_ARCHS_REASON=	requires x86 SSE or ARM NEON to work

BROKEN_i386=	wants to use amd64-only SSE intrinsics

TEST_TARGET=	check
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	include/sse2neon.h

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	DLTcollab

do-install:
	${INSTALL_DATA} ${WRKSRC}/sse2neon.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
