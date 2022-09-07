PORTNAME=	knewstuff
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for downloading application assets from the network
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/knewstuff/html/index.html

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	archive attica5 auth codecs completion config \
		configwidgets coreaddons i18n iconthemes itemviews \
		jobwidgets kio kirigami2 package service solid sonnet \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

.include <bsd.port.mk>
