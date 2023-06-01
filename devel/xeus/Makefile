PORTNAME=	xeus
DISTVERSION=	3.1.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ implementation of the Jupyter kernel protocol
WWW=		https://github.com/jupyter-xeus/xeus

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack
LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid
TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake:testing localbase:ldflags pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jupyter-xeus

CMAKE_OFF=	BUILD_STATIC_LIBS
CMAKE_TESTING_ON=	XEUS_BUILD_TESTS

OPTIONS_DEFINE=		NATIVE

NATIVE_DESC=		Build with native optimizations (-march=native)
NATIVE_CMAKE_ON=	-DXEUS_DISABLE_ARCH_NATIVE=OFF
NATIVE_CMAKE_OFF=	-DXEUS_DISABLE_ARCH_NATIVE=ON

.include <bsd.port.mk>
