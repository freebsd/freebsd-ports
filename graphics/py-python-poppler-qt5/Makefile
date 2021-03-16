# $FreeBSD$

PORTNAME=	python-poppler-qt5
DISTVERSIONPREFIX=	v
DISTVERSION=	0.75.0
PORTREVISION=	16
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Python bindings for the Poppler-Qt PDF rendering library

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	qmake:devel/qt5-qmake
LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang pkgconfig pyqt:5 python:3.5+ qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi
USE_PYQT=	gui xml sip_build qtbuilder

do-build:
	(cd ${WRKSRC} ; sip-build  --verbose --no-make --build-dir build ; ${MAKE} -C ./build )

do-install:
	(cd ${WRKSRC} ; ${MAKE} -C ./build install INSTALL_ROOT=${STAGEDIR} )

post-install:
	${RLN} ${STAGEDIR}${PYTHON_SITELIBDIR}/popplerqt5.cpython-${PYTHON_SUFFIX}m.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/popplerqt5.cpython-${PYTHON_SUFFIX}m.so

.include <bsd.port.mk>
