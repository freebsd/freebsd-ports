PORTNAME=	semantic-version
PORTVERSION=	2.10.0
PORTREVISION=	1
MASTER_SITES=	PYPI
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	semantic_version-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library provides a few tools to handle SemVer in Python
WWW=		https://github.com/rbarrois/python-semanticversion

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=1.1:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent nose2 pep517

NO_ARCH=	yes

.include <bsd.port.mk>
