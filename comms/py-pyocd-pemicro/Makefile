PORTNAME=	pyocd-pemicro
PORTVERSION=	1.1.5
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyocd-pemicro-${PORTVERSION}

MAINTAINER=	aishapoval@mts.ru
COMMENT=	The simple PyOCD debug probe plugin for PEMicro debug probes
WWW=		https://pypi.org/project/pyocd-pemicro/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyocd>=0:comms/py-pyocd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypemicro>=0:devel/py-pypemicro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} 

USES=		python:3.9-3.11 shebangfix
USE_PYTHON=	autoplist concurrent cython pep517
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
