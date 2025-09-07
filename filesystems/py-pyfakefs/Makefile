PORTNAME=	pyfakefs
PORTVERSION=	5.9.2
CATEGORIES=	filesystems devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implement a fake file system that mocks the Python file system modules
WWW=		https://pytest-pyfakefs.readthedocs.io/en/stable/ \
		https://github.com/jmcgeheeiv/pyfakefs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0,1:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
