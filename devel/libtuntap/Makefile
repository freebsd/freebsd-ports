# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME=	libtuntap
DISTVERSION=	0.4
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel net

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Configuring TUN or TAP devices API in a portable manner

LICENSE=	MIT

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LaKabane

OPTIONS_DEFINE=	CXX_WRPR TEST
OPTIONS_SUB=	yes

CXX_WRPR_DESC=	Build C++ wrapper library
TEST_DESC=	Build regression tests

CXX_WRPR_USES=		compiler:c++11-lang
CXX_WRPR_CMAKE_BOOL=	ENABLE_CXX
CXX_WRPR_VARS=		USE_CXXSTD=c++11
TEST_CMAKE_BOOL=	ENABLE_REGRESS
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
