PORTNAME=	kalendar
DISTVERSION=	0.2.1
CATEGORIES=	deskutils
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar application using Akonadi and QML for online calendars

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

USES=		cmake compiler:c++17-lang desktop-file-utils \
		kde:5 xorg qt:5 tar:xz
USE_QT=		concurrent core dbus declarative gui location multimedia network \
		printsupport quickcontrols2 svg widgets xml \
		buildtools_build linguist_build qmake_build
USE_KDE=	akonadi akonadicalendar akonadicontacts auth calendarcore calendarsupport calendarutils config contacts codecs configwidgets coreaddons dbusaddons eventviews grantleetheme i18n identitymanagement itemmodels kirigami2 mime people pimtextedit sonnet textwidgets widgetsaddons xmlgui windowsystem
USE_XORG=	x11

.include <bsd.port.mk>
