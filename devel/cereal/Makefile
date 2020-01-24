# $FreeBSD$

PORTNAME=		cereal
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.0
CATEGORIES=		devel

MAINTAINER=	teodor@sigaev.ru
COMMENT=	C++11 library for serialization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs
BUILD_DEPENDS=	boost-libs>=1.69:devel/boost-libs \
		cmake>=2.6.2:devel/cmake \
		ninja>=1.8.2:devel/ninja

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	USCiLab

CFLAGS+=	-Wno-unused-private-field

.include <bsd.port.mk>
