PORTNAME=	python-poppler-qt5
DISTVERSIONPREFIX=	v
DISTVERSION=	0.75.0
PORTREVISION=	23
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Python bindings for the Poppler-Qt PDF rendering library

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	qmake-qt5:devel/qt5-qmake
LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang gl pkgconfig pyqt:5 python:3.7-3.9 qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi
USE_GL=		gl
USE_PYQT=	gui qtbuilder xml sip_build
USE_QT=		core gui xml

PLIST_SUB=	_PY_SONAME=${_PY_SONAME}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
_PY_SONAME=	.cpython-${PYTHON_SUFFIX}m
.else
_PY_SONAME=	${PYTHON_EXT_SUFFIX}
.endif

do-build:
	(cd ${WRKSRC} ; sip-build-${PYTHON_VER} --qmake ${QMAKE} --verbose --no-make --build-dir build ; ${MAKE} -C ./build )

do-install:
	(cd ${WRKSRC} ; ${MAKE} -C ./build install INSTALL_ROOT=${STAGEDIR} )

post-install:
	${RLN} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5${_PY_SONAME}.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/popplerqt5${_PY_SONAME}.so

.include <bsd.port.post.mk>
