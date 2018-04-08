# $FreeBSD$

PORTNAME=	spectacle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen capture program

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util

USES=		cmake:outsource gettext kde:5 pkgconfig tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons doctools ecm i18n jobwidgets kdeclarative kio \
		libkipi notifications package service widgetsaddons \
		windowsystem xmlgui
USE_QT5=	core concurrent dbus gui network printsupport qml quick \
		widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	x11 xcb xext xfixes

.include <bsd.port.mk>
