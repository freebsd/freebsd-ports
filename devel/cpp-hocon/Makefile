# $FreeBSD$

PORTNAME=	cpp-hocon
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	C++ configuration library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libleatherman_util.so:devel/leatherman

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=SHARED
TEST_TARGET=	test
USES=		cmake
USE_LDCONFIG=	yes

.include <bsd.port.mk>
