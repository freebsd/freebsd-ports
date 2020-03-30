# $FreeBSD$

PORTNAME=	xeus
DISTVERSION=	0.23.10
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ implementation of the Jupyter kernel protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cppzmq>0:net/cppzmq \
		nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack
LIB_DEPENDS=	libcryptopp.so:security/cryptopp \
		libuuid.so:misc/e2fsprogs-libuuid \
		libzmq.so:net/libzmq4

USES=		cmake compiler:c++14-lang localbase:ldflags pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	jupyter-xeus
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_STATIC_LIBS
CMAKE_ON=	DISABLE_ARCH_NATIVE

.include <bsd.port.mk>
