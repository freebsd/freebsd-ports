PORTNAME=	pycrdt-store
PORTVERSION=	0.1.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pycrdt_store-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Persistent storage for pycrdt
WWW=		https://github.com/y-crdt/pycrdt-store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.6.2<5:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrdt>=0.12.13<0.13.0:devel/py-pycrdt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite-anyio>=0.2.3<0.3.0:databases/py-sqlite-anyio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
