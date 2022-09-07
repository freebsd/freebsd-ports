PORTNAME=	openapi-core
PORTVERSION=	0.14.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client-side and server-side support for the OpenAPI Specification v3
WWW=		https://github.com/p1c2u/openapi-core

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy-object-proxy>=0:devel/py-lazy-object-proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-schema-validator02>=0<0.3.0:devel/py-openapi-schema-validator02@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-spec-validator04>=0<0.5.0:devel/py-openapi-spec-validator04@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse>=0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathable>=0:devel/py-pathable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
