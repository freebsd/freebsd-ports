# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphql-relay
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Relay implementation for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphql-core>=2.2<3:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}promise>=2.2<3:devel/py-promise@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
