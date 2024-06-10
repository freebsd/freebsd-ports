PORTNAME=	mimalloc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.7
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	General-purpose allocator with excellent performance characteristics
WWW=		https://github.com/microsoft/mimalloc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
USE_LDCONFIG=	yes

CMAKE_ON=	MI_INSTALL_TOPLEVEL
CMAKE_OFF=	MI_BUILD_OBJECT MI_BUILD_TESTS

CMAKE_TESTING_ON=	MI_BUILD_TESTS

# ci pipeline creates transient tags
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
