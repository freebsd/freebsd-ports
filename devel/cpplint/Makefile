PORTNAME=	cpplint
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	PYPI

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Static code checker for C++
WWW=		https://github.com/cpplint/cpplint

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS}	\
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	pylint:devel/pylint	\
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}testfixtures>0:devel/py-testfixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USES=		pytest python
USE_PYTHON=	noflavors pep517

NO_ARCH=	yes

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
