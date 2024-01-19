PORTNAME=	argh
PORTVERSION=	0.31.0
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple (Python) argparse wrapper
WWW=		https://github.com/neithere/argh

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=4.11.3:devel/py-tox@${PY_FLAVOR}

USES=		python
# tests: 169 passed, 1 warning
USE_PYTHON=	autoplist pep517 pytest

.include <bsd.port.mk>
