PORTNAME=	graphene
PORTVERSION=	2.1.9
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphQL Framework for Python
WWW=		https://github.com/graphql-python/graphene

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aniso86016>=3<7:devel/py-aniso86016@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core2>=2.1<3:devel/py-graphql-core2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-relay2>=2<3:devel/py-graphql-relay2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0<2:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}graphene

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
