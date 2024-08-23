PORTNAME=	cpp-utilities
DISTVERSIONPREFIX=	v
DISTVERSION=	5.26.0-6
DISTVERSIONSUFFIX=	-g7992212
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common C++ classes such as argument parser, IO, conversion utilities
WWW=		https://github.com/Martchus/cpp-utilities

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs
TEST_DEPENDS=	cppunit>0:devel/cppunit

USES=		cmake:testing compiler:c++17-lang iconv:wchar_t localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Martchus

CXXFLAGS+=	-liconv

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ARGS=	-DEXCLUDE_TESTS_FROM_ALL=OFF # tests fail to link: ld: error: unable to find library -lcppunit, see https://github.com/Martchus/cpp-utilities/issues/27

.include <bsd.port.mk>
