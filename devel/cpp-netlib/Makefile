# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=		cpp-netlib
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=		0.13.0
DISTVERSIONSUFFIX=	-final
CATEGORIES=		devel

MAINTAINER=		zi@FreeBSD.org
COMMENT=		Cross-platform, standards compliant networking library

LICENSE=		BSL
LICENSE_FILE=		${WRKSRC}/LICENSE_1_0.txt

LIB_DEPENDS=		libboost_system.so:devel/boost-libs
BUILD_DEPENDS=		boost-libs>0:devel/boost-libs \
			asio>0:net/asio

USES=			cmake compiler:c++11-lang ssl
USE_LDCONFIG=		yes
CFLAGS+=		-fPIC
CMAKE_ARGS+=		-DCPP-NETLIB_BUILD_EXAMPLES=OFF \
			-DCPP-NETLIB_BUILD_SHARED_LIBS=ON \
			-DCPP-NETLIB_BUILD_TESTS=OFF
USE_GITHUB=		yes

.include <bsd.port.mk>
