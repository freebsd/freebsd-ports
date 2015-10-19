# $FreeBSD$

PORTNAME=	pyopencl
PORTVERSION=	2015.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python wrapper for OpenCL

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/CL/cl.h:${PORTSDIR}/devel/opencl \
		${PYTHON_PKGNAMEPREFIX}numpy>0:${PORTSDIR}/math/py-numpy
LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
		libOpenCL.so:${PORTSDIR}/devel/ocl-icd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytools>0:${PORTSDIR}/devel/py-pytools \
		${PYTHON_PKGNAMEPREFIX}numpy>0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako

USE_PYTHON=	autoplist distutils
USES=		python

CONFIGURE_ARGS=	--boost-inc-dir="${LOCALBASE}/include" \
		--boost-lib-dir="${LOCALBASE}/lib" \
		--boost-python-libname=boost_python \
		--cl-inc-dir="${LOCALBASE}/include" \
		--cl-lib-dir="${LOCALBASE}/lib" \
		--no-use-shipped-boost

do-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -name '*.so' \
	    -exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
