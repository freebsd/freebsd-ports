# $FreeBSD$

PORTNAME=	spectacle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen capture program

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		dbusaddons doctools ecm i18n jobwidgets kdeclarative kio \
		libkipi newstuff notifications package service widgetsaddons \
		windowsystem xmlgui
USE_QT=		core concurrent dbus declarative gui network printsupport \
		quickcontrols widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	x11 xcb xext xfixes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
