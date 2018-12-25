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
		iconthemes jobwidgets kio package service widgetsaddons \
		windowsystem
USE_QT=		buildtools_build core dbus declarative gui network qmake_build \
		testlib widgets xml

.include <bsd.port.mk>
