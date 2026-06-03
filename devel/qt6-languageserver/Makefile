PORTNAME=	languageserver
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 implementation of the Language Server Protocol

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>0:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.3:misc/py-spdx-tools@${PY_FLAVOR} \
		vulkan-headers>=1.4:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang pkgconfig python:build qt-dist:6
USE_QT=		base:build # libs are statically linked

.include <bsd.port.mk>
