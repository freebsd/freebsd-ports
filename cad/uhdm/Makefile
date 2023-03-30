PORTNAME=	uhdm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.51
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Hardware Data Model
WWW=		https://github.com/chipsalliance/UHDM

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}orderedmultidict>0:devel/py-orderedmultidict@${PY_FLAVOR}

USES=		cmake:testing python:build tcl:86,build
USE_LDCONFIG=	${PREFIX}/lib/uhdm

USE_GITHUB=	yes
GH_ACCOUNT=	chipsalliance
GH_PROJECT=	${PORTNAME:tu}
GH_TUPLE=	capnproto:capnproto:14f24a4:capnproto/third_party/capnproto \
		google:googletest:e2239ee:googletest/third_party/googletest

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	UHDM_BUILD_TESTS
CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	UHDM_BUILD_TESTS

CONFLICTS_INSTALL=	capnproto capnproto080 surelog # bin/uhdm-dump lib/libcapnp.so

BINARY_ALIAS=	tclsh=${TCLSH}

.include <bsd.port.mk>
