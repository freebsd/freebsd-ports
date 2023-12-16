PORTNAME=	ddt
PORTVERSION=	1.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Data-Driven Tests for Python Unittest
WWW=		https://readthedocs.org/projects/ddt/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes

.include <bsd.port.mk>
