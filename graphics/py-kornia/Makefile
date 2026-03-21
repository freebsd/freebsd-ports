PORTNAME=	kornia
DISTVERSION=	0.7.4
CATEGORIES=	graphics python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Differentiable computer vision library for PyTorch
WWW=		https://kornia.readthedocs.io/en/stable/ \
		https://github.com/kornia/kornia

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kornia-rs>0:graphics/py-kornia-rs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=1.13.1:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
