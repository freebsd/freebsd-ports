PORTNAME=	pyside6
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python Qt bindings for Qt 6
WWW:		https://wiki.qt.io/Qt_for_Python

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		git>0:devel/git \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libLLVM.so:devel/llvm${LLVM_DEFAULT} \
		libshiboken6.abi${PYTHON_MAJOR_VER}.so:devel/shiboken6@${PY_FLAVOR}

USES=		cmake gl python:3.5+ qt:6 tar:xz
USE_GL=		gl
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		3d 5compat base declarative doc imageformats positioning \
		quick3d quicktimeline networkauth serialport shadertools \
		svg tools translations wayland webchannel websockets

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHON_CMD}


.include <bsd.port.pre.mk>

PLIST_SUB+=	PYVERSTR=.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}
PLIST_SUB+=	DISTVERSION=${DISTVERSION}

WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION}/sources/pyside6

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB+=	WEBENGINE="@comment "
.endif

.include <bsd.port.post.mk>
