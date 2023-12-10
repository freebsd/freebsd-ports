PORTNAME=	uhdm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.82
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Hardware Data Model
WWW=		https://github.com/chipsalliance/UHDM

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}orderedmultidict>0:devel/py-orderedmultidict@${PY_FLAVOR}
LIB_DEPENDS=	libcapnp.so:devel/capnproto
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang python:build tcl:86,build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	${PORTNAME:tu}

CMAKE_ON=	BUILD_SHARED_LIBS \
		UHDM_USE_HOST_CAPNP \
		UHDM_USE_HOST_GTEST
CMAKE_OFF=	UHDM_BUILD_TESTS
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD} -DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	UHDM_BUILD_TESTS # tests fail to compile, see https://github.com/chipsalliance/UHDM/issues/1045

BINARY_ALIAS=	tclsh=${TCLSH}

.include <bsd.port.mk>
