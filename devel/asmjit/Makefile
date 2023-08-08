PORTNAME=	asmjit
DISTVERSION=	g20221210
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Complete x86/x64 JIT and AOT Assembler for C++
WWW=		https://asmjit.com/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	only implements x86 and x64 assembly

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	5b5b0b3

CMAKE_TESTING_ON=	ASMJIT_TEST

.include <bsd.port.mk>
