PORTNAME=	albumentations
DISTVERSION=	1.3.1
CATEGORIES=	graphics python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast image augmentation library and wrapper around other libraries
WWW=		https://albumentations.ai/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.11.1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qudida>=0.0.4:graphics/py-qudida@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.16.1:graphics/py-scikit-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 95 tests fail, see https://github.com/albumentations-team/albumentations/issues/1505

NO_ARCH=	yes

.include <bsd.port.mk>
