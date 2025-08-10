PORTNAME=	pyside6
DISTVERSION=	${PYSIDE6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/${PORTNAME}/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}
DIST_SUBDIR=	KDE/Qt/${PYSIDE6_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python Qt bindings for Qt 6
WWW=		https://wiki.qt.io/Qt_for_Python

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libshiboken6.abi${PYTHON_MAJOR_VER}.so:devel/shiboken6@${PY_FLAVOR} \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl llvm:lib,min=17,noexport python qt:6 tar:xz
USE_GL=		opengl
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		3d base charts connectivity datavis3d declarative doc graphs \
		httpserver imageformats location multimedia networkauth \
		positioning quick3d quicktimeline remoteobjects scxml sensors \
		serialbus serialport shadertools speech svg tools translations \
		webchannel websockets

CONFIGURE_ENV=	LLVM_INSTALL_DIR="${LLVM_PREFIX}/lib/cmake/llvm"

PATCH_WRKSRC=	${WRKSRC:H:H}
WRKSRC_SUBDIR=	sources/pyside6
PLIST_SUB=	PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER} \
		SHLIB_VER=${DISTVERSION:R} \
		SHLIB_VERSION=${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	PDF="" \
		WEBENGINE="" \
		WEBVIEW=""
USE_QT+=	pdf webengine webview
.else
CMAKE_ON+=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineCore \
		CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineQuick \
		CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineWidgets \
		CMAKE_DISABLE_FIND_PACKAGE_Qt6WebView
PLIST_SUB+=	PDF="@comment " \
		WEBENGINE="@comment " \
		WEBVIEW="@comment "
.endif

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PySide6 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PySide6
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PySide6 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PySide6

.include <bsd.port.post.mk>
