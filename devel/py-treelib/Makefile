PORTNAME=	treelib
DISTVERSION=	1.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python 2/3 implementation of tree structure
WWW=		https://treelib.readthedocs.io/en/latest/

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.13.0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=4.4.1:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=5.0.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8-black>=0.3.6:devel/py-flake8-black@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
