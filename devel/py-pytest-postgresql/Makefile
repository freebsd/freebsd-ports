PORTNAME=	pytest-postgresql
PORTVERSION=	8.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_postgresql-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Postgresql fixtures and fixture factories for Pytest
WWW=		https://github.com/dbfixtures/pytest-postgresql

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.lesser

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mirakuru>=2.6.0:devel/py-mirakuru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}port-for>=0.4:net/py-port-for@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.0.0:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8.2,1:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
