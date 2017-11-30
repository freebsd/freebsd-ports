# $FreeBSD$

PORTNAME=	leatherman
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Leatherman C++ Tool library

LICENSE=	APACHE20

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl

BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option "-std=c++11"

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

USES=		cmake:outsource gettext
USE_RUBY=	yes
CMAKE_ARGS=	-DLEATHERMAN_SHARED:BOOL=ON
USE_LDCONFIG=	yes
TEST_TARGET=	test

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
