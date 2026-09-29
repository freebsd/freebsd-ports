PORTNAME=	pydantic-resolve
PORTVERSION=	6.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pydantic_resolve-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Entity-first architecture framework for Python
WWW=		https://klr-pattern.github.io/pydantic-resolve/ \
		https://github.com/KLR-Pattern/pydantic-resolve

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodataloader>=0.4.0<0.5.0:databases/py-aiodataloader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core>=3.2<4.0:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0<3.0.0:devel/py-pydantic2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
