PORTNAME=	zfp
DISTVERSION=	1.0.1
CATEGORIES=	devel science
MASTER_SITES=	https://github.com/LLNL/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High throughput library for compressed floating-point arrays
WWW=		https://computing.llnl.gov/projects/zfp \
		https://github.com/LLNL/zfp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/scikit-build-cmake/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libzfp.so:devel/zfp
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake localbase:ldflags python
USE_PYTHON=	cython flavors pytest

WRKSRC_SUBDIR=	python

TEST_WRKSRC=	${WRKSRC}/../tests/python
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

PLIST_FILES=	${PYTHON_SITELIBDIR}/zfpy${PYTHON_TAG}.so

# tests fail to run, see https://github.com/LLNL/zfp/issues/251

.include <bsd.port.mk>
