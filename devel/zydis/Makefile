PORTNAME=	zydis
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Fast and lightweight x86/x86-64 disassembler library
WWW=		https://zydis.re

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	see definitions in include/Zycore/Defines.h

LIB_DEPENDS=	libZycore.so:devel/zycore-c

USES=		cmake cpe dos2unix localbase:ldflags
USE_GITHUB=	yes
DOS2UNIX_FILES=	src/String.c
GH_ACCOUNT=	zyantific
GH_TUPLE=	zyantific:zycore-c:f98abdf:zydis/dependencies/zycore
CPE_VENDOR=	zyantific

CMAKE_ON=	ZYDIS_BUILD_SHARED_LIB ZYAN_SYSTEM_ZYCORE
CMAKE_OFF=	ZYDIS_BUILD_EXAMPLES

.include <bsd.port.mk>
