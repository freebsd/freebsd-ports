PORTNAME=	schema-salad
PORTVERSION=	8.10.20261106141337
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	schema_salad-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schema Annotations for Linked Avro Data (SALAD)
WWW=		https://schema-salad.readthedocs.io/ \
		https://github.com/common-workflow-language/schema_salad

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.13.1:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=3.3.0:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.2.2:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=1.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich-argparse>0:textproc/py-rich-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.17.6:devel/py-ruamel.yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		--deselect src/schema_salad/tests/test_cg.py::test_load_by_yaml_metaschema \
		--deselect src/schema_salad/tests/test_examples.py::test_bad_schemas \
		--ignore src/schema_salad/tests/test_cwl11.py # test_load_by_yaml_metaschema fails with ruamel.yaml 0.19, the others need network access

# tests as of 8.10.20261106141337: 190 passed, 2 skipped, 2 deselected, 9 warnings in 62.85s (0:01:02)

.include <bsd.port.mk>
