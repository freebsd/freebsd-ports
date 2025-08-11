PORTNAME=	pg8000
PORTVERSION=	1.31.4
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Pure-Python Interface to the PostgreSQL Database
WWW=		https://github.com/tlocke/pg8000

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch>=0:devel/py-hatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}versioningit>=3.1.0:devel/py-versioningit@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scramp>=1.4.4:security/py-scramp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.0:devel/py-asn1crypto@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pg8000-112 # lib/python3.8/site-packages/pg8000/__init__.py

NO_ARCH=	yes

.include <bsd.port.mk>
