PORTNAME=	itinerary
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Digital travel assistant for KDE
WWW=		https://apps.kde.org/en/itinerary

BUILD_DEPENDS=	libquotient>=0.9.0:net-im/libquotient
LIB_DEPENDS=	libKOSM.so:astro/kosmindoormap \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++20-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	calendarcore completion config contacts coreaddons crash \
		dbusaddons filemetadata holidays i18n jobwidgets kio \
		kirigami-addons kitinerary kpublictransport mime notifications \
		qqc2-desktop-style service solid unitconversion widgetsaddons \
		windowsystem \
		ecm:build \
		itemmodels:run prison:run
USE_QT=		base positioning \
		location:run multimedia:run
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
