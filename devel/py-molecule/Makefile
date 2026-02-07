PORTNAME=	molecule
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Aid for the development and testing of Ansible roles
WWW=		https://molecule.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=19.3.1:devel/py-pip@${PY_FLAVOR} \
	${PY_SETUPTOOLS} \
	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7.0.0:devel/py-setuptools-scm@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}wheel>=0.33.6:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansi2html>=1.8.0:textproc/py-ansi2html@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ansible-compat>=2.2.1:sysutils/py-ansible-compat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-help-colors>=0.9:devel/py-click-help-colors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cookiecutter>=1.7.3:devel/py-cookiecutter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enrich>=1.2.7:textproc/py-enrich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.9.1:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=0.7.1:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=9.5.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}
# ansi2html >= 1.6.0
# pytest-cov >= 2.10.1
# pytest-testinfra >= 6.1.0
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=6.2:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=4.8.0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.9.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-html>=3.0.0:devel/py-pytest-html@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.3.1:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-plus>=0.2:devel/py-pytest-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=2.1.0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

# Note: we're only running the unit tests here.  Upstream acknowledges
# that functional tests are still a work in progress.
#
# Test failures. Only three tests fail:
#  test/unit/test_util.py ......FFF.......................   [ 23%]
#
# The click module demands a UTF-8 locale when used with python-3.x
TEST_ENV=	LANG=en_US.UTF-8 \
		LC_ALL=en_US.UTF-8

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCKER DOCS LINT
OPTIONS_DEFAULT=	LINT
DOCKER_DESC=		For testing on Docker Platform(Remote)
LINT_DESC=		For linting molecule itself
DOCKER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docker>=2.0.0:sysutils/py-docker@${PY_FLAVOR}
# sphinx-ansible-theme >= 0.8.0, < 0.10.0
# sphinx-notfound-page >= 0.7.1
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.3:devel/py-Jinja2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ansible-core>=2.12.0:sysutils/py-ansible-core@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}simplejson>=3.17.2:devel/py-simplejson@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=5.0.0:textproc/py-sphinx@${PY_FLAVOR}
LINT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=3.8.4:devel/py-flake8@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pre-commit>=2.10.1:devel/py-pre-commit@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}yamllint>0:devel/py-yamllint@${PY_FLAVOR}

.include <bsd.port.mk>
