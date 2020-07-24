# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphene-django
PORTVERSION=	2.12.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Graphene Django integration

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphene>=2.1.7<3:devel/py-graphene@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core2>=2.1.0<3:devel/py-graphql-core2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}promise>=2.1:devel/py-promise@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	REST_FRAMEWORK
OPTIONS_DEFAULT=REST_FRAMEWORK
REST_FRAMEWORK_DESC=	REST framework support

REST_FRAMEWORK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.6.3:www/py-djangorestframework@${PY_FLAVOR}

.include <bsd.port.mk>
