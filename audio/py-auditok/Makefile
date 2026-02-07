PORTNAME=	auditok
DISTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio/acoustic activity detection and audio segmentation tool
WWW=		https://github.com/amsehili/auditok/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydub>0:audio/py-pydub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

NOARCH=		yes

# tests as of auditok: 7 failed, 608 passed, 218 warnings in 23.05s (failures likely to numpy-1.x while numpy-2.x would possibly work)

.include <bsd.port.mk>
