# $FreeBSD$

PORTNAME=	kdeclarative
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing integration of QML and KDE Frameworks

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz
USE_KDE=	completion config coreaddons globalaccel guiaddons i18n \
		iconthemes jobwidgets kio notifications package service widgetsaddons \
		windowsystem
USE_QT=		concurrent core dbus declarative gui network testlib widgets \
		xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
