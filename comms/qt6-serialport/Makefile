PORTNAME=	serialport
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	comms
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt functions to access serial ports

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>0:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.3:misc/py-spdx-tools@${PY_FLAVOR} \
		vulkan-headers>=1.4:graphics/vulkan-headers
LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang pkgconfig python:build qt-dist:6
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base

.include <bsd.port.mk>
