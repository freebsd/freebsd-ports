PORTNAME=	zycore-c
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Support library with platform independent types, macros, etc for Zydis
WWW=		https://zydis.re

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	see definitions in include/Zycore/Defines.h

USES=		cmake:testing compiler:c++17-lang cpe
CPE_VENDOR=	zyantific

USE_GITHUB=	yes
GH_ACCOUNT=	zyantific

CMAKE_ON=	ZYCORE_BUILD_SHARED_LIB
CMAKE_TESTING_ON=	ZYCORE_BUILD_TESTS

.include <bsd.port.mk>
