PORTNAME=	scikit-bio
PORTVERSION=	0.5.7
PORTREVISION=	2
CATEGORIES=	biology education python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data structures, algorithms, educational resources for bioinformatics
WWW=		http://scikit-bio.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BROKEN_aarch64=	fails to build: invalid conversion between vector type '__m64' (vector of 1 'long long' value) and integer type 'int' of different size, see https://github.com/biocore/scikit-bio/issues/1816

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}CacheControl>=0.11.5:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.2:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.9.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hdmedians>=0.14.1:math/py-hdmedians@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=3.2.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lockfile>=0.10.2:devel/py-lockfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4.3:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=4.0.3:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.0.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.19.1:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3.0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils cython autoplist

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}ddtrace # lib/python3.8/site-packages/benchmarks/__init__.py

.include <bsd.port.options.mk>

.if ${ARCH} == i386
CFLAGS+=	-msse2 # workaround for https://github.com/biocore/scikit-bio/issues/1727
CXXFLAGS+=	-msse2
.endif

.include <bsd.port.mk>
