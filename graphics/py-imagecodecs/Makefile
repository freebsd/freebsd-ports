PORTNAME=	imagecodecs
PORTVERSION=	2024.6.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Image transformation, compression, and decompression codecs
WWW=		https://github.com/cgohlke/imagecodecs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython3>=3.0:lang/cython3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libdeflate.so:archivers/libdeflate \
		libjbig.so:graphics/jbigkit\
		libjpegxr.so:graphics/libjxr \
		liblcms2.so:graphics/lcms2 \
		libLerc.so:graphics/lerc \
		liblz4.so:archivers/liblz4 \
		libopenjp2.so:graphics/openjpeg \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		jpeg localbase python:3.9+
USE_PYTHON=	autoplist concurrent pep517

CPPFLAGS+=	-I${LOCALBASE}/include/jxrlib -I${LOCALBASE}/include/openjpeg-2.5

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
