PORTNAME=	ewah-bool-utils
DISTVERSION=	1.3.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	EWAH Bool Array utils for yt
WWW=		https://github.com/yt-project/ewah_bool_utils

LICENSE=	BSD2CLAUSE APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_APACHE20=	${WRKSRC}/src/ewah_bool_utils/cpp/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.18.0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.23.2:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist cython pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/ewah_bool_utils/_testing${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/ewah_bool_utils/ewah_bool_wrap${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/ewah_bool_utils/morton_utils${PYTHON_TAG}.so

# tests as of 1.3.2: 3 passed

.include <bsd.port.mk>
