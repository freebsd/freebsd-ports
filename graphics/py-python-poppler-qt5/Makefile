# $FreeBSD$

PORTNAME=	python-poppler-qt5
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24.2
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Python bindings for the Poppler-Qt PDF rendering library

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang pkgconfig pyqt:5 python:3.4+ qmake qt:5
USE_PYQT=	gui xml sip_build
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	wbsoft

PYDISTUTILS_BUILD_TARGET=	build_ext
PYDISTUTILS_BUILDARGS+=		--pyqt-sip-dir=${PYQT_SIPDIR}

.include <bsd.port.mk>
