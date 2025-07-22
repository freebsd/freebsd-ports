PORTNAME=	virtualenv
PORTVERSION=	20.32.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool for creating isolated Python environments
WWW=		https://virtualenv.pypa.io

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distlib>=0.3.7:devel/py-distlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0.3:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.17.1:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distlib>=0.3.7:devel/py-distlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.12.2:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=3.9.1:devel/py-platformdirs@${PY_FLAVOR}
# tests: 321 passed, 33 skipped
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}covdefaults>=2.3:devel/py-covdefaults@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=7.3.2:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage_enable_subprocess>=1.0:devel/py-coverage_enable_subprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>=3.7.0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-env>=0.6.2:devel/py-pytest-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-freezer>=0.4.9:devel/py-pytest-freezer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.10:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=3.12:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.1.0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}time-machine>=2.10.0:devel/py-time-machine@${PY_FLAVOR} \
		nu:shells/nushell

USES=		cpe python
USE_GITHUB=	yes
GH_ACCOUNT=	pypa
USE_PYTHON=	autoplist concurrent pep517 pytest

# Fix the LookupError: setuptools-scm was unable to detect version (build target)
MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION="${PORTVERSION}"

.if make(test)
TEST_ENV=	PYTHONIOENCODING=utf-8 \
		PYTHONPATH="${STAGEDIR}${PYTHON_SITELIBDIR}"
.endif

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click-default-group>=1.2.4:devel/py-click-default-group@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}filelock>=3.12.2:sysutils/py-filelock@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}furo>=2023.7.26:textproc/py-furo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}platformdirs>3.9.1:devel/py-platformdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}proselint>=0.13:devel/py-proselint@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-argparse>=0.4:textproc/py-sphinx-argparse@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=5.3.0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-towncrier>=0.3.2a0:textproc/py-sphinxcontrib-towncrier@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}towncrier>=22.12.0:textproc/py-towncrier@${PY_FLAVOR}
DOCS_BINARY_ALIAS=	towncrier=towncrier-${PYTHON_VER}
DOCS_PLIST_FILES=	share/man/man1/virtualenv.1.gz
DOCS_PORTDOCS=		* .buildinfo

# Fix the Exception:
#
# File "/build/lib/virtualenv/run/plugin/discovery.py", line 20, in get_discover
#    default=next(iter(choices)),
# StopIteration
#
# Apparently it doesn't work setting PYTHONPATH environment variable...
VIRTUALENV_WHEEL=	${WRKSRC}/dist/${PORTNAME}-${PORTVERSION}-py${PYTHON_MAJOR_VER}-none-any.whl

post-patch:
	@${SED} -i.bak -e 's,%%VIRTUALENV_WHEEL%%,${VIRTUALENV_WHEEL},1' \
	-e 's,%%PYTHON_VER%%,${PYTHON_VER},1' \
	${WRKSRC}/docs/conf.py

post-install-DOCS-on:
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} -b html -n ${WRKSRC}/docs ${STAGEDIR}${DOCSDIR}
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} -b man -n ${WRKSRC}/docs ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
