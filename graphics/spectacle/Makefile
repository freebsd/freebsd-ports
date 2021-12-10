PORTNAME=	spectacle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen capture program

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libkImageAnnotator.so:graphics/kimageannotator
RUN_DEPENDS=	kipi-plugins>=0:graphics/kipi-plugins

USES=		cmake compiler:c++11-lang gettext kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		dbusaddons globalaccel i18n jobwidgets kdeclarative kio \
		libkipi newstuff notifications package service solid wayland \
		widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		core concurrent dbus declarative gui network printsupport \
		quickcontrols svg widgets x11extras xml \
		buildtools_build qmake_build testlib_build
USE_XORG=	x11 xcb xext xfixes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
