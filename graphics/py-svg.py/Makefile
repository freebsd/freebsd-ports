PORTNAME=	svg_py
DISTVERSION=	1.10.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Type-safe SVG drawing library for Python
WWW=		https://github.com/orsinium-labs/svg.py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=2:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
