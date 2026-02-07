PORTNAME=	typing-extensions
PORTVERSION=	4.15.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	typing_extensions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Backported and Experimental Type Hints for Python 3.5+
WWW=		https://github.com/python/typing_extensions

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
