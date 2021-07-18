# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	pip
PORTVERSION=	20.3.4
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/f9/d3/955738b20d3832dfa3cd3d9b07e29a8162edb480bf988332f5e6e48ca444/:test_setuptools \
		https://files.pythonhosted.org/packages/a7/00/3df031b3ecd5444d572141321537080b40c1c25e1caa3d86cdd12e5e919c/:test_wheel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	setuptools-44.0.0-py2.py3-none-any.whl:test_setuptools \
		wheel-0.35.1-py2.py3-none-any.whl:test_wheel
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Tool for installing and managing Python packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Tests also need bzr, git, otherwise they fail
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}csv23>=0:devel/py-csv23@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}invoke>=0:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pretend>=0:devel/py-pretend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scripttest>=0:devel/py-scripttest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=0:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		hg:devel/mercurial \
		git:devel/git \
		svn:devel/subversion

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

MAKE_ENV=	PYTHONPATH=${WRKSRC}/src/
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pypa

SHEBANG_FILES=	src/pip/__init__.py

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}furo>=0:textproc/py-furo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=2.4.3,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-inline-tabs>=0:textproc/py-sphinx-inline-tabs@${PY_FLAVOR}
DOCS_PORTDOCS=		*
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET=build_sphinx \
			PYDISTUTILS_BUILDARGS="-n --all-files --fresh-env"

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30700 && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}future-annotations>=0:devel/py-future-annotations@${PY_FLAVOR}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-python36
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")

do-test:
	${MKDIR} ${WRKSRC}/tests/data/common_wheels
	# the tests check for these wheel files, so fetch them and copy them in
	${CP} ${DISTDIR}/${DIST_SUBDIR}/setuptools-44.0.0-py2.py3-none-any.whl ${WRKSRC}/tests/data/common_wheels
	${CP} ${DISTDIR}/${DIST_SUBDIR}/wheel-0.35.1-py2.py3-none-any.whl ${WRKSRC}/tests/data/common_wheels
	${LN} -sf ${LOCALBASE}/bin/pip ${LOCALBASE}/bin/pip3
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
