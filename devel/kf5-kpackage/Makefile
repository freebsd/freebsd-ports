PORTNAME=	kpackage
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to load and install packages
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kpackage/html/index.html

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive config coreaddons i18n \
		doctools_build ecm_build
USE_QT=		core dbus xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
