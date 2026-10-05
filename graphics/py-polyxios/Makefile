PORTNAME=	polyxios
DISTVERSION=	0.4.1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast 3D file format I/O and processing library
WWW=		https://github.com/fury-gl/polyxios

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=3.0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meson-python>=0.15:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ninja>=0:devel/py-ninja@${PY_FLAVOR} \
		ninja:devel/ninja
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.24:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

post-patch:
	@${REINPLACE_CMD} -e '1s|#!/usr/bin/env python3|#!${PYTHON_CMD}|' ${WRKSRC}/tools/gitversion.py

# tests as of 0.4.1: 2527 passed, 58 skipped, 3 xfailed

.include <bsd.port.mk>
