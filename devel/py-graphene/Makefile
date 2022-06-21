# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	graphene
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphQL Framework for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aniso8601>=8<10:devel/py-aniso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core>=3.1<3.3:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-relay>=3.1<3.3:devel/py-graphql-relay@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}graphene2

.include <bsd.port.mk>
