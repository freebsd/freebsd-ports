PORTNAME=	oslotest
DISTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Oslo test framework
WWW=		https://docs.openstack.org/oslotest/latest/ \
		https://github.com/openstack/oslotest

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pbr>=6.1.1:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fixtures>=3.0.0:devel/py-fixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-subunit>=1.0.0:devel/py-python-subunit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=2.2.0:devel/py-testtools@${PY_FLAVOR} \
		bash>0:shells/bash

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest
SHEBANG_FILES=	tools/oslo_debug_helper

NO_ARCH=	yes

.include <bsd.port.mk>
