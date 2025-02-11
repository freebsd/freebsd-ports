PORTNAME=	spectacle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen capture program
WWW=		https://projects.kde.org/projects/kde/kdegraphics/spectacle

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libkImageAnnotator-Qt6.so:graphics/kimageannotator@qt6 \
		libZXing.so:textproc/zxing-cpp \
		libopencv_core.so:graphics/opencv

USES=		cmake compiler:c++11-lang gettext kde:6 pkgconfig qt:6 tar:xz \
		xorg
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		dbusaddons globalaccel guiaddons i18n jobwidgets kdeclarative \
		kio layer-shell-qt newstuff notifications package prison \
		purpose service solid statusnotifieritem wayland \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build plasma-wayland-protocols:build
USE_QT=		base multimedia
USE_XORG=	x11 xcb xext xfixes

OPTIONS_DEFINE=			DOCS PIPEWIRE
OPTIONS_DEFAULT=		PIPEWIRE
PIPEWIRE_DESC=			Screen capture via PipeWire (required for Wayland)
PIPEWIRE_USE=			KDE=kpipewire
PIPEWIRE_CMAKE_BOOL_OFF=	DISABLE_PIPEWIRE
PIPEWIRE_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-pipewire-off

.include <bsd.port.mk>
