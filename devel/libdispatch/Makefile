PORTNAME=	libdispatch
DISTVERSION=	6.4.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/swiftlang/swift-corelibs-libdispatch/commit/
PATCHFILES=	493f3fe6f5f6fe80b2a27be08536c55610512ec2.patch:-p1 \
		a37eeb617695310da8cfd330c3af3eb413914d3b.patch:-p1

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Grand Central Dispatch API support library

LICENSE=	APACHE20

USES=		cmake:testing compiler:c++17-lang
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	swiftlang
GH_PROJECT=	swift-corelibs-libdispatch
GH_TAGNAME=	swift-${DISTVERSION}-RELEASE

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc)
CFLAGS+=	-Wno-incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
