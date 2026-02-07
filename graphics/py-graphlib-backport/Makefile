PORTNAME=	graphlib-backport
PORTVERSION=	1.1.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	graphlib_backport-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backport of the Python 3.9 graphlib module for Python 3.6+
WWW=		https://github.com/mariushelf/graphlib_backport

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
