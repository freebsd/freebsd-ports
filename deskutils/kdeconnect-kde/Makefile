PORTNAME=	kdeconnect-kde
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for KDE to interface between your phone and your computer
WWW=		https://community.kde.org/KDEConnect

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libfakekey.so:x11/libfakekey \
		libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libKF6PulseAudioQt.so:audio/pulseaudio-qt
BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		wayland-protocols>=0:graphics/wayland-protocols
RUN_DEPENDS=	sshpass:security/sshpass \
		sshfs:filesystems/sshfs

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools \
		gl kde:6 localbase:ldflags pkgconfig qt:6 ssl tar:xz xorg
USE_GL=		gl opengl # GLX
USE_KDE=	bookmarks colorscheme completion config configwidgets \
		coreaddons crash dbusaddons doctools guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kio kirigami-addons \
		kirigami2 notifications package people qqc2-desktop-style \
		service solid statusnotifieritem widgetsaddons windowsystem \
		ecm:build
USE_QT=		base connectivity declarative multimedia wayland
USE_XORG=	ice sm x11 xext xtst
USE_LDCONFIG=	${QT_QMLDIR}/org/kde/kdeconnect

OPTIONS_DEFINE=	DOCS

KDE_APPLICATIONS_SHLIB_VER=${KDE_APPLICATIONS_VERSION}

.include <bsd.port.mk>
