PORTNAME=	kdeclarative
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
POPRTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing integration of QML and KDE Frameworks
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kdeclarative/html/index.html

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	completion config coreaddons globalaccel guiaddons i18n \
		iconthemes jobwidgets kio notifications package service \
		solid widgetsaddons windowsystem \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools_build qmake_build testlib_build
USE_XORG=	x11

.include <bsd.port.mk>
