PORTNAME=	setuptools_scm
PORTVERSION=	7.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	7

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Setuptools plugin to manage your versions by scm tags
WWW=		https://pypi.org/project/setuptools-scm/ \
		https://github.com/pypa/setuptools_scm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
		git:devel/git \
		${PY_MERCURIAL}	\
		gpg:security/gnupg

USES=		python
USE_PYTHON=	autoplist pep517 pytest

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}-${PORTNAME}

NO_ARCH=	yes

TEST_ENV+=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

# Optional tests that depend on `dir` (windows) and `hg_git` (no longer in ports) will be skipped

# test_case_mismatch_on_windows_git  we're not on windows...
# test_on_old_setuptools             devel/py-setuptools is newer than the versions tested here
# test_not_owner                     requires passwordless sudo access
PYTEST_IGNORED_TESTS=	test_case_mismatch_on_windows_git \
			test_on_old_setuptools \
			test_not_owner

# https://github.com/pypa/setuptools_scm/issues/449
PYTEST_BROKEN_TESTS=	test_non_dotted_version

.include <bsd.port.mk>
