PORTNAME=	librosa
DISTVERSION=	0.9.2
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for audio and music processing
WWW=		https://librosa.org/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}audioread>=2.1.9:audio/py-audioread@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=4.0.10:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.14:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.45.1:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pooch>=1.0:devel/py-pooch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resampy>=0.2.2:audio/py-resampy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.19.1:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.2.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SoundFile>=0.10.2:audio/py-SoundFile@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
