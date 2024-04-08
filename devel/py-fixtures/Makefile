PORTNAME=	fixtures
PORTVERSION=	4.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fixtures, reusable state for writing clean tests and more
WWW=		https://github.com/testing-cabal/fixtures

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/Apache-2.0
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=5.7.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=36.6.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=5.7.0:devel/py-pbr@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
