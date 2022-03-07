# Created by: Fukang Chen <loader@FreeBSD.org>

PORTNAME=	semantic-version
PORTVERSION=	2.9.0
MASTER_SITES=	CHEESESHOP
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	semantic_version-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python library provides a few tools to handle SemVer in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.1:www/py-django22@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py test

.include <bsd.port.mk>
