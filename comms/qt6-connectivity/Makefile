PORTNAME=	connectivity
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	comms
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt connectivity (Bluetooth/NFC) module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>0:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.3:misc/py-spdx-tools@${PY_FLAVOR} \
		vulkan-headers>=1.4:graphics/vulkan-headers
LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		cmake compiler:c++11-lang pkgconfig python:build qt-dist:6,connectivity
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base

.include <bsd.port.mk>
