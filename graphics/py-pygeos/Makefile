# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pygeos
PORTVERSION=	0.12.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GEOS wrapped in numpy ufuncs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	geos>=3.5:graphics/geos \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13,1:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libgeos.so:graphics/geos
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.13,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
