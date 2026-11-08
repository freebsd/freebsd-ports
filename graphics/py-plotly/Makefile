PORTNAME=	plotly
DISTVERSION=	7.1.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Library for collaborative, interactive, publication-quality graphs
WWW=		https://plotly.com/python/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.26:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}narwhals>=1.15.1:math/py-narwhals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

USES+=		shebangfix
SHEBANG_FILES=	${WRKSRC}/_plotly_utils/png.py

.include <bsd.port.mk>
