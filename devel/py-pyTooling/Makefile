PORTNAME=	pyTooling
DISTVERSIONPREFIX=	v
DISTVERSION=	8.3.0
PORTREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	PYPI # requirements.txt is missing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of arbitrary classes, decorators, meta-classes, exceptions
WWW=		https://pytooling.github.io/pyTooling/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anytree>=2.8.0:devel/py-anytree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}igraph>0:math/py-igraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itertree>0:devel/py-itertree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=1.10:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.6:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=4.0.0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}treelib>0:devel/py-treelib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 8 tests fail, see https://github.com/pyTooling/pyTooling/issues/123#issuecomment-2362275029
USE_GITHUB=	yes

TEST_ARGS=	${WRKSRC}/tests/unit # skip performance and other tests

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}

# tests as of 8.3.0: 6 failed, 858 passed, 17 skipped, 6 xfailed in 20.75s

.include <bsd.port.mk>
