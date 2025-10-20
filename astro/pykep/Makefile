PORTNAME=	pykep
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.2
PORTREVISION=	8
CATEGORIES=	astro

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library providing basic tools for astrodynamics research
WWW=		https://github.com/esa/pykep

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_OFF=	PYKEP_BUILD_TESTS
CMAKE_TESTING_ON=	PYKEP_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	esa

.include <bsd.port.mk>
