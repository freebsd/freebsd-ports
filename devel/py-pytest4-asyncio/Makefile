PORTNAME=	pytest4-asyncio
PORTVERSION=	0.10.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/4//}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Py.test plugin providing fixtures and markers for asyncio (legacy version for pytest 4)
WWW=		https://pypi.org/project/pytest-asyncio/

LICENSE=	APACHE20

DEPRECATED=	legacy version for pytest4 no longer used by any port
EXPIRATION_DATE=2022-11-19

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest4>=3.0.6:devel/py-pytest4@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.5+
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	${PORTNAME:C/4//}

.include <bsd.port.mk>
