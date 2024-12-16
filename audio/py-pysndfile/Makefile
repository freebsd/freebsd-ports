PORTNAME=	pysndfile
DISTVERSION=	1.4.6
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython wrapper class for reading/writing soundfiles using libsndfile
WWW=		https://forge-2.ircam.fr/roebel/pysndfile

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
LIB_DEPENDS=	libsndfile.so:audio/libsndfile
RUN_DEPENDS=	${PYNUMPY}

USES=		python localbase
USE_PYTHON=	distutils autoplist cython pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests fail: ModuleNotFoundError: No module named 'pysndfile_inst_dir'; reported to the author via-e-mail on 2024-12-15

.include <bsd.port.mk>
