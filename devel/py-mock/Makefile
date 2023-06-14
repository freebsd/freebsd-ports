PORTNAME=	mock
PORTVERSION=	5.0.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Rolling backport of unittest.mock for all Pythons
WWW=		https://mock.readthedocs.org/en/latest/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_GITHUB=	yes # tests not packages in PyPI sdist
GH_ACCOUNT=	testing-cabal
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
