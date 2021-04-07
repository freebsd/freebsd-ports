PORTNAME=	ta-lib
DISTVERSIONPREFIX=	TA_Lib-
DISTVERSION=	0.4.17
PORTREVISION=	1
CATEGORIES=	finance python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Python wrapper for ta-lib (tools for market analysis)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libta_lib.so:devel/ta-lib
RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.6+

MAKE_ENV=	TA_INCLUDE_PATH="${LOCALBASE}/include"

USE_GITHUB=	yes
GH_ACCOUNT=	mrjbq7
USE_PYTHON=	distutils cython autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/talib/_ta_lib*.so

.include <bsd.port.mk>
