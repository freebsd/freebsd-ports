PORTNAME=	mgwr
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Multiscale Geographically Weighted Regression
WWW=		https://mgwr.readthedocs.io/en/latest/ \
		https://github.com/pysal/mgwr

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpysal>=4.0.0:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.11:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglm>=1.0.6:math/py-spglm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spreg>=0:math/py-spreg@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
