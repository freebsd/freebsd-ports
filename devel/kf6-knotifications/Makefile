PORTNAME=	knotifications
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform library for creating popup notifications

LIB_DEPENDS=	libcanberra.so:audio/libcanberra

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	config \
		ecm:build
USE_QT=		base declarative

# Requires PySide and Shiboken.
CMAKE_OFF=	BUILD_PYTHON_BINDINGS

.include <bsd.port.mk>
