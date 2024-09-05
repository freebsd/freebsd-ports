PORTNAME=	pybind11_protobuf
PORTVERSION=	0.0.0.20240809
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pybind11 bindings for Google's Protocol Buffers
WWW=		https://github.com/pybind/pybind11_protobuf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	abseil>=20230125:devel/abseil \
		pybind11>=2.11.1:devel/pybind11
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libprotobuf.so:devel/protobuf
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}absl-py>=0:devel/py-absl-py@${PY_FLAVOR}

USES=		cmake:testing compiler:c++17-lang localbase python

CFLAGS+=	-I${WRKSRC}
CMAKE_ARGS=	-DCMAKE_INSTALL_PYDIR=${PYTHON_SITELIBDIR}
CMAKE_OFF=	BUILD_TESTING
CMAKE_ON=	USE_SYSTEM_ABSEIL \
		USE_SYSTEM_PROTOBUF \
		USE_SYSTEM_PYBIND
CMAKE_TESTING_ON=	BUILD_TESTING

USE_GITHUB=	yes
GH_ACCOUNT=	pybind
GH_TAGNAME=	f1b2459

.include <bsd.port.mk>
