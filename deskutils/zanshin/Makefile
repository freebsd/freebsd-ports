PORTNAME=	zanshin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Daily organizer for KDE
WWW=		https://zanshin.kde.org/

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++14-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	akonadi auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm guiaddons i18n iconthemes itemmodels \
		itemviews jobwidgets kdelibs4support kio notifications package \
		parts plasma-framework runner service solid sonnet textwidgets \
		unitconversion wallet widgetsaddons windowsystem xmlgui  \
# PIM Components
USE_KDE+=	akonadicalendar akonadicontacts akonadinotes akonadisearch \
		calendarcore contacts identitymanagement kontactinterface ldap \
		mime pimtextedit \
		kdepim-runtime5:run
USE_QT=		concurrent core dbus declarative gui network printsupport testlib \
		widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
