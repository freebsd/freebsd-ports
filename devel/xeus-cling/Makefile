# $FreeBSD$

PORTNAME=	xeus-cling
DISTVERSION=	0.4.6
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Jupyter Kernel

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cppzmq>0:net/cppzmq \
		cxxopts>0:devel/cxxopts \
		czmq>0:net/czmq \
		llvm-config:lang/cling
LIB_DEPENDS=	libclingInterpreter.so:lang/cling \
		libcryptopp.so:security/cryptopp \
		libpugixml.so:textproc/pugixml \
		libuuid.so:misc/e2fsprogs-libuuid \
		libxeus.so:devel/xeus \
		libzmq.so:net/libzmq4

USES=		cmake:outsource pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	QuantStack

.include <bsd.port.mk>
