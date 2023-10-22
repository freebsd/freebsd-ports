PORTNAME=	auditok
DISTVERSION=	0.2.0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio/acoustic activity detection and audio segmentation tool
WWW=		https://github.com/amsehili/auditok/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# dependencies aren't listed in setup.py and pyproject.toml, see https://github.com/amsehili/auditok/issues/46
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydub>0:audio/py-pydub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

NOARCH=		yes

.include <bsd.port.mk>
