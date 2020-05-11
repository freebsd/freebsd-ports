# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pip
PORTVERSION=	19.1.1
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/bb/10/44230dd6bf3563b8f227dbf344c908d412ad2ff48066476672f3a72e174e/:test_wheel \
		https://files.pythonhosted.org/packages/ec/51/f45cea425fd5cb0b0380f5b0f048ebc1da5b417e48d304838c02d6288a1e/:test_setuptools
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	setuptools-41.0.1-py2.py3-none-any.whl:test_setuptools \
		wheel-0.33.4-py2.py3-none-any.whl:test_wheel
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Tool for installing and managing Python packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Tests also need bzr, git, otherwise they fail
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}invoke>=0:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pretend>0:devel/py-pretend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-capturelog>0:devel/py-pytest-capturelog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scripttest>=1.3:devel/py-scripttest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=1.10:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.23.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		bzr>0:devel/bzr \
		git>0:devel/git \
		svn:devel/subversion

USES=		python shebangfix

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pypa-docs-theme>=g20180622:textproc/py-pypa-docs-theme@${PY_FLAVOR} \
			${PY_SPHINX}
DOCS_PORTDOCS=		*
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET=build_sphinx \
			PYDISTUTILS_BUILDARGS="-n --all-files --fresh-env"
MAKE_ENV=		PYTHONPATH=${WRKSRC}/src/

USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	src/pip/__init__.py

GH_ACCOUNT=	pypa

NO_ARCH=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")

do-test:
	${MKDIR} ${WRKSRC}/tests/data/common_wheels
	# the tests check for these wheel files, so fetch them and copy them in
	${CP} ${DISTDIR}/${DIST_SUBDIR}/setuptools-41.0.1-py2.py3-none-any.whl ${WRKSRC}/tests/data/common_wheels
	${CP} ${DISTDIR}/${DIST_SUBDIR}/wheel-0.33.4-py2.py3-none-any.whl ${WRKSRC}/tests/data/common_wheels
	${LN} -sf ${LOCALBASE}/bin/pip ${LOCALBASE}/bin/pip3
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
