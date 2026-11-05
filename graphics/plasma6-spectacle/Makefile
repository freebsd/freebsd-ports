PORTNAME=	spectacle
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	graphics kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma screen capture program

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libtesseract.so:graphics/tesseract \
		libwayland-client.so:graphics/wayland \
		libKQuickImageEditor.so:graphics/kquickimageeditor

USES=		cmake compiler:c++20-lang gettext kde:6 localbase pkgconfig \
		qt:6 tar:xz xorg
USE_KDE=	config coreaddons crash dbusaddons globalaccel guiaddons i18n \
		kio kirigami2 notifications prison purpose \
		statusnotifieritem widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build plasma-wayland-protocols:build
# KDE Plasma
USE_KDE+=	kpipewire layer-shell-qt
USE_QT=		base declarative multimedia wayland
USE_XORG=	x11 xcb xfixes

.include <bsd.port.mk>
