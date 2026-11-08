PORTNAME=	auditok
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
CATEGORIES=	audio python
#MASTER_SITES=	PYPI # no testdata
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio/acoustic activity detection and audio segmentation tool
WWW=		https://github.com/amsehili/auditok/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sounddevice>0:audio/py-sounddevice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	amsehili

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload

# tests as of 0.5.2: 817 passed, 1 skipped, 15 warnings in 18.77s

.include <bsd.port.mk>
