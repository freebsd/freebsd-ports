PORTNAME=	graphql-core
PORTVERSION=	3.2.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GraphQL implementation for Python
WWW=		https://github.com/graphql-python/graphql-core-next

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.2<5:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
