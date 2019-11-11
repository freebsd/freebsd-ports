# $FreeBSD$

PORTNAME=	leatherman
PORTVERSION=	1.9.0
CATEGORIES=	devel

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Leatherman C++ Tool library

LICENSE=	APACHE20

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		compiler:c++11-lang cmake gettext
USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

USE_RUBY=	yes
CMAKE_ON=	LEATHERMAN_SHARED
CMAKE_OFF=	ENABLE_CXX_WERROR
USE_LDCONFIG=	yes
TEST_TARGET=	test

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
