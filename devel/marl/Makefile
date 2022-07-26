PORTNAME=	marl
PORTVERSION=	g20210818
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hybrid thread / fiber task scheduler written in C++11

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	riscv64
NOT_FOR_ARCHS_REASON=	assembly isn't implemented, see src/osfiber_asm.h

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	4960243
GH_TUPLE=	google:googletest:fb49e6c:googletest/third_party/googletest

CMAKE_ON=	MARL_BUILD_SHARED MARL_INSTALL
CMAKE_TESTING_ON=	MARL_BUILD_TESTS MARL_BUILD_EXAMPLES # tests are built but not run, see https://github.com/google/marl/issues/205

.include <bsd.port.mk>
