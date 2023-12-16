PORTNAME=	pint
PORTVERSION=	0.23
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pint-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Physical quantities module
WWW=		https://pint.readthedocs.io/en/stable/ \
		https://github.com/hgrecco/pint

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.3:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	NUMPY UNCERTAINTIES
NUMPY_DESC=	Automatic conversion of units
UNCERTAINTIES_DESC=	Handle quantities with uncertainties

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.19.5,1:math/py-numpy@${PY_FLAVOR}
UNCERTAINTIES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uncertainties>=3.1.6:math/py-uncertainties@${PY_FLAVOR}

.include <bsd.port.mk>
