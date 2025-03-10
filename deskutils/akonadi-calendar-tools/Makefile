PORTNAME=	akonadi-calendar-tools
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CLI tools to manage akonadi calendars
WWW=		https://www.kde.org/

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++11-lib gettext kde:6 qt:6 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemmodels \
		itemviews jobwidgets kio notifications parts service solid \
		sonnet textwidgets unitconversion widgetsaddons windowsystem \
		xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicalendar calendarcore calendarsupport \
		calendarutils identitymanagement libkdepim mime pimtextedit
USE_QT=		base
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
