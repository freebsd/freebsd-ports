# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	graphene-django
PORTVERSION=	2.15.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Graphene Django integration

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.11:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene2>=2.1.7<3:devel/py-graphene2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core2>=2.1.0<3:devel/py-graphql-core2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}promise>=2.1:devel/py-promise@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}text-unidecode>=0:converters/py-text-unidecode@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

OPTIONS_DEFINE=	REST_FRAMEWORK
OPTIONS_DEFAULT=REST_FRAMEWORK
REST_FRAMEWORK_DESC=	REST framework support

REST_FRAMEWORK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.6.3:www/py-djangorestframework@${PY_FLAVOR}

.include <bsd.port.mk>
