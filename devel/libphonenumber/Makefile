PORTNAME=	libphonenumber
DISTVERSIONPREFIX=	v
DISTVERSION=	8.13.41
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for parsing, formatting, and validating phone numbers
WWW=		https://github.com/google/libphonenumber

LICENSE=	APACHE20

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libabsl_strings.so:devel/abseil \
		libboost_atomic.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libprotobuf.so:devel/protobuf

USES=		cmake:noninja compiler:c++17-lang pkgconfig
# Workaround CMAKE_ARGS+=-DABSL_PROPAGATE_CXX_STD:BOOL=ON not being set in the
# devel/abseil Makefile. As of version 8.13.21, libphonenumber no longer sets
# the C++ dialect and expects to inherit it from abseil.
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON=	USE_STD_MAP
CMAKE_OFF=	REGENERATE_METADATA \
		BUILD_TESTING

WRKSRC_SUBDIR=	cpp

MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	SHLIB_FULL=${PORTVERSION:R} SHLIB_SHORT=${PORTVERSION:R:R}

.include <bsd.port.mk>
