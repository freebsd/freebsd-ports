PORTNAME=	fitsio
PORTVERSION=	1.2.4
CATEGORIES=	astro python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full featured python library to read from and write to FITS files
WWW=		https://github.com/esheldon/fitsio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	FITSIO_USE_SYSTEM_FITSIO=yes \
		FITSIO_SYSTEM_FITSIO_INCLUDEDIR=${LOCALBASE}/include \
		FITSIO_SYSTEM_FITSIO_LIBDIR=${LOCALBASE}/lib

# Clean up bundled libraries
post-patch:
	@${RM} -r ${WRKSRC}/cfitsio-*/
	@${RM} -r ${WRKSRC}/zlib/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
