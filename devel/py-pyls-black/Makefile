PORTNAME=	pyls-black
PORTVERSION=	0.4.7
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Black plugin for the Python Language Server
WWW=		https://github.com/rupert/pyls-black

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR}

# No tests because they are not in the release tarball
USES=		python:3.6+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
