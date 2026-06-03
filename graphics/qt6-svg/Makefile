PORTNAME=	svg
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt6 classes for displaying the contents of SVG files

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>0:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.3:misc/py-spdx-tools@${PY_FLAVOR} \
		vulkan-headers>=1.4:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl python:build qt-dist:6
USE_GL=		opengl
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base

.include <bsd.port.mk>
