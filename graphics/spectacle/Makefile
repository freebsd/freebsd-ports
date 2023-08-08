PORTNAME=	spectacle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen capture program
WWW=		https://projects.kde.org/projects/kde/kdegraphics/spectacle

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libkImageAnnotator.so:graphics/kimageannotator
RUN_DEPENDS=	kipi-plugins>=0:graphics/kipi-plugins

USES=		cmake compiler:c++11-lang gettext kde:5 pkgconfig qt:5 tar:xz \
		xorg
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		dbusaddons globalaccel guiaddons i18n jobwidgets kdeclarative \
		kio libkipi newstuff notifications package purpose \
		service solid wayland widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus declarative gui network printsupport \
		quickcontrols svg widgets x11extras xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11 xcb xext xfixes

OPTIONS_DEFINE=			DOCS PIPEWIRE
OPTIONS_DEFAULT=		PIPEWIRE
PIPEWIRE_DESC=			Screen capture via PipeWire
PIPEWIRE_USE=			KDE=kpipewire
PIPEWIRE_CMAKE_BOOL_OFF=	DISABLE_PIPEWIRE
PIPEWIRE_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-pipewire-off

.include <bsd.port.mk>
