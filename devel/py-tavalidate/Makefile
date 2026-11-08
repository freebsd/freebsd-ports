PORTNAME=	tavalidate
DISTVERSION=	0.0.6
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lazeraman@gmail.com
COMMENT=	Utilities to validate and save Tavern responses
WWW=		https://github.com/sohoffice/tavalidate

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.0.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-box>=0:devel/py-python-box@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

.include <bsd.port.mk>
