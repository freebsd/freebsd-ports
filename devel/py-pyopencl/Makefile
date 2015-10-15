# $FreeBSD$

PORTNAME=	pyopencl
PORTVERSION=	2015.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python wrapper for OpenCL

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:${PORTSDIR}/devel/opencl \
		${PYTHON_SITELIBDIR}/numpy/__init__.py:${PORTSDIR}/math/py-numpy
LIB_DEPENDS=	libOpenCL.so:${PORTSDIR}/devel/ocl-icd
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pytools/__init__.py:${PORTSDIR}/devel/py-pytools \
		${PYTHON_SITELIBDIR}/numpy/__init__.py:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/mako/__init__.py:${PORTSDIR}/textproc/py-mako

USE_PYTHON=	autoplist distutils
USES=		python

CPPFLAGS+=	-isystem ${LOCALBASE}/include

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -name '*.so' \
	    -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
