PORTNAME=	textx
DISTVERSION=	4.3.0
CATEGORIES=	lang python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Meta-language for DSL implementation inspired by Xtext
WWW=		https://textx.github.io/textX/ \
		https://github.com/textX/textX/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8.0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arpeggio>=2.0.0:devel/py-arpeggio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}memory-profiler>0:devel/py-memory-profiler@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} \
		PATH=${STAGEDIR}${PREFIX}/bin:${WRKDIR}/test-prefix${PREFIX}/bin:${PATH} \
		PWD=${WRKSRC} \
		PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTHONNOUSERSITE=1 \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${WRKDIR}/test-prefix${PYTHON_SITELIBDIR}

do-test:
	@${MKDIR} ${WRKDIR}/test-dist ${WRKDIR}/test-prefix
	@cd ${WRKSRC} && \
		for project in \
		./tests/functional/registration/projects/types_dsl \
		./tests/functional/registration/projects/flow_dsl \
		./tests/functional/registration/projects/flow_codegen \
		./tests/functional/registration/projects/data_dsl \
		./tests/functional/subcommands/example_project; do \
			${SETENV} ${MAKE_ENV} PYTHONNOUSERSITE=1 ${PYTHON_CMD} -m build \
			--wheel --no-isolation --outdir ${WRKDIR}/test-dist $$project; \
		done
	@for wheel in ${WRKDIR}/test-dist/*.whl; do \
		${PYTHON_CMD} -m installer --destdir ${WRKDIR}/test-prefix \
		--prefix ${PREFIX} $$wheel; \
	done
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs tests/functional

# tests as of 4.3.0: 339 passed in 1.83s

.include <bsd.port.mk>
