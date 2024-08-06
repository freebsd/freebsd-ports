PORTNAME=	commentjson
PORTVERSION=	0.9.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Create JSON files with Python and JavaScript style inline comments
WWW=		https://pypi.org/project/commentjson/

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lark-parser>=0.7.1,<0.8.0:lang/py-lark-parser@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
