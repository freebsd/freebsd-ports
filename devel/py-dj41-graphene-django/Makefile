PORTNAME=	graphene-django
PORTVERSION=	3.0.0
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj41-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Graphene Django integration
WWW=		https://github.com/graphql-python/graphene-django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=3.2:www/py-django41@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene>=3.0<4:devel/py-graphene@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core>=3.1.0<4:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-relay>=3.1.1<4:devel/py-graphql-relay@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}promise>=2.1:devel/py-promise@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=0:converters/py-text-unidecode@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	REST_FRAMEWORK
OPTIONS_DEFAULT=REST_FRAMEWORK
REST_FRAMEWORK_DESC=	REST framework support

REST_FRAMEWORK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj41-djangorestframework>=3.6.3:www/py-dj41-djangorestframework@${PY_FLAVOR}

.include <bsd.port.mk>
