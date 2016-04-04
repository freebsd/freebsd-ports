# $FreeBSD$

PORTNAME=	Pyrseas
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arcade@b1t.name
COMMENT=	Framework and utilities to upgrade and maintain a relational database

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.2:databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.09:devel/py-yaml
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	perseas

# Requires a running PostgreSQL instance

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
