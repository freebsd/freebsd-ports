PORTNAME=	imagecodecs
PORTVERSION=	2024.12.30
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Image transformation, compression, and decompression codecs
WWW=		https://github.com/cgohlke/imagecodecs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libaec.so:science/libaec \
		libavif.so:graphics/libavif \
		libblosc.so:archivers/c-blosc \
		libblosc2.so:archivers/c-blosc2 \
		libbrotlicommon.so:archivers/brotli \
		libbrunslidec-c.so:graphics/brunsli \
		libcharls.so:graphics/charls \
		libdeflate.so:archivers/libdeflate \
		libgif.so:graphics/giflib \
		libheif.so:graphics/libheif \
		libjbig.so:graphics/jbigkit\
		libjpegxr.so:graphics/libjxr \
		libjxl.so:graphics/libjxl \
		liblcms2.so:graphics/lcms2 \
		libLerc.so:graphics/lerc \
		liblz4.so:archivers/liblz4 \
		liblzfse.so:archivers/lzfse \
		libopenjp2.so:graphics/openjpeg \
		libpng16.so:graphics/png \
		libsnappy.so:archivers/snappy \
		libSZ3c.so:science/sz3 \
		libtiff.so:graphics/tiff \
		libuhdr.so:graphics/libultrahdr \
		libwebp.so:graphics/webp \
		libz-ng.so:archivers/zlib-ng \
		libzfp.so:devel/zfp \
		libzopfli.so:archivers/zopfli \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		jpeg localbase python:3.9+
USE_PYTHON=	autoplist concurrent cython3 pep517

CPPFLAGS+=	-I${LOCALBASE}/include/jxrlib \
		-I${LOCALBASE}/include/openjpeg-2.5

OPTIONS_DEFINE=	ALL
ALL_DESC=	All optional dependencies

# Remove graphics/py-tifffile from RUN_DEPENDS to avoid cyclic dependency
ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numcodecs>=0:misc/py-numcodecs@${PY_FLAVOR}
#			${PYTHON_PKGNAMEPREFIX}tifffile>=0:graphics/py-tifffile@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
