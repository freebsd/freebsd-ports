PORTNAME=	fugashi
DISTVERSION=	1.3.2
CATEGORIES=	japanese python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython MeCab wrapper for fast, pythonic Japanese tokenization
WWW=		https://github.com/polm/fugashi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libmecab.so:japanese/mecab

USES=		python
USE_PYTHON=	distutils cython autoplist # tests depend on ipadic

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/fugashi/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fugashi/fugashi${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
