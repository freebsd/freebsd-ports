# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	caterva
PORTVERSION=	0.7.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Caterva for Python (multidimensional compressed data containers)

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	caterva>=0.5.0_1:databases/caterva \
		cmake:devel/cmake \
		ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0:devel/py-scikit-build@${PY_FLAVOR}
LIB_DEPENDS=	libblosc2.so:archivers/c-blosc2 \
		libcaterva.so:databases/caterva
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ndindex>=0:math/py-ndindex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.20.3,1:math/py-numpy@${PY_FLAVOR}

USES=		localbase:ldflags python:3.7+
USE_PYTHON=	autoplist concurrent cython distutils

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/caterva/caterva/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
