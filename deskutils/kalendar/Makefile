PORTNAME=	kalendar
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar application using Akonadi and QML for online calendars
WWW=		https://invent.kde.org/pim/kalendar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

BUILD_DEPENDS=	kirigami-addons>=0:x11-toolkits/kirigami-addons
RUN_DEPENDS=	kirigami-addons>=0:x11-toolkits/kirigami-addons

USES=		cmake compiler:c++17-lang desktop-file-utils grantlee:5 kde:5 \
		qt:5 tar:xz xorg
USE_QT=		concurrent core dbus declarative gui location multimedia \
		network printsupport quickcontrols2 svg widgets xml \
		buildtools:build declarative-test:build linguist:build \
		qmake:build testlib:build
USE_KDE=	akonadi akonadicalendar akonadicontacts auth calendarcore \
		calendarsupport calendarutils codecs config configwidgets \
		contacts coreaddons dbusaddons eventviews grantleetheme i18n \
		identitymanagement itemmodels kio kirigami2 mailcommon mime notifications \
		people pimtextedit qqc2-desktop-style service sonnet \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_XORG=	x11

.include <bsd.port.mk>
