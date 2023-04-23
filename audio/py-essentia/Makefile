PORTNAME=	essentia
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1_beta5-859
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gb247091f
CATEGORIES=	audio
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for essentia, C++ library for audio and music analysis
WWW=		https://essentia.upf.edu/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libessentia.so:audio/essentia
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		eigen:3 pkgconfig python
USE_PYTHON=	pytest

USE_GITHUB=	yes
GH_ACCOUNT=	MTG

do-configure:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${BUILD_ENV} ${PYTHON_CMD} waf configure --only-python

do-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${BUILD_ENV} ${PYTHON_CMD} waf build --only-python

do-install:
	# install
	cd ${BUILD_WRKSRC} && ${SETENV} ${BUILD_ENV} ${PYTHON_CMD} waf install --only-python --prefix ${PREFIX} --destdir ${STAGEDIR}
	# strip
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/essentia/_essentia${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
