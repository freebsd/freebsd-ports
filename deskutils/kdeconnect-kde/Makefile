PORTNAME=	kdeconnect-kde
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	3
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for KDE to interface between your phone and your computer
WWW=		https://community.kde.org/KDEConnect

LICENSE=	GPLv2

LIB_DEPENDS=	libfakekey.so:x11/libfakekey \
		libwayland-client.so:graphics/wayland \
		libKF5PulseAudioQt.so:audio/pulseaudio-qt@qt5
BUILD_DEPENDS=	kpeoplevcard>0:net/kpeoplevcard \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		wayland-protocols>=0:graphics/wayland-protocols \
		kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons
RUN_DEPENDS=	sshpass:security/sshpass \
		sshfs:sysutils/fusefs-sshfs \
		kpeoplevcard>0:net/kpeoplevcard \
		kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		pkgconfig qca qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons doctools guiaddons i18n iconthemes \
		itemviews jobwidgets kcmutils kio kirigami2 notifications \
		people qqc2-desktop-style service solid wayland widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui multimedia network \
		quickcontrols2 testlib wayland widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext xtst
USE_LDCONFIG=	${QT_QMLDIR}/org/kde/kdeconnect

OPTIONS_DEFINE=	DOCS

KDE_APPLICATIONS_SHLIB_VER=${KDE_APPLICATIONS_VERSION}

.include <bsd.port.mk>
