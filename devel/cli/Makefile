PORTNAME=	cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for interactive command line interfaces in modern C++
WWW=		https://github.com/daniele77/cli

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/include/asio/version.hpp:net/asio \
		${LOCALBASE}/include/boost/version.hpp:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang

CMAKE_TESTING_ON=	CLI_BuildTests

USE_GITHUB=	yes
GH_ACCOUNT=	daniele77

NO_ARCH=	yes

.include <bsd.port.mk>
