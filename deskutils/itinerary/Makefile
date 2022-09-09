PORTNAME=	itinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Digital travel assistant for KDE
WWW=		https://apps.kde.org/en/itinerary

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 qt:5 \
		tar:xz xorg
USE_KDE=	calendarcore completion config contacts coreaddons crash \
		dbusaddons i18n jobwidgets kio kpkpass notifications kosm \
		kitinerary kpublictransport mime qqc2-desktop-style \
		service solid widgetsaddons windowsystem \
		ecm_build
USE_QT=		concurrent core dbus declarative gui location network quick3d \
		quickcontrols2 \
		testlib widgets \
		buildtools_build qmake_build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
