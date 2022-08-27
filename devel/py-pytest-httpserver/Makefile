PORTNAME=	pytest-httpserver
PORTVERSION=	1.0.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_httpserver-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP server for pytest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>=2.0.0:www/py-werkzeug@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
