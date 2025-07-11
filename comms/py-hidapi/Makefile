PORTNAME=	hidapi
PORTVERSION=	0.14.0
DISTVERSIONSUFFIX=	.post4
PORTREVISION=	1
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cython interface to the hidapi
WWW=		https://github.com/trezor/cython-hidapi

LICENSE=	BSD3CLAUSE GPLv3 PD
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE-bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-gpl3.txt
LICENSE_FILE_PD=	${WRKSRC}/LICENSE-orig.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		pkgconfig python
USE_PYTHON=	autoplist concurrent cython pep517 unittest

MAKE_ENV=	HIDAPI_SYSTEM_HIDAPI=1 \
		HIDAPI_WITH_LIBUSB=1

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/hidapi/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
