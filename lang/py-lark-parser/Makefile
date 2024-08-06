PORTNAME=	lark-parser
PORTVERSION=	0.7.1
CATEGORIES=	lang python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	awoonyaa@gmail.com
COMMENT=	Parsing toolkit for Python, built with for ergonomics, performance etc
WWW=		https://pypi.org/project/lark-parser/

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
