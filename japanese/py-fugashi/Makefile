PORTNAME=	fugashi
DISTVERSION=	1.4.0
PORTREVISION=	1
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
RUN_DEPENDS=	ja-mecab-ipadic>0:japanese/mecab-ipadic
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipadic>0:japanese/py-ipadic@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython3 distutils pytest # many tests fail, see https://github.com/polm/fugashi/issues/102

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/fugashi/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fugashi/fugashi${PYTHON_TAG}.so

.include <bsd.port.mk>
