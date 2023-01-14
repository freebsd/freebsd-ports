PORTNAME=	leatherman
PORTVERSION=	1.12.6
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Leatherman C++ Tool library
WWW=		https://github.com/puppetlabs/leatherman

LICENSE=	APACHE20

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		compiler:c++11-lang cmake gettext ruby
USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

CMAKE_ON=	LEATHERMAN_SHARED
CMAKE_OFF=	ENABLE_CXX_WERROR
USE_LDCONFIG=	yes
TEST_TARGET=	test

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
