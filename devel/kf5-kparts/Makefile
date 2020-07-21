# $FreeBSD$

PORTNAME=	kparts
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 document centric plugin system

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n iconthemes jobwidgets kio notifications service \
		sonnet textwidgets widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
