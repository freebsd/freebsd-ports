PORTNAME=	librosa
DISTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for audio and music processing
WWW=		https://librosa.org/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}audioread>=2.1.9:audio/py-audioread@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=4.3.0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.14:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>=0.1:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=1.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.51.0:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pooch>=1.0:devel/py-pooch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.20.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.2.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SoundFile>=0.12.1:audio/py-SoundFile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soxr>=0.3.2:audio/py-soxr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.1:devel/py-typing-extensions@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}resampy>=0.2.2:audio/py-resampy@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
