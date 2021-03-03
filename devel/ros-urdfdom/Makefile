# $FreeBSD$

PORTNAME=	ros-urdfdom
DISTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Unified Robot Description Format (URDF) parsers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ros-urdfdom_headers>0:devel/ros-urdfdom_headers
LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml \
		libconsole_bridge.so:devel/ros-console_bridge
RUN_DEPENDS=	ros-urdfdom_headers>0:devel/ros-urdfdom_headers

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	ros
GH_PROJECT=	${PORTNAME:S/ros-//}

do-test: # some tests are known to fail: https://github.com/ros/urdfdom/issues/118
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
