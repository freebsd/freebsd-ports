PORTNAME=	libfort
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2-11
DISTVERSIONSUFFIX=	-g4123716
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C/C++ library to print formatted ASCII tables for console applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	seleznevae

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_OFF=		FORT_ENABLE_TESTING
CMAKE_TESTING_ON=	FORT_ENABLE_TESTING # 2 tests are known to fail: https://github.com/seleznevae/libfort/issues/65

# project also optionally bundles devel/astyle

.include <bsd.port.mk>
