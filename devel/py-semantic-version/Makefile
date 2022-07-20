PORTNAME=	semantic-version
PORTVERSION=	2.10.0
MASTER_SITES=	CHEESESHOP
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	semantic_version-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library provides a few tools to handle SemVer in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.1:www/py-django32@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils nose2

NO_ARCH=	yes

.include <bsd.port.mk>
