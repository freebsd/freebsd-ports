PORTNAME=	tifffile
PORTVERSION=	2025.6.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI \
		https://github.com/cgohlke/tifffile/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read and write TIFF(r) files
WWW=		https://github.com/cgohlke/tifffile

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		dos2unix python:3.11+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CODECS PLOT XML # ZARR
CODECS_DESC=	Codec for compression and predictor schemes
PLOT_DESC=	Plotting support
XML_DESC=	Validate and print XML
ZARR_DESC=	Access zarr store

CODECS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imagecodecs>=2024.12.30:graphics/py-imagecodecs@${PY_FLAVOR}
PLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}
XML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR}
ZARR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>=0:filesystems/py-fsspec@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}kerchunk>=0:filesystems/py-kerchunk@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zarr>=3:devel/py-zarr@${PY_FLAVOR}

.include <bsd.port.mk>
