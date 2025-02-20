PORTNAME=	spectacle
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	graphics kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma screen capture program

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libopencv_core.so:graphics/opencv \
		libwayland-client.so:graphics/wayland

USES=		cmake compiler:c++20-lang gettext kde:6 localbase pkgconfig \
		qt:6 tar:xz xorg
USE_KDE=	config coreaddons crash dbusaddons globalaccel guiaddons i18n \
		kio kirigami2 kpipewire layer-shell-qt notifications prison \
		purpose statusnotifieritem widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build plasma-wayland-protocols:build
USE_QT=		base declarative multimedia wayland
USE_XORG=	x11 xcb xfixes

OPTIONS_DEFINE=		WAYLAND
OPTIONS_DEFAULT=	WAYLAND
WAYLAND_USE=		KDE=kpipewire
WAYLAND_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-pipewire-off

.include <bsd.port.mk>
