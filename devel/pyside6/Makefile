PORTNAME=	pyside6
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python Qt bindings for Qt 6
WWW=		https://wiki.qt.io/Qt_for_Python

LICENSE=	LGPL3

LIB_DEPENDS=	libshiboken6.abi${PYTHON_MAJOR_VER}.so:devel/shiboken6@${PY_FLAVOR} \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl llvm:lib python qt:6 tar:xz
USE_GL=		gl
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		3d base charts connectivity datavis3d declarative doc graphs \
		httpserver imageformats location multimedia networkauth pdf \
		positioning quick3d quicktimeline remoteobjects scxml sensors \
		serialbus serialport shadertools speech svg tools translations \
		wayland webchannel websockets

CMAKE_ARGS=	-DPYTHON_EXECUTABLE=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/pyside-setup-everywhere-src-${PYSIDE6_VERSION}/sources/pyside6
PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
CMAKE_ON+=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineCore \
		CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineQuick \
		CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineWidgets
PLIST_SUB+=	WEBENGINE="@comment "
.endif

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PySide6 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PySide6
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PySide6 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PySide6

.include <bsd.port.post.mk>
