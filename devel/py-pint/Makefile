PORTNAME=	pint
PORTVERSION=	0.25.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Physical quantities module
WWW=		https://pint.readthedocs.io/en/stable/ \
		https://github.com/hgrecco/pint

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flexcache>=0.3:devel/py-flexcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flexparser>=0.4:devel/py-flexparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.1.0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	NUMPY SCIPY UNCERTAINTIES
UNCERTAINTIES_DESC=	Handle quantities with uncertainties

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.23,1:math/py-numpy@${PY_FLAVOR}
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=0,1:science/py-scipy@${PY_FLAVOR}
UNCERTAINTIES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uncertainties>=3.1.6:math/py-uncertainties@${PY_FLAVOR}

.include <bsd.port.mk>
