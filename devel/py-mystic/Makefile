PORTNAME=	mystic
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Highly-constrained non-convex optimization and uncertainty quantification
WWW=		https://github.com/uqfoundation/mystic

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dill>=0.3.6:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}klepto>=0.2.3:devel/py-klepto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>=0.19:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=0.6.7:math/py-sympy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

NO_ARCH=	yes

.include <bsd.port.mk>
