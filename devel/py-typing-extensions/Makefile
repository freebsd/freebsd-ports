PORTNAME=	typing-extensions
PORTVERSION=	4.6.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	typing_extensions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backported and Experimental Type Hints for Python 3.5+
WWW=		https://github.com/python/typing_extensions

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	allflavors autoplist concurrent pep517

NO_ARCH=	yes

# The workaround (e7a9ba1fecd9209fbb4b669ccb283cb1862c4a2a) should be reverted after Python 3.7 EOL
PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel
PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.4<4:devel/py-flit-core@${PY_FLAVOR}

.include <bsd.port.mk>
