PORTNAME=	kalendar
DISTVERSION=	1.0.0
CATEGORIES=	deskutils
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar application using Akonadi and QML for online calendars

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

USES=		cmake compiler:c++17-lang desktop-file-utils grantlee:5 kde:5 \
		qt:5 tar:xz xorg
USE_QT=		concurrent core dbus declarative gui location multimedia \
		network printsupport quickcontrols2 svg widgets xml \
		buildtools_build linguist_build qmake_build
USE_KDE=	akonadi akonadicalendar akonadicontacts auth calendarcore \
		calendarsupport calendarutils codecs config configwidgets \
		contacts coreaddons dbusaddons eventviews grantleetheme i18n \
		identitymanagement itemmodels kio kirigami2 mime notifications \
		people pimtextedit service sonnet textwidgets widgetsaddons \
		windowsystem xmlgui \
		ecm_build
USE_XORG=	x11

.include <bsd.port.mk>
