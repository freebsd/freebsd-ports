# $FreeBSD$

PORTNAME=	asmjit
DISTVERSION=	g20200101
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Complete x86/x64 JIT and AOT Assembler for C++

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	only implements x86 and x64 assembly

USES=		cmake
USE_GITHUB=	yes
GH_TAGNAME=	911a9a50a2cbc9802c4d44e94b8b99e1d9285cf3
USE_LDCONFIG=	yes

.include <bsd.port.mk>
