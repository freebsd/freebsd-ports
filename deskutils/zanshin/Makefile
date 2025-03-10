PORTNAME=	zanshin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Daily organizer for KDE
WWW=		https://zanshin.kde.org/

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++14-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	akonadi auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemmodels \
		itemviews jobwidgets kio libplasma notifications package parts \
		service solid sonnet textwidgets unitconversion wallet \
		widgetsaddons windowsystem xmlgui \
		ecm:build
# PIM Copmonents
USE_KDE+=	akonadicalendar akonadicontacts akonadisearch \
		calendarcore contacts identitymanagement kontactinterface ldap \
		mime pimtextedit \
		kdepim-runtime:run
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
