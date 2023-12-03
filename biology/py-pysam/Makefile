PORTNAME=	pysam
DISTVERSION=	0.22.0
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading, manipulating and writing genomic data sets
WWW=		https://github.com/pysam-developers/pysam

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhts.so:biology/htslib

USES=		gmake python
USE_PYTHON=	distutils autoplist cython cython_run

BINARY_ALIAS=	make=${GMAKE}
MAKE_ENV=	HTSLIB_MODE=external \
		HTSLIB_LIBRARY_DIR=${LOCALBASE}/lib \
		HTSLIB_INCLUDE_DIR=${LOCALBASE}/include

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysam/lib*${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
