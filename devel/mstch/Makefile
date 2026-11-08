PORTNAME=	mstch
DISTVERSION=	1.0.2-1
DISTVERSIONSUFFIX=	-g0fde1cf
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Complete implementation of {{mustache}} templates using modern C++
WWW=		https://github.com/no1msd/mstch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	no1msd
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/no1msd/mstch/issues/38

.include <bsd.port.mk>
