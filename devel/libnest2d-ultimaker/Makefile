# XXX ultimaker forked libnest2d, and never upstreamed patches
# includes commits since tag 0.4
PORTNAME=	libnest2d-ultimaker
DISTVERSION=	0.4
CATEGORIES=	devel

MAINTAINER=	y@trombik.org
COMMENT=	2D irregular bin packaging and nesting library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
	libpolyclipping.so:graphics/polyclipping \
	libnlopt.so:math/nlopt

USES=	cmake
USE_GITHUB=	yes
GH_TUPLE=	Ultimaker:libnest2d:4d6fb4d

.include <bsd.port.mk>
