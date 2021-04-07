PORTNAME=	ros-console_bridge
DISTVERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	ROS-independent logging that pipes into ROS packages

LICENSE=	BSD3CLAUSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	ros
GH_PROJECT=	${PORTNAME:S/ros-//}

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DDO_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
