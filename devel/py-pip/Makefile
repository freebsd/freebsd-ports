# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	pip
PORTVERSION=	22.1.2
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/fb/58/9efbfe68482dab9557c49d433a60fff9efd7ed8835f829eba8297c2c124a/:test_setuptools \
		https://files.pythonhosted.org/packages/27/d6/003e593296a85fd6ed616ed962795b2f87709c3eee2bca4f6d0fe55c6d00/:test_wheel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	setuptools-62.1.0-py3-none-any.whl:test_setuptools \
		wheel-0.37.1-py2.py3-none-any.whl:test_wheel
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Tool for installing and managing Python packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Tests also need bzr, git, otherwise they fail
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scripttest>=0:devel/py-scripttest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		hg:devel/mercurial \
		git:devel/git \
		svn:devel/subversion

USES=		cpe python:3.7+ shebangfix
CPE_VENDOR=	pypa
USE_PYTHON=	autoplist concurrent distutils pytest

MAKE_ENV=	PYTHONPATH=${WRKSRC}/src/
NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

USE_GITHUB=	yes
GH_ACCOUNT=	pypa

SHEBANG_FILES=	src/pip/__init__.py

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}furo>=0:textproc/py-furo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}myst-parser>=0:textproc/py-myst-parser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=4.2,1<5,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-copybutton>=0:textproc/py-sphinx-copybutton@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-inline-tabs>=0:textproc/py-sphinx-inline-tabs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-towncrier>=0.2.0a0:textproc/py-sphinxcontrib-towncrier@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}towncrier>=0:textproc/py-towncrier@${PY_FLAVOR}
DOCS_PORTDOCS=		*
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET=build_sphinx \
			PYDISTUTILS_BUILDARGS="-n --all-files --fresh-env"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")

pre-test:
	${MKDIR} ${WRKSRC}/tests/data/common_wheels
	# the tests check for these wheel files, so fetch them and copy them in
	${CP} ${DISTDIR}/${DIST_SUBDIR}/setuptools-62.1.0-py3-none-any.whl ${WRKSRC}/tests/data/common_wheels
	${CP} ${DISTDIR}/${DIST_SUBDIR}/wheel-0.37.1-py2.py3-none-any.whl ${WRKSRC}/tests/data/common_wheels
	${LN} -sf ${LOCALBASE}/bin/pip ${LOCALBASE}/bin/pip3

.include <bsd.port.mk>
