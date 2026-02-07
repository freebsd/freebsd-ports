PORTNAME=	kidletime
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Reporting of idle time of user and system
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	wayland-protocols>=1.27:graphics/wayland-protocols

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	ecm:build \
		plasma-wayland-protocols:build
USE_QT=		base wayland tools:build
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
