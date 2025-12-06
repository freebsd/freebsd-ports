PORTNAME=	python-poppler-qt5
DISTVERSIONPREFIX=	v
DISTVERSION=	21.3.0
PORTREVISION=	5
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Python bindings for the Poppler-Qt PDF rendering library
WWW=		https://pypi.org/project/python-poppler-qt5/

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PY_SETUPTOOLS}
LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++17-lang gl pkgconfig pyqt:5 python qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi
USE_GL=		gl
USE_PYQT=	pyqt5 qtbuilder:build
USE_PYTHON=	autoplist pep517
USE_QT=		core gui xml qmake:build

PEP517_BUILD_CONFIG_SETTING=	-C--build-dir=build \
				-C--jobs=${MAKE_JOBS_NUMBER} -C--qmake=${QMAKE} \
				-C--qmake-setting='CONFIG += c++17' \
				-C--qmake-setting='QMAKE_CXXFLAGS += ${CXXFLAGS}' \
				-C--qmake-setting='QMAKE_LFLAGS += ${LDFLAGS}' \
				-C--verbose

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5${PYTHON_TAG}.so

.include <bsd.port.mk>
