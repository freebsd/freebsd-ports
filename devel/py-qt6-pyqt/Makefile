PORTNAME=	pyqt
PORTVERSION=	${PYQT_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtCore module
WWW=		https://riverbankcomputing.com/software/pyqt

PYQT_DIST=	yes

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libqscintilla2_qt6.so:devel/qscintilla2-qt6
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR}

USES=		gl pkgconfig python pyqt:6 qt:6
USE_GL+=	gl opengl
USE_LOCALE=	C.UTF-8
USE_PYTHON=	concurrent flavors
USE_PYQT=	pysip qtbuilder sip
USE_QT=		base connectivity declarative imageformats multimedia \
		pdf positioning quick3d remoteobjects sensors serialport \
		shadertools speech svg tools translations webchannel \
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
