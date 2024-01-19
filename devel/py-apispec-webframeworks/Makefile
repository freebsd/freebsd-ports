PORTNAME=	apispec-webframeworks
DISTVERSION=	1.0.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web framework plugins for apispec
WWW=		https://github.com/marshmallow-code/apispec-webframeworks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apispec>0:devel/py-apispec@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottle>=0.12.25:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=2.3.3:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6:www/py-tornado@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

USE_GITHUB=	yes
GH_ACCOUNT=	marshmallow-code

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
