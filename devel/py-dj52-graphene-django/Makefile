PORTNAME=	graphene-django
DISTVERSION=	3.2.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-

MAINTAINER=	siva@FreeBSD.org
COMMENT=	Graphene Django integration
WWW=		https://docs.graphene-python.org/projects/django/en/latest/ \
		https://github.com/graphql-python/graphene-django

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=3.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene>=3.0<4:devel/py-graphene@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core>=3.1.0<4:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-relay>=3.1.1<4:devel/py-graphql-relay@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}promise>=2.1:devel/py-promise@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=0:converters/py-text-unidecode@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

OPTIONS_DEFINE=	REST_FRAMEWORK
OPTIONS_DEFAULT=REST_FRAMEWORK
REST_FRAMEWORK_DESC=	REST framework support

REST_FRAMEWORK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj52-djangorestframework>0:www/py-dj52-djangorestframework@${PY_FLAVOR}

.include <bsd.port.mk>
