PORTNAME=	spectacle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-applications kde-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen capture program
WWW=		https://projects.kde.org/projects/kde/kdegraphics/spectacle

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon \
		libwayland-server.so:graphics/wayland

USES=		cmake compiler:c++11-lang gettext gl kde:6 pkgconfig qt:6 tar:xz \
		xorg
USE_GL=		gl opengl
USE_KDE=	attica auth codecs colorscheme completion config configwidgets coreaddons \
		dbusaddons globalaccel guiaddons i18n jobwidgets kdeclarative \
		kio kirigami2 layer-shell-qt newstuff notifications package purpose \
		service solid wayland widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build plasma-wayland-protocols:build
USE_QT=		base declarative multimedia wayland
USE_XORG=	x11 xcb xext xfixes

OPTIONS_DEFINE=			DOCS PIPEWIRE
OPTIONS_DEFAULT=		PIPEWIRE
PIPEWIRE_DESC=			Screen capture via PipeWire
PIPEWIRE_USE=			KDE=kpipewire
PIPEWIRE_CMAKE_BOOL_OFF=	DISABLE_PIPEWIRE
PIPEWIRE_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-pipewire-off

.include <bsd.port.mk>
