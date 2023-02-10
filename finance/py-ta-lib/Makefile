PORTNAME=	ta-lib
PORTVERSION=	0.4.25
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TA-Lib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python wrapper for TA-Lib (Technical Analysis Library)
WWW=		https://mrjbq7.github.io/ta-lib/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libta_lib.so:devel/ta-lib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		localbase python:3.7+
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
