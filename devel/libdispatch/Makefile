PORTNAME=	libdispatch
DISTVERSION=	6.1.1
PORTEPOCH=	1
CATEGORIES=	devel

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
