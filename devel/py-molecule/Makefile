PORTNAME=	molecule
PORTVERSION=	2.22
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Aid for the development and testing of Ansible roles

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>=1.0:devel/py-setuptools_scm_git_archive@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}ansible>=2.5:sysutils/ansible@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ansible-lint>=4.0.2:sysutils/py-ansible-lint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Cerberus>=1.3.1:devel/py-cerberus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anyconfig>=0.9.7:devel/py-anyconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-completion>=0.3.1:devel/py-click-completion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cookiecutter>=1.6.0:devel/py-cookiecutter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3.6.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.5.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>=4.6.0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>=1.17.0:devel/py-pre-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.4.6:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gilt>=1.2.1:devel/py-python-gilt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sh>=1.12.14:devel/py-sh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.8.3:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testinfra>=3.0.6:devel/py-testinfra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-format>=0.1.2:devel/py-tree-format@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yamllint>=1.15.0:devel/py-yamllint@${PY_FLAVOR}
# TEST requires pytest >=4.6.3. Will change once updated
TEST_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}flake8>=3.6.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=3.0.5:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=4.5.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.7.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-helpers-namespace>=2019.1.8:devel/py-pytest-helpers-namespace@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=1.10.4:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-verbose-parametrize>=1.7.0:devel/py-pytest-verbose-parametrize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.29.0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AZURE DOCKER DOCS EC2 GCE
AZURE_DESC=	For testing on Microsoft Azure Platform
DOCKER_DESC=	For testing on Docker Platform(Remote)
EC2_DESC=	For testing on Amazon EC2 Platform
GCE_DESC=	For testing on Google Compute Engine Platform
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alabaster>0:textproc/py-alabaster@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
AZURE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-cli>0:sysutils/py-azure-cli@${PY_FLAVOR}
DOCKER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docker>=2.0.0:sysutils/py-docker@${PY_FLAVOR}
EC2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR}
GCE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcloud>0:net/py-libcloud@${PY_FLAVOR}
# Note: we're only running the unit tests here.  Upstream acknowledges
# that functional tests are still a work in progress.
#
# Test failures. Only three tests fail:
#  test/unit/test_util.py ......FFF.......................   [ 23%]
#
# The click module demands a UTF-8 locale when used with python-3.x
TEST_ENV=	LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
