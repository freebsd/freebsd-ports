PORTNAME=	sqlfluff
PORTVERSION=	4.4.0
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SQL Linter for Humans
WWW=		https://sqlfluff.com/ \
		https://github.com/sqlfluff/sqlfluff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}platformdirs>=0:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diff-cover>=2.5.0:devel/py-diff-cover@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tblib>=0:devel/py-tblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest
PYTEST_BROKEN_TESTS=	test__plugin_manager_registers_example_plugin \
			test__plugin_example_rules_returned[Rule_Example_L001] \
			test__plugin_default_config_read[Example_L001-forbidden_columns]

USE_GITHUB=	yes
GH_ACCOUNT=	sqlfluff

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=   ${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
