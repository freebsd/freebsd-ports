PORTNAME=	xeus-zmq
DISTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ZeroMQ-based middleware for xeus
WWW=		https://github.com/jupyter-xeus/xeus-zmq

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cppzmq>0:net/cppzmq \
		nlohmann-json>0:devel/nlohmann-json \
		xtl-quant-stack>0:devel/xtl-quant-stack
LIB_DEPENDS=	libuuid.so:misc/libuuid \
		libxeus.so:devel/xeus \
		libzmq.so:net/libzmq4
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-kernel-test>0:devel/py-jupyter-kernel-test@${PY_FLAVOR}

USES=		cmake:testing pkgconfig python:test ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	jupyter-xeus

CMAKE_TESTING_ON=	XEUS_ZMQ_BUILD_TESTS # tests fail, see https://github.com/jupyter-xeus/xeus-zmq/issues/29

.include <bsd.port.mk>
