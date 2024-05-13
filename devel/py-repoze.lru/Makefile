PORTNAME=	repoze.lru
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny LRU cache implementation and decorator
WWW=		https://github.com/repoze/repoze.lru

LICENSE=	REPOZE
LICENSE_NAME=	Repoze Public License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
