PORTNAME=	cascadio
DISTVERSION=	0.1.1
CATEGORIES=	cad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert STEP files to GLB using OpenCASCADE
WWW=		https://github.com/trimesh/cascadio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE/LICENSE-cascadio.md

BUILD_DEPENDS=	rapidjson>0:devel/rapidjson \
		${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR}
BUILD_RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR}
LIB_DEPENDS=	libTKernel.so:cad/opencascade
TEST_DEPENDS:	${PYTHON_PKGNAMEPREFIX}trimesh>0:devel/py-trimesh@${PY_FLAVOR} # circular deps for the 1st time

USES=		cmake:indirect dos2unix localbase ninja:build pytest python shebangfix
USE_PYTHON=	pep517
DOS2UNIX_FILES=	src/convert.hpp scripts/build_schema.py scripts/color_by_primitive.py
SHEBANGFILES=	scripts/*

USE_GITHUB=	yes
GH_ACCOUNT=	trimesh

CFLAGS+=	-I${LOCALBASE}/include/OpenCASCADE
MAKE_ENV=	CMAKE_ARGS="-DSYSTEM_OPENCASCADE:BOOL=ON"
TEST_ENV=	PYTEST_DISABLE_PLUGIN_AUTOLOAD=1
BINARY_ALIAS=	python=${PYTHON_CMD}

TESTING_UNSAFE=yes	# brep not implemented in this port

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
