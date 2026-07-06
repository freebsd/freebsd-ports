PORTNAME=	tesserocr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Pillow-friendly, Python wrapper around tesseract-ocr API using Cython
WWW=		https://github.com/sirfz/tesserocr

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}
LIB_DEPENDS=	libtesseract.so:graphics/tesseract \
		libleptonica.so:graphics/leptonica
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cysignals>0:devel/py-cysignals@${PY_FLAVOR}

USES=		compiler:c++17-lang pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	sirfz
USE_PYTHON=	cython pep517

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
