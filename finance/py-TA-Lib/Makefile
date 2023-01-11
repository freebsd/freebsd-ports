PORTNAME=	TA-Lib # provides Python namespace 'talib'
DISTVERSION=	0.4.25
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for TA-LIB based on Cython
WWW=		https://mrjbq7.github.io/ta-lib/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libta_lib.so:devel/ta-lib
RUN_DEPENDS=	${PYNUMPY}
#TEST_DEPENDS=	misc/py-polars - fails to build, see https://github.com/rust-lang/hashbrown/issues/377

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/talib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/talib/_ta_lib${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
