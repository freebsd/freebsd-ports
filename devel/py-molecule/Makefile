# $FreeBSD$

PORTNAME=	molecule
PORTVERSION=	2.19.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Aid for the development and testing of Ansible roles

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible-lint>=3.4.23:sysutils/py-ansible-lint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anyconfig>=0.9.7:devel/py-anyconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Cerberus>=1.2:devel/py-cerberus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click-completion>=0.3.1:devel/py-click-completion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cookiecutter>=1.6.0:devel/py-cookiecutter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3.5.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gilt>=1.2.1:devel/py-python-gilt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.13:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sh>=1.12.14:devel/py-sh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0.8.2:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testinfra>=1.16.0:devel/py-testinfra@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-format>=0.1.2:devel/py-tree-format@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yamllint>=1.11.1:devel/py-yamllint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.0.7:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-helpers-namespace>0:devel/py-pytest-helpers-namespace@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# Note: we're only running the unit tests here.  Upstream acknowledges
# that functional tests are still a work in progress.
#
# Test failures. Only three tests fail:
#  test/unit/test_util.py ......FFF.......................   [ 23%]
#
# The click module demands a UTF-8 locale when used with python-3.x
TEST_ENV=	LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing>=0:devel/py-typing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}functools32>=0:devel/py-functools32@${PY_FLAVOR}
.endif

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.post.mk>
