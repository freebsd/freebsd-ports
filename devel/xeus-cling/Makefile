PORTNAME=	xeus-cling
DISTVERSION=	0.8.1
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Jupyter Kernel
WWW=		https://github.com/jupyter-xeus/xeus-cling

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Doesn't build: xmanager.hpp:125:35: error: no type named 'OptionException' in namespace 'cxxopts'; 0.15.3-5-g93d61b9 also doesn't build due to outdated lang/cling

BUILD_DEPENDS=	cppzmq>0:net/cppzmq \
		cxxopts>0:devel/cxxopts \
		llvm-config:lang/cling \
		nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack
LIB_DEPENDS=	libclingInterpreter.so:lang/cling \
		libpugixml.so:textproc/pugixml \
		libuuid.so:misc/libuuid \
		libxeus.so:devel/xeus \
		libzmq.so:net/libzmq4

USES=		cmake compiler:c++14-lang pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	jupyter-xeus
USE_LDCONFIG=	yes

LDFLAGS+=	${LOCALBASE}/lib/libLLVMSupport.so ${LOCALBASE}/lib/libclangAST.so -pthread # https://github.com/jupyter-xeus/xeus-cling/issues/234

OPTIONS_DEFINE=		NATIVE

NATIVE_DESC=		Build with native optimizations (-march=native)
NATIVE_CMAKE_ON=	-DDISABLE_ARCH_NATIVE=OFF
NATIVE_CMAKE_OFF=	-DDISABLE_ARCH_NATIVE=ON

.include <bsd.port.mk>
