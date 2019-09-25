# $FreeBSD$

PORTNAME=	ros-urdfdom
DISTVERSION=	1.0.3
CATEGORIES=	devel

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	URDF parsers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/urdfdom_headers/cmake/urdfdom_headers-config.cmake:devel/ros-urdfdom_headers
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libconsole_bridge.so:devel/ros-console_bridge

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	ros
GH_PROJECT=	urdfdom
GH_TAGNAME=	1.0.3

.include <bsd.port.mk>
