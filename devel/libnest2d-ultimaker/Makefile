PORTNAME=	libnest2d-ultimaker
# XXX there is no 4.13.1
# https://github.com/Ultimaker/libnest2d/tags
DISTVERSION=	4.12.0
CATEGORIES=	devel

MAINTAINER=	db@FreeBSD.org
COMMENT=	2D irregular bin packaging and nesting library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
	libpolyclipping.so:graphics/polyclipping \
	libnlopt.so:math/nlopt

USES=	cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Ultimaker
GH_PROJECT=	libnest2d

.include <bsd.port.mk>
