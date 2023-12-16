PORTNAME=	mashumaro
PORTVERSION=	3.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Fast serialization library on top of dataclasses
WWW=		https://github.com/Fatal1ty/mashumaro

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
