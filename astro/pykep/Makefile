PORTNAME=	pykep
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6
CATEGORIES=	astro

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library providing basic tools for astrodynamics research

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs

USES=		cmake compiler:c++11-lang
USE_LDCONFIG=	yes

CMAKE_OFF=	PYKEP_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	esa

.include <bsd.port.mk>
