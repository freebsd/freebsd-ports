# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>

PORTNAME=	glog
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgflags.so:devel/gflags \
		libunwind.so:devel/libunwind

USES=		cmake compiler:c++11-lang pkgconfig

CMAKE_ON=	BUILD_SHARED_LIBS WITH_GFLAGS WITH_PKGCONFIG WITH_SYMBOLIZE WITH_THREADS WITH_TLS WITH_UNWIND
CMAKE_OFF=	PRINT_UNSYMBOLIZED_STACK_TRACES WITH_CUSTOM_PREFIX WITH_GTEST

LDFLAGS+=	-lexecinfo
TEST_TARGET=	test
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

GH_ACCOUNT=	google
USE_GITHUB=	yes

.include <bsd.port.mk>
