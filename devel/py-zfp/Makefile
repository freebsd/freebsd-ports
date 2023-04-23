PORTNAME=	zfp
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel science
MASTER_SITES=	https://github.com/LLNL/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High throughput library for compressed floating-point arrays
WWW=		https://computing.llnl.gov/projects/zfp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/scikit-build-cmake/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libzfp.so:devel/zfp
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake localbase:ldflags python
USE_PYTHON=	cython flavors

WRKSRC_SUBDIR=	python

PLIST_FILES=	${PYTHON_SITELIBDIR}/zfpy${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
