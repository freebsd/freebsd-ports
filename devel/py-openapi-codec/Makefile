PORTNAME=	openapi-codec
DISTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	OpenAPI codec for Core API
WWW=		https://github.com/core-api/python-openapi-codec

LICENSE=	BSD2CLAUSE

DEPRECATED=	Upstream archived the repository. Please use devel/py-openapi-core instead
EXPIRATION_DATE=2025-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coreapi>0:devel/py-coreapi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
