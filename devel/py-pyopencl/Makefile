# $FreeBSD$

PORTNAME=	pyopencl
PORTVERSION=	2017.2
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python wrapper for OpenCL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:devel/opencl \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${FLAVOR}
LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs \
		libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py-cffi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.2.0:devel/py-decorator@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.3.6:textproc/py-mako@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=2:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytools>=2017.2:devel/py-pytools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR}

CONFIGURE_ARGS=	BOOST_INC_DIR="${LOCALBASE}/include" \
		BOOST_LIB_DIR="${LOCALBASE}/lib" \
		BOOST_PYTHON_LIBNAME=boost_python \
		CL_INC_DIR="${LOCALBASE}/include" \
		CL_LIB_DIR="${LOCALBASE}/lib" \
		USE_SHIPPED_BOOST=False
USE_PYTHON=	autoplist distutils
USES=		localbase python

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/ -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
