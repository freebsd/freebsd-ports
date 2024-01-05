PORTNAME=	python-poppler-qt5
DISTVERSIONPREFIX=	v
DISTVERSION=	21.3.0
PORTREVISION=	1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Python bindings for the Poppler-Qt PDF rendering library
WWW=		https://pypi.org/project/python-poppler-qt5/

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	qmake-qt5:devel/qt5-qmake
LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang gl pkgconfig pyqt:5 python qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi
USE_GL=		gl
USE_PYQT=	pyqt5 sip:build
USE_PYTHON=	flavors pep517
USE_QT=		core gui xml

PLIST_SUB=	_PY_SONAME=${_PY_SONAME}

_PY_SONAME=	${PYTHON_EXT_SUFFIX}

BINARY_ALIAS=	qmake=${QMAKE}

do-build:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${SIP} ${SIP_ARGS} ; ${SETENV} ${MAKE_ENV} ${MAKE} -C ./build )

do-install:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} -C ./build install INSTALL_ROOT=${STAGEDIR} )

post-install:
	${RLN} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5${_PY_SONAME}.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5${_PY_SONAME}.so

.include <bsd.port.mk>
