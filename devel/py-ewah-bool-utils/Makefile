PORTNAME=	ewah-bool-utils
DISTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	EWAH Bool Array utils for yt
WWW=		https://github.com/yt-project/ewah_bool_utils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.37.1:devel/py-wheel@${PY_FLAVOR} \
		${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist cython3 pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} # tests fail to run, see https://github.com/yt-project/ewah_bool_utils/issues/41
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/ewah_bool_utils/_testing${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/ewah_bool_utils/ewah_bool_wrap${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/ewah_bool_utils/morton_utils${PYTHON_TAG}.so

.include <bsd.port.mk>
