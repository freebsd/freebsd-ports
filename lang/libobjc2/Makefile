# Created by: Pete French <pete@twisted.org.uk>
# $FreeBSD$

PORTNAME=	libobjc2
PORTVERSION=	2.1
CATEGORIES=	lang devel gnustep

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement Objective-C runtime supporting modern Objective-C features

LICENSE=	MIT

BROKEN_sparc64=		Does not compile on sparc64: Cannot configure clang properly
USES=		cmake compiler objc:compiler

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_TAGNAME=	0db500a

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DLIB_INSTALL_PATH=lib
CMAKE_ARGS+=	-DTESTS=OFF

CFLAGS+=	-fcommon

LDFLAGS_armv7=	-Wl,-znotext
SSP_UNSAFE=	yes

PLIST_SUB+=	SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

SHLIB_MAJOR=	4
SHLIB_MINOR=	6

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-stdlib=libstdc++
.endif

post-install:
	${LN} -sf libobjc.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/libobjc.so.${SHLIB_MAJOR}

.include <bsd.port.post.mk>
