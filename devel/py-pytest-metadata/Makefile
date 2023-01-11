PORTNAME=	pytest-metadata
PORTVERSION=	2.0.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Pytest plugin for test session metadata
WWW=		https://github.com/pytest-dev/pytest-metadata

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.0.0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
