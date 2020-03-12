# $FreeBSD$

PORTNAME=	apispec
PORTVERSION=	3.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Pluggable API specification generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.10:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow>0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

# tests_require = prance[osv]>=0.11
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}prance>=0.11:devel/py-prance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>0:devel/py-openapi-spec-validator@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
