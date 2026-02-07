PORTNAME=	xeus
DISTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ implementation of the Jupyter kernel protocol
WWW=		https://github.com/jupyter-xeus/xeus

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack
LIB_DEPENDS=	libuuid.so:misc/libuuid
TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake:testing localbase:ldflags pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jupyter-xeus

CMAKE_OFF=	BUILD_STATIC_LIBS
CMAKE_TESTING_ON=	XEUS_BUILD_TESTS

.include <bsd.port.mk>
