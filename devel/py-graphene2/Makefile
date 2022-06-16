# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	graphene
PORTVERSION=	2.1.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphQL Framework for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aniso86016>=3<7:devel/py-aniso86016@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core2>=2.1<3:devel/py-graphql-core2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-relay2>=2<3:devel/py-graphql-relay2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0<2:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}graphene

PORTSCOUT=	limmit:^2\.

.include <bsd.port.mk>
