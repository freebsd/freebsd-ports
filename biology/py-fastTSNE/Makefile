# $FreeBSD$

PORTNAME=	fastTSNE
DISTVERSION=	0.2.13
PORTREVISION=	4
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, parallel implementations of t-SNE

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.38.1:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.20.0:science/py-scikit-learn@${PY_FLAVOR}

USES=		localbase:ldflags python:3.5+
USE_PYTHON=	distutils autoplist

PORTSCOUT=	skipv:0.2.14 # no such version, not sure where does portscout see it

.include <bsd.port.mk>
