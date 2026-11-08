PORTNAME=	testscenarios
PORTVERSION=	0.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PyUnit extension for dependency injection
WWW=		https://github.com/testing-cabal/testscenarios

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/Apache-2.0
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent pep517

USES=		python

.include <bsd.port.mk>
