PORTNAME=	openapi-core
PORTVERSION=	0.16.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client-side and server-side support for the OpenAPI Specification v3
WWW=		https://github.com/p1c2u/openapi-core

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-schema-validator>=0.3.0<0.4.0:devel/py-openapi-schema-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>=0.5.0<0.6.0:devel/py-openapi-spec-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parse>=0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathable>=0.4.0<0.5.0:devel/py-pathable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0<5.0.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0:www/py-werkzeug@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DJANGO FALCON FLASK REQUESTS
DJANGO_DESC=	Django support
FALCON_DESC=	Falcon support
FLASK_DESC=	Flask support
REQUESTS_DESC=	Requests support

DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=3.0:www/py-django32@${PY_FLAVOR}
FALCON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}falcon>=3.0:www/py-falcon@${PY_FLAVOR}
FLASK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
