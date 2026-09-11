PORTNAME=	plac
DISTVERSION=	1.4.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line arguments parser for python
WWW=		https://github.com/ialbert/plac

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/doc

# tests as of 1.4.7:
# Results (2.55s):
#       27 passed
#        1 failed
#          - doc/test_plac.py:342 test_doctest # due to a missing file

.include <bsd.port.mk>
