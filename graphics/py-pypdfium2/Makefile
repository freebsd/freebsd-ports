PORTNAME=	pypdfium2
PORTVERSION=	5.7.1
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

BUILD_DEPENDS=	${LO_PDFIUM}:editors/libreoffice \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${LO_PDFIUM}:editors/libreoffice

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pypdfium2-team

# pdfium version bundled with LibreOffice (editors/libreoffice)
PDFIUM_VER=		7471
PDFIUM_FULL_VER=	143.0.7471.0
LO_PDFIUM=		${LOCALBASE}/lib/libreoffice/program/libpdfiumlo.so

# Use pre-generated reference bindings (bundled in the source tree) to avoid
# network access during the build phase.  Provide the full pdfium version so
# PdfiumVer.to_full() does not do a git ls-remote to chromium.googlesource.com.
MAKE_ENV=	PDFIUM_BINDINGS=reference \
		PDFIUM_PLATFORM=system-search:${PDFIUM_VER} \
		GIVEN_FULLVER=${PDFIUM_FULL_VER}

# tests as of 5.7.1: 8 failed, 160 passed, 3 skipped, 3 warnings in 5.73s (failures are possibly due to the custom ctypesgen commented out)

.include <bsd.port.mk>
