PORTNAME=	pyopencl
PORTVERSION=	2026.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python wrapper for OpenCL
WWW=		https://mathema.tician.de/software/pyopencl/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl \
		${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.9.3:devel/py-scikit-build-core@${PY_FLAVOR}
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytools>=2025.1.6:devel/py-pytools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6:devel/py-typing-extensions@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++17-lang gl localbase python
USE_GL=		opengl
USE_PYTHON=	autoplist pep517 pytest

MAKE_ENV=	PYOPENCL_ENABLE_GL=ON

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/ -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
