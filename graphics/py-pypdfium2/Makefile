PORTNAME=	pypdfium2
PORTVERSION=	5.13.0
CATEGORIES=	graphics python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to the PDFium PDF rendering library
WWW=		https://github.com/pypdfium2-team/pypdfium2

LICENSE=	APACHE20 BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=		${WRKSRC}/LICENSES/Apache-2.0.txt
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_MIT=		${WRKSRC}/LICENSES/MIT.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	pdfium>=${PDFIUM_VER}:graphics/pdfium
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest
USE_GITHUB=	yes
GH_ACCOUNT=	pypdfium2-team

# pdfium version provided by graphics/pdfium
PDFIUM_VER=		8066
PDFIUM_FULL_VER=	156.0.8066.0
PDFIUM_LIB=	${LOCALBASE}/lib/libpdfium.so

# Use pre-generated reference bindings (bundled in the source tree) to avoid
# network access during the build phase.  Provide the full pdfium version so
# PdfiumVer.to_full() does not do a git ls-remote to chromium.googlesource.com.
# Point PDFIUM_BINARY to the graphics/pdfium shared library because
# ctypes.util.find_library() does not locate unversioned .so files on FreeBSD.
MAKE_ENV=	PDFIUM_BINDINGS=reference \
		PDFIUM_PLATFORM=system-search:${PDFIUM_VER} \
		PDFIUM_BINARY=${PDFIUM_LIB} \
		GIVEN_FULLVER=${PDFIUM_FULL_VER}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

# tests as of 5.13.0: 175 passed, 3 skipped in 0.58s

.include <bsd.port.mk>
