# $FreeBSD$

PORTNAME=	core
CATEGORIES=	devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtCore module

PYQT_MODULE=	QtCore
CONFIGURE_ARGS=	${PYQT5_MODULES_ALL:N${PYQT_MODULE}:C/.*/--disable=&/} \
		--enable=${PYQT_MODULE}

PYQT_DIST=	yes

USES=		python:3.5+ pyqt:5 qt:5
USE_PYTHON=	concurrent flavors py3kplist
USE_PYQT=	sip pysip
USE_QT=		core buildtools_build qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtCore API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.pre.mk>

PLIST_SUB+=	PYTHON_MAJOR_VER="${PYTHON_MAJOR_VER}"
post-patch:
	${RM} -r ${WRKSRC}/pyuic/uic/port_v2

post-install:
	${INSTALL_DATA} ${FILESDIR}/Qt.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5
	# This Qt.so masks the Qt.py which is supposed to import
	# all of the Qt submodules.
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5/Qt.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5/QtCore.so

.include <bsd.port.post.mk>
