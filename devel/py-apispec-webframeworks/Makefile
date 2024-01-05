PORTNAME=	apispec-webframeworks
DISTVERSION=	0.5.2
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web framework plugins for apispec
WWW=		https://github.com/marshmallow-code/apispec-webframeworks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apispec>0:devel/py-apispec@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent pytest

USE_GITHUB=	yes
GH_ACCOUNT=	marshmallow-code

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
