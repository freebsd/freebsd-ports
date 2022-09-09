PORTNAME=	kparts
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 document centric plugin system
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kparts/html/index.html

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n iconthemes jobwidgets kio notifications service \
		solid sonnet textwidgets widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

.include <bsd.port.mk>
