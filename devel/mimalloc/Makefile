PORTNAME=	mimalloc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.6
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	General-purpose allocator with excellent performance characteristics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
USE_LDCONFIG=	yes

CMAKE_ON=	MI_INSTALL_TOPLEVEL
CMAKE_OFF=	MI_BUILD_OBJECT

TEST_TARGET=	test

# ci pipeline creates transient tags
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
