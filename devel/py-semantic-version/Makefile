PORTNAME=	semantic-version
PORTVERSION=	2.10.0
MASTER_SITES=	PYPI
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	semantic_version-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library provides a few tools to handle SemVer in Python
WWW=		https://github.com/rbarrois/python-semanticversion

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.1:www/py-django32@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils nose2

NO_ARCH=	yes

.include <bsd.port.mk>
