PORTNAME=	essentia
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1_beta5-859
DISTVERSIONSUFFIX=	-gb247091f
PORTREVISION=	5
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
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

MASTER_SITES=	https://raw.githubusercontent.com/MTG/essentia/d02b6c752046802a711530e2bcd5feafca42247d/
DISTFILES=	waf
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}*.gz

USES=		eigen:3 pkgconfig python
USE_PYTHON=	pytest

USE_GITHUB=	yes
GH_ACCOUNT=	MTG

post-extract:
	@${CP} ${DISTDIR}/waf ${WRKSRC}/

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
