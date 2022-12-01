PORTNAME=	virtualenv
PORTVERSION=	20.17.0
PORTREVISION=	0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool for creating isolated Python environments
WWW=		https://virtualenv.pypa.io

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distlib>=0.3.6:devel/py-distlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distlib>=0.3.6:devel/py-distlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.4.1:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.4:devel/py-platformdirs@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage_enable_subprocess>=1.0:devel/py-coverage_enable_subprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>=3.7.0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-env>=0.6.2:devel/py-pytest-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-freezegun>=0.4.2:devel/py-pytest-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=3.10.3:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.1.0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		cpe python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	pypa
USE_PYTHON=	autoplist concurrent distutils pytest

# Fix the LookupError: setuptools-scm was unable to detect version (build target)
MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION="${PORTVERSION}"
.if make(test)
TEST_DEPENDS+=	python2:lang/python2
TEST_ENV=	PYTHONIOENCODING=utf-8 \
		PYTHONPATH="${STAGEDIR}${PYTHON_SITELIBDIR}"
QA_ENV=		IGNORE_QA_depends_blacklist=yes # we also need lang/python2 to pass some tests
.endif

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click-default-group>0:devel/py-click-default-group@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}platformdirs>0:devel/py-platformdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}proselint>0:devel/py-proselint@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-argparse>0:textproc/py-sphinx-argparse@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=1.8.0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}towncrier>=22.8.0:textproc/py-towncrier@${PY_FLAVOR}
DOCS_BINARY_ALIAS=	towncrier=towncrier-${PYTHON_VER}
DOCS_PLIST_FILES=	man/man1/virtualenv.1.gz
DOCS_PORTDOCS=		* .buildinfo
# Note: we install a temporary egg_info so that virtualenv can discover its stuff,
# while sphinx builds docs. Otherwise an Exception occurs:
#
# File "/build/lib/virtualenv/run/plugin/discovery.py", line 20, in get_discover
#    default=next(iter(choices)),
# StopIteration
#
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="install_egg_info --install-dir build/lib"

post-install-DOCS-on:
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} -b html -n ${WRKSRC}/docs ${STAGEDIR}${DOCSDIR}
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} -b man -n ${WRKSRC}/docs ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.pre.mk>

.if "${PYTHON_VER}" == "3.7"
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.8.1:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
