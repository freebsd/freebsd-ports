PORTNAME=	setuptools-scm
DISTVERSION=	9.2.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/[-_.]+/_/g}-${DISTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Setuptools plugin to manage your versions by scm tags
WWW=		https://setuptools-scm.readthedocs.io/en/latest/ \
		https://github.com/pypa/setuptools-scm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}build>=0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR} \
		${PY_TYPING_EXTENSIONS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}griffe>0:textproc/py-griffe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		git:devel/git \
		gpg2:security/gnupg \
		${PY_MERCURIAL} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>=0:devel/py-setuptools_scm_git_archive@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

# test_dump_version_mypy	https://github.com/pypa/setuptools-scm/issues/1204
# test_not_owner		requires passwordless sudo access
PYTEST_BROKEN_TESTS=	test_dump_version_mypy
PYTEST_IGNORED_TESTS=	test_not_owner

post-patch:
	@${REINPLACE_CMD} -e '569,593s|"gpg|"gpg2|' ${WRKSRC}/testing/test_git.py

.include <bsd.port.mk>
