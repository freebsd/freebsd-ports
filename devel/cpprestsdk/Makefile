# $FreeBSD$

PORTNAME=	cpprestsdk
PORTVERSION=	2.9.1
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	projects@phess.net
COMMENT=	Microsoft C++ REST SDK

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../license.txt

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake compiler:c++11-lib ssl
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft
WRKSRC_SUBDIR=	Release
CMAKE_OFF=	BUILD_SAMPLES BUILD_TESTS

.include <bsd.port.mk>
