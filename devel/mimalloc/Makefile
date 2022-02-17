# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	mimalloc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.5
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
TEST_TARGET=	test

# ci pipeline creates transient tags
PORTSCOUT=	ignore:1

post-install: # workaround for https://github.com/microsoft/mimalloc/issues/398
	@${RM} ${STAGEDIR}${PREFIX}/lib/mimalloc.o

.include <bsd.port.mk>
