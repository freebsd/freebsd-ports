PORTNAME=	kdbusaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Convenience classes for D-Bus

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	ecm:build
USE_QT=		base \
		tools:build

.include <bsd.port.mk>
