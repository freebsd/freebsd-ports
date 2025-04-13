PORTNAME=	coreschema
DISTVERSION=	0.0.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Core schema for the Core API
WWW=		https://github.com/core-api/python-coreschema

LICENSE=	BSD2CLAUSE

DEPRECATED=	Upstream archived the repository. Please use devel/py-openapi-schema-validator instead
EXPIRATION_DATE=2025-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
