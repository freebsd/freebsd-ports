PORTNAME=	minimongo
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		http://files.derzinn.de/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@derzinn.de
COMMENT=	Minimal database Model management for MongoDB
WWW=		https://github.com/slacy/minimongo

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=1.9:databases/py-pymongo@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
