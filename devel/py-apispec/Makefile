PORTNAME=	apispec
DISTVERSION=	6.8.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Pluggable API specification generator
WWW=		https://github.com/marshmallow-code/apispec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit>0:devel/py-flit@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prance>0:devel/py-prance@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>0:devel/py-openapi-spec-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prance>=0.11:devel/py-prance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
