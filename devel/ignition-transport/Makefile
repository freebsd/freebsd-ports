# $FreeBSD$

PORTNAME=	ignition-transport
DISTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Ignition transport classes and functions for robot applications

LICENSE=	APACHE20

BUILD_DEPENDS=	ignition-cmake==2:devel/ignition-cmake \
		ignition-tools>0:devel/ignition-tools \
		cppzmq>0:net/cppzmq
LIB_DEPENDS=	libignition-math6.so:math/ignition-math \
		libignition-msgs3.so:devel/ignition-msgs \
		libprotobuf.so:devel/protobuf \
		libuuid.so:misc/e2fsprogs-libuuid \
		libzmq.so:net/libzmq4
RUN_DEPENDS=	ignition-tools>0:devel/ignition-tools

USES=		cmake pkgconfig sqlite
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_TESTING

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-transport
BB_COMMIT=	4b78da2af04c

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_SUB+=	TRANSPORT_IGN_VER=transport${DISTVERSION:R:R}

do-test: # 1 test is known to fail: https://bitbucket.org/ignitionrobotics/ign-transport/issues/100/test-integration_log_versioned_symbols
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTING=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
