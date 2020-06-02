# $FreeBSD$

PORTNAME=	python-poppler-qt5
DISTVERSIONPREFIX=	v
DISTVERSION=	0.75.0
PORTREVISION=	7
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Python bindings for the Poppler-Qt PDF rendering library

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang pkgconfig pyqt:5 python:3.4+ qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi
USE_PYQT=	gui xml sip_build
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS+=	--pyqt-sip-dir=${PYQT_SIPDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5.so

.include <bsd.port.mk>
