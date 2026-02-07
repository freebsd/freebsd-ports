PORTNAME=	pytest-cases
PORTVERSION=	3.9.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_cases-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Separate test code from test cases in pytest
WWW=		https://smarie.github.io/python-pytest-cases/ \
		https://github.com/smarie/python-pytest-cases

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=39.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decopatch>=0:devel/py-decopatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}makefun>=1.15.1:devel/py-makefun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
