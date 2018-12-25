# $FreeBSD$

PORTNAME=	xeus-cling
DISTVERSION=	0.4.10
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Jupyter Kernel

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cppzmq>0:net/cppzmq \
		cxxopts>0:devel/cxxopts \
		llvm-config:lang/cling \
		nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack
LIB_DEPENDS=	libclingInterpreter.so:lang/cling \
		libpugixml.so:textproc/pugixml \
		libuuid.so:misc/e2fsprogs-libuuid \
		libxeus.so:devel/xeus \
		libzmq.so:net/libzmq4

USES=		cmake compiler:c++14-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	QuantStack

.include <bsd.port.mk>
