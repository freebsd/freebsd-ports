PORTNAME=	pyside6
DISTVERSION=	${PYSIDE6_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken6/PySide6-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-everywhere-src-${DISTVERSION}

PATCH_SITES=	https://github.com/qtproject/pyside-pyside-setup/commit/
PATCHFILES+=	4a3fe49a0976f19ca03c869caded8cde8ac60315.patch:-p3 # Fix build with Qt 6.5.3

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
USE_QT=		3d base charts connectivity datavis3d declarative doc httpserver \
		imageformats location multimedia networkauth positioning \
		quick3d quicktimeline remoteobjects scxml sensors serialbus \
		serialport shadertools speech svg tools translations wayland \
		webchannel websockets

CMAKE_ARGS=	-DPYTHON_EXECUTABLE=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/pyside-setup-everywhere-src-${PYSIDE6_VERSION}/sources/pyside6
PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
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
