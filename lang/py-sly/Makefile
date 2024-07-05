PORTNAME=	sly
PORTVERSION=	0.5
CATEGORIES=	lang python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sly-${PORTVERSION}

MAINTAINER=	aishapoval@mts.ru
COMMENT=	Additional Python argparse types and actionsPython implementation of the lex & yacc tools for parsing & compiling
WWW=		https://pypi.org/project/sly/

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.9-3.11 shebangfix
USE_PYTHON=	autoplist concurrent cython pep517
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
