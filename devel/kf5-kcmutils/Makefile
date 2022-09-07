PORTNAME=	kcmutils
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 utilities for working with KCModules
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kcmutils/html/index.html

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons guiaddons i18n \
		itemviews kdeclarative package service \
		widgetsaddons xmlgui \
		ecm_build
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools_build qmake_build testlib_build

.include <bsd.port.mk>
