PORTNAME=	setuptools-scm
PORTVERSION=	8.0.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Setuptools plugin to manage your versions by scm tags
WWW=		https://github.com/pypa/setuptools_scm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20:devel/py-packaging@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		git:devel/git \
		${PY_MERCURIAL} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR} \
		gpg2:security/gnupg \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>0:devel/py-setuptools_scm_git_archive@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

# test_git_worktree_support		sometimes relative path results
# test_dump_version_on_old_python	python 3.7 not available
# test_not_owner			requires passwordless sudo access
# test_case_mismatch_on_windows_git	we're not on Windows
PYTEST_BROKEN_TESTS=	test_git_worktree_support
PYTEST_IGNORED_TESTS=	test_dump_version_on_old_python \
			test_not_owner \
			test_case_mismatch_on_windows_git

post-patch:
	@${REINPLACE_CMD} -e '497,521s|"gpg|"gpg2|' ${WRKSRC}/testing/test_git.py

.include <bsd.port.mk>
