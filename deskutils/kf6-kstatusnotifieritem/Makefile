PORTNAME=	kstatusnotifieritem
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	deskutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Implementation of Status Notifier Items

USES=		cmake gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	windowsystem \
		ecm:build
USE_QT=		base
USE_XORG=	x11

CMAKE_OFF=	BUILD_PYTHON_BINDINGS

.include <bsd.port.mk>
