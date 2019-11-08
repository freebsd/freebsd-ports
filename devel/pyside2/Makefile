# $FreeBSD$

PORTNAME=	pyside2
DISTVERSION=	5.13.2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken2/PySide2-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Python Qt bindings for Qt 5.12+

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		git>0:devel/git
LIB_DEPENDS=	# more later

USES=		cmake gl python qt:5 tar:xz
USE_GL=		gl
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		3d buildtools_build charts core datavis3d declarative \
		designer gui help location multimedia network opengl \
		printsupport qmake_build script scripttools scxml sensors \
		speech sql svg testlib uitools webchannel webengine \
		websockets widgets x11extras xml xmlpatterns

CMAKE_ARGS+=	"-DUSE_PYTHON_VERSION=${PYTHON_VER}" \
		"-DPYTHON_EXECUTABLE=${PYTHON_CMD}"

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} >= 3
LIB_DEPENDS+=	libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR}
PLIST_SUB+=	PYVERSTR=.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}
.else
LIB_DEPENDS+=	libshiboken2-${PYTHON_VERSION}.so:devel/shiboken2@${PY_FLAVOR}
PLIST_SUB+=	PYVERSTR=-${PYTHON_VERSION}
.endif

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION}/sources/pyside2

post-stage:
	@${RM} -r ${STAGEDIR}/${PYTHON_SITELIBDIR}/CMakeFiles \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/tests \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/CMakeFiles \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/Qt3DAnimation \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/Qt3DCore \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/Qt3DExtras \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/Qt3DInput \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/Qt3DLogic \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/Qt3DRender \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtCharts \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtConcurrent \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtCore \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtDataVisualization \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtGui \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtHelp \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtLocation \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtMultimedia \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtMultimediaWidgets \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtNetwork \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtOpenGL \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtPositioning \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtPrintSupport \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtQml \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtQuick \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtQuickWidgets \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtScript \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtScriptTools \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtScxml \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtSensors \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtSql \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtSvg \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtTest \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtTextToSpeech \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtUiTools \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtWebChannel \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtWebEngine \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtWebEngineCore \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtWebEngineWidgets \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtWebSockets \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtWidgets \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtX11Extras \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtXml \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/QtXmlPatterns \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/PySide2/support \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/libpyside \
		${STAGEDIR}/${PYTHON_SITELIBDIR}/plugins

.include <bsd.port.post.mk>
