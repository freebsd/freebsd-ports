PORTNAME=	pyopencl
PORTVERSION=	2018.2
PORTREVISION=	9
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python wrapper for OpenCL
WWW=		https://mathema.tician.de/software/pyopencl/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl \
		${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	${PY_BOOST} \
		libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.2.0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.3.6:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytools>=2017.6:devel/py-pytools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		compiler:c++11-lang localbase python
USE_PYTHON=	autoplist pep517

CONFIGURE_ARGS=	BOOST_INC_DIR="${LOCALBASE}/include" \
		BOOST_LIB_DIR="${LOCALBASE}/lib" \
		BOOST_PYTHON_LIBNAME=${PY_BOOST_LIB} \
		CL_INC_DIR="${LOCALBASE}/include" \
		CL_LIB_DIR="${LOCALBASE}/lib" \
		USE_SHIPPED_BOOST=False

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/ -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
