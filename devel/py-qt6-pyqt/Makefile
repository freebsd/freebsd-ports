PORTNAME=	pyqt
DISTVERSION=	${PYQT_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQT_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit
WWW=		https://riverbankcomputing.com/software/pyqt

LICENSE=	${PYQT6_LICENSE}

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>1:devel/py-dbus@${PY_FLAVOR}

USES=		gl pkgconfig pyqt:6,dist python qt:6
USE_GL=		opengl
USE_PYQT=	pysip qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		base connectivity declarative imageformats multimedia \
		positioning quick3d remoteobjects scxml sensors serialport \
		shadertools speech svg tools translations webchannel \
		websockets

PORTSCOUT=	limit:^${_QT_VERSION:R}

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv7 || ${ARCH} == i386
USE_QT+=	pdf
PLIST_SUB+=	PDF=""
.else
SIP_ARGS+=	--disable QtPdf --disable QtPdfWidgets
PLIST_SUB+=	PDF="@comment "
.endif

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

.include <bsd.port.post.mk>
