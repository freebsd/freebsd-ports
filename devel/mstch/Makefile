PORTNAME=	mstch
DISTVERSION=	1.0.2-1
DISTVERSIONSUFFIX=	-g0fde1cf
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Complete implementation of {{mustache}} templates using modern C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	no1msd
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
