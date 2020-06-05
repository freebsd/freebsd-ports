# $FreeBSD$

PORTNAME=	libphonenumber
DISTVERSIONPREFIX=	v
DISTVERSION=	8.12.5
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for parsing, formatting, and validating phone numbers

LICENSE=	APACHE20

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libprotobuf.so:devel/protobuf

USES=		cmake:noninja compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	googlei18n

CMAKE_ON=	USE_STD_MAP

WRKSRC_SUBDIR=	cpp

.include <bsd.port.mk>
