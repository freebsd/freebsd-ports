# $FreeBSD$

PORTNAME=	cpp-hocon
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	C++ configuration library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libleatherman_util.so:devel/leatherman

USES=		cmake:noninja compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=SHARED
TEST_TARGET=	test
USE_LDCONFIG=	yes

.include <bsd.port.mk>
