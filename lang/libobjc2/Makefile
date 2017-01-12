# Created by: Pete French <pete@twisted.org.uk>
# $FreeBSD$

PORTNAME=	libobjc2
PORTVERSION=	1.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	lang devel gnustep

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Replacement Objective-C runtime supporting modern Objective-C features

SSP_UNSAFE=	yes

USES=		cmake objc:compiler
BROKEN_powerpc=		Does not compile on powerpc: Unsupported relocation type 10
BROKEN_sparc64=		Does not compile on sparc64: Cannot configure clang properly

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep

SHLIB_MAJOR=	4
SHLIB_MINOR=	6

PLIST_SUB+=	SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

CMAKE_ARGS+=	-DLIB_INSTALL_PATH=lib
CMAKE_ARGS+=	-DTESTS=OFF
# This shouldn't be needed, but our llvm port installs llvm-config with a silly
# name...
CMAKE_ARGS+=	-DLLVM_OPTS=OFF

post-install:
	${LN} -sf libobjc.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/libobjc.so.${SHLIB_MAJOR}

.include <bsd.port.mk>
