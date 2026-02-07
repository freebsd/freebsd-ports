PORTNAME=	kservice
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 advanced plugin and service introspection

USES=		bison cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons dbusaddons i18n \
		doctools:build ecm:build
USE_QT=		core dbus xml \
		buildtools:build qmake:build

# Make the applications.menu file not conflict with KDE4.
CMAKE_ARGS=	-DAPPLICATIONS_MENU_NAME:STRING="kf5-applications.menu"

.include <bsd.port.mk>
