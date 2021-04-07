PORTNAME=	oslotest
DISTVERSION=	4.4.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Oslo test framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fixtures>=3.0.0:devel/py-fixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-subunit>=1.0.0:devel/py-python-subunit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=2.2.0:devel/py-testtools@${PY_FLAVOR} \
		bash>0:shells/bash

USES=		python:3.6+ shebangfix
USE_PYTHON=	distutils concurrent autoplist
SHEBANG_FILES=	tools/oslo_debug_helper \
		tools/oslo_run_cross_tests \
		tools/oslo_run_pre_release_tests

NO_ARCH=	yes

.include <bsd.port.mk>
