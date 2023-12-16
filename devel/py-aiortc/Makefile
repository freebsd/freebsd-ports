PORTNAME=	aiortc
PORTVERSION=	1.6.0
CATEGORIES=	devel multimedia python www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	WebRTC and ORTC in Python
WWW=		https://github.com/aiortc/aiortc/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libopus.so:audio/opus \
		libvpx.so:multimedia/libvpx
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}aioice>=0.9.0:devel/py-aioice@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}av>=9.0.0:multimedia/py-av@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-crc32c>=1.1:devel/py-google-crc32c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=23.1.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyee>=9.0.0:devel/py-pyee@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylibsrtp>=0.5.6:devel/py-pylibsrtp@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent cryptography distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/codecs/*.so

.include <bsd.port.mk>
