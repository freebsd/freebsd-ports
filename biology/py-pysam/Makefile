PORTNAME=	pysam
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.0
PORTREVISION=	1
CATEGORIES=	biology python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading, manipulating and writing genomic data sets
WWW=		https://github.com/pysam-developers/pysam

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhts.so:biology/htslib
RUN_DEPENDS=	bcftools:biology/bcftools \
		samtools:biology/samtools

USES=		gmake python
USE_PYTHON=	distutils autoplist cython cython_run pytest # 2 failed, 155 errors, see https://github.com/pysam-developers/pysam/issues/1284

USE_GITHUB=	yes
GH_ACCOUNT=	pysam-developers

BINARY_ALIAS=	make=${GMAKE}
MAKE_ENV=	HTSLIB_MODE=external \
		HTSLIB_LIBRARY_DIR=${LOCALBASE}/lib \
		HTSLIB_INCLUDE_DIR=${LOCALBASE}/include
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysam/lib*${PYTHON_TAG}.so

# tests as of 0.23.0: 958 passed, 13 skipped, 1 warning in 502.60s (0:08:22)

.include <bsd.port.mk>
