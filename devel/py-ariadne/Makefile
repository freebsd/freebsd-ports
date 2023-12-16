PORTNAME=	ariadne
PORTVERSION=	0.21
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python library for implementing GraphQL servers
WWW=		https://ariadnegraphql.org \
		https://github.com/mirumee/ariadne

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphql-core>=3.2.0:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0.17:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
