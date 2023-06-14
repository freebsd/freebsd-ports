PORTNAME=	pyqt
PORTVERSION=	${PYQT_VERSION}
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtCore module
WWW=		https://riverbankcomputing.com/software/pyqt

PYQT_DIST=	yes

LIB_DEPENDS=	libqscintilla2_qt6.so:devel/qscintilla2-qt6 \
		libdbus-1.so:devel/dbus
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR}

USES=		gl pkgconfig python pyqt:6 qt:6
USE_GL+=	gl opengl
USE_PYTHON=	concurrent flavors py3kplist
USE_PYQT=	qtbuilder sip pysip
USE_QT=		5compat base declarative imageformats languageserver lottie \
		multimedia positioning quick3d remoteobjects sensors \
		serialport shadertools svg tools translations webchannel \
		websockets

PORTSCOUT?=	limit:^${_QT_VERSION:R}

post-extract:
	${RM} -r ${WRKSRC}/pyuic/uic/port_v2

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
