PORTNAME=	kidletime
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Reporting of idle time of user and system

BUILD_DEPENDS=	wayland-protocols>=1.27:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		cmake gl kde:6 pkgconfig qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	ecm:build plasma-wayland-protocols:build
USE_QT=		base
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
