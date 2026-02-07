PORTNAME=	innoextract
DISTVERSION=	1.9-82
DISTVERSIONSUFFIX=	-g6e9e34e
CATEGORIES=	archivers

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Program to extract Inno Setup files
WWW=		https://constexpr.org/innoextract/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang iconv localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	dscharrer
CMAKE_ON=	Boost_USE_STATIC_LIBS
CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=	check

PLIST_FILES=	bin/innoextract \
		share/man/man1/innoextract.1.gz

.include <bsd.port.mk>
