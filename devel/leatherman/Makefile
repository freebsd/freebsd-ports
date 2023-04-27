PORTNAME=	leatherman
PORTVERSION=	1.12.9
PORTREVISION=	1
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

post-configure:
	# This file is vendored in vendor/Catch-1.10.0.zip and extracted at configure step
	${SED} -i '' -e '1s|\(.*\)|#include <sys/signal.h>\n\1|' ${CONFIGURE_WRKSRC}/src/Catch-1.10.0/single_include/catch.hpp

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
