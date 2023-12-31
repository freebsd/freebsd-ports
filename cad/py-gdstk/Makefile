PORTNAME=	gdstk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.49
CATEGORIES=	cad
#MASTER_SITES=	PYPI # build fails from PYPI: https://github.com/heitzmann/gdspy/issues/236
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for creation and manipulation of GDSII and OASIS files
WWW=		https://heitzmann.github.io/gdstk/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYNUMPY}
LIB_DEPENDS=	libqhull_r.so:math/qhull

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 autoplist pytest # tests fail to run, see https://github.com/heitzmann/gdspy/issues/237

USE_GITHUB=	yes
GH_ACCOUNT=	heitzmann

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/gdstk/gdstk${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
