# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=		cpp-netlib
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=		0.12.0
DISTVERSIONSUFFIX=	-final
PORTREVISION=		1
CATEGORIES=		devel

MAINTAINER=		zi@FreeBSD.org
COMMENT=		Cross-platform, standards compliant networking library

LICENSE=		BSL
LICENSE_FILE=		${WRKSRC}/LICENSE_1_0.txt

BUILD_DEPENDS=		boost-libs>0:devel/boost-libs \
					asio>0:net/asio

BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option "-std=c++11"

USES=			cmake:outsource
USE_LDCONFIG=		yes
CFLAGS+=	-fPIC
CMAKE_ARGS+=		-DCPP-NETLIB_BUILD_EXAMPLES=OFF \
			-DCPP-NETLIB_BUILD_SHARED_LIBS=ON \
			-DCPP-NETLIB_BUILD_TESTS=OFF
USE_GITHUB=		yes

.include <bsd.port.mk>
