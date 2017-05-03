# $FreeBSD$

PORTNAME=	cpp-hocon
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jslagle@gmail.com
COMMENT=	C++ configuration library

LICENSE=	APACHE20

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libleatherman_util.so:devel/leatherman

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

USES=		cmake
CMAKE_ARGS=	-DCPP_HOCON_SHARED:BOOL=ON

.include <bsd.port.mk>
