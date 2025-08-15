PORTNAME=	libphonenumber
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.12
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for parsing, formatting, and validating phone numbers
WWW=		https://github.com/google/libphonenumber

LICENSE=	APACHE20

LIB_DEPENDS=	libabsl_strings.so:devel/abseil \
		libboost_atomic.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libprotobuf.so:devel/protobuf
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	USE_STD_MAP
CMAKE_OFF=	REGENERATE_METADATA \
		BUILD_TESTING
CMAKE_TESTING_TARGET=	tests

WRKSRC_SUBDIR=	cpp

PLIST_SUB=	SHLIB_FULL="${DISTVERSION:R}" \
		SHLIB_SHORT="${DISTVERSION:R:R}"

.include <bsd.port.mk>
