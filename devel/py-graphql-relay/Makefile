# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphql-relay
PORTVERSION=	3.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Relay implementation for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphql-core>=3.1:devel/py-graphql-core@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7<4:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
