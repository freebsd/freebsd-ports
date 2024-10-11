PORTNAME=	sgqlc
DISTVERSION=	16.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple GraphQL Client
WWW=		https://github.com/profusion/sgqlc

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}graphql-core>=3.2.4:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
