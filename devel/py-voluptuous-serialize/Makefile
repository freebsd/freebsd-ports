PORTNAME=	voluptuous-serialize
DISTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Convert voluptuous schemas to JSON
WWW=		https://github.com/home-assistant-libs/voluptuous-serialize

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}voluptuous>=0:devel/py-voluptuous@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
